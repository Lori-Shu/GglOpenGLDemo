#include "GglAudioPlayTask.h"
#include"GglAudioPlayer.h"
namespace mystd {
using namespace std;
GglAudioPlayTask::GglAudioPlayTask(
    GglSwResample& gglResample,
    GglAVFrameQueue& cacheFrameQueue ,GglVideoPlayTask& vTask)
    : gglResample(gglResample), cacheFrameQueue(cacheFrameQueue),vTask(vTask) {
  this->stopFlag = false;
  currentFramePtr=nullptr;
}
GglAudioPlayTask ::~GglAudioPlayTask() {
  stopFlag = true;
  playThreadPtr->join();
  
}
void GglAudioPlayTask ::runPlayTask(GglAudioPlayer* player) {
  playThreadPtr = new thread(&GglAudioPlayTask::playTask, this,player);
}
AVFrame* GglAudioPlayTask ::getCurrentFramePtr() {return currentFramePtr;}
bool GglAudioPlayTask ::getStopFlag() {return stopFlag;}
void GglAudioPlayTask ::playTask(GglAudioPlayer* player) {
    for (; !stopFlag;) {
      

      // if (lastVideoFramePtr == vTask.getCurrentFramePtr()) {
      //   continue;
      // }
      if (cacheFrameQueue.size() < 1) {
        this_thread::sleep_for(chrono::milliseconds(1));
        //   this_thread::sleep_for(chrono::milliseconds(20));
        continue;
      }
        
        AVFrame* destFramePtr = av_frame_alloc();
        gglResample.resampleAndLoadPCMData(destFramePtr);
        currentFramePtr = destFramePtr;

          player->playAudioFrame();

          av_frame_free(&currentFramePtr);
      }

}

}  // namespace mystd