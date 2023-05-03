#include "GglAudioPlayTask.h"
#include"GglAudioPlayer.h"
namespace mystd {
using namespace std;
GglAudioPlayTask::GglAudioPlayTask(
    GglSwResample& gglResample, GglFrameVector& fVector,
    GglAVFrameQueue& frameQueue ,GglVideoPlayTask& vTask)
    : gglResample(gglResample), fVector(fVector), frameQueue(frameQueue),vTask(vTask) {
  this->stopFlag = false;
}
GglAudioPlayTask ::~GglAudioPlayTask() {
  stopFlag = true;
  loadThreadPtr->join();
  playThreadPtr->join();
  
}
void GglAudioPlayTask ::runPlayTask(GglAudioPlayer* player) {
  loadThreadPtr = new thread(&GglAudioPlayTask::loadTask, this);
  playThreadPtr = new thread(&GglAudioPlayTask::playTask, this,player);
}
AVFrame* GglAudioPlayTask ::getCurrentFramePtr() {return currentFramePtr;}

void GglAudioPlayTask ::playTask(GglAudioPlayer* player) {
  auto& rawV = fVector.getVector();
  for (; rawV.size() == 0;) {
    this_thread::sleep_for(chrono::milliseconds(10));
  }
  currentIndex = 0;
  currentFramePtr = rawV[currentIndex];
  for (; !stopFlag;) {
    this_thread::sleep_for(chrono::milliseconds(20));
    if(stopFlag){
        break;
    }
    if(lastVideoFramePtr==vTask.getCurrentFramePtr()){
        continue;
    }
    if (currentIndex == rawV.size()-1) {
        continue;
    }
    int32_t comRe = av_compare_ts(
        currentFramePtr->pts, currentFramePtr->time_base,
        vTask.getCurrentFramePtr()->pts, vTask.getCurrentFramePtr()->time_base);
    if(0==comRe){
       player->playAudioFrame();
       lastVideoFramePtr=vTask.getCurrentFramePtr();
      ++currentIndex;
      currentFramePtr = rawV[currentIndex];
      continue;
    }
    if(-1==comRe){
      player->playAudioFrame();
      lastVideoFramePtr = vTask.getCurrentFramePtr();
      ++currentIndex;
      currentFramePtr = rawV[currentIndex];
      continue;
    }
    
  }
}
void GglAudioPlayTask ::loadTask() {
    for(;!stopFlag;){
        this_thread::sleep_for(chrono::milliseconds(20));
    if (frameQueue.size() > 0) {
      AVFrame* destFramePtr = av_frame_alloc();
      destFramePtr->ch_layout = frameQueue.front()->ch_layout;
      destFramePtr->nb_samples = frameQueue.front()->nb_samples;
      destFramePtr->format = AV_SAMPLE_FMT_FLT;
      destFramePtr->sample_rate = frameQueue.front()->sample_rate;
      int32_t res= av_frame_get_buffer(destFramePtr, 0);
      if (res != 0) {
        av_strerror(res, errBuffer, 1024);
        throw runtime_error(errBuffer);
        return;
      }
      gglResample.resampleAndLoadPCMData(destFramePtr);
      fVector.getVector().push_back(destFramePtr);
    }
    }
}
}  // namespace mystd