#include"GglVideoPlayTask.h"

namespace mystd{
    using namespace std;
    GglVideoPlayTask::GglVideoPlayTask(
        GglSwScale& gglScale,
        std::chrono::duration<int32_t, std::milli>& timePerFrame,GglAVFrameQueue* frameQueuePtr)
        : gglScale(gglScale) {
      this->stopFlag = false;
      this->timePerFramePtr=&timePerFrame;
      this->playPortWidth=1280;
      this->playPortHeight = 720;
      this->shouldDrawVideoTex=false;
      cacheFrameQueuePtr=frameQueuePtr;
    }
    GglVideoPlayTask::~GglVideoPlayTask(){
        stopFlag=true;
        playThreadPtr->join();
        
    }
    void GglVideoPlayTask::runPlayThread(){
        playThreadPtr = new thread(&GglVideoPlayTask::playTask,this);
        
    }
    AVFrame* GglVideoPlayTask::getCurrentFramePtr() {return currentFramePtr;}

    void GglVideoPlayTask::playTask() {
        AVFrame* destFramePtr;
        for(;!stopFlag;){
            this_thread::sleep_for(chrono::milliseconds(20));
        if (cacheFrameQueuePtr->size() > 0) {
            destFramePtr = av_frame_alloc();
          destFramePtr->width = playPortWidth;
          destFramePtr->height = playPortHeight;
          destFramePtr->format = AV_PIX_FMT_RGBA;
          av_frame_get_buffer(destFramePtr, 0);
          gglScale.scaleAndLoadTextureData(destFramePtr);
          
          unique_lock<mutex> lock{drawMtx};
          if (shouldDrawVideoTex) {
            av_frame_free(&currentFramePtr);
          }
          currentFramePtr = destFramePtr;
          shouldDrawVideoTex = true;
          lock.unlock();
        }
        }
    }
}