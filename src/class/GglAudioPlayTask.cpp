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
      this_thread::sleep_for(chrono::milliseconds(1));

      // if (lastVideoFramePtr == vTask.getCurrentFramePtr()) {
      //   continue;
      // }
      
      if (cacheFrameQueue.size() < 1) {
        //   this_thread::sleep_for(chrono::milliseconds(20));
        continue;
      }
      player->pauseIfBufferNotReady();
      vTask.drawMtx.lock();
      lastVideoFramePtr = vTask.getCurrentFramePtr();
      int64_t comRe = -1;
      for (; comRe <= 0 && !stopFlag;) {
        
        if(currentFramePtr==nullptr){
        AVFrame* destFramePtr = av_frame_alloc();
        gglResample.resampleAndLoadPCMData(destFramePtr);
        currentFramePtr = destFramePtr;
        
      }
      comRe = (currentFramePtr->pts - lastVideoFramePtr->pts) / 1000;
      cout << "lastVideoFramePtr pts==" << lastVideoFramePtr->pts
           << "audioFramePtr pts==" << currentFramePtr->pts << endl;
      cout << "comRe==" << comRe << endl;
    
        if (-40 <comRe&&40>comRe) {
          // cout<<"comRe=="<<comRe<<endl;
          player->playAudioFrame();

          av_frame_free(&currentFramePtr);
          continue;
        }
        if (comRe > 0) {
          continue;
        }
        if (0 > comRe) {
          av_frame_free(&currentFramePtr);
        }
      }

      vTask.drawMtx.unlock();
    

    }
}

}  // namespace mystd