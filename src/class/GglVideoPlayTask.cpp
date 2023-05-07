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
      currentFramePtr=nullptr;
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
            this_thread::sleep_for(chrono::milliseconds(*timePerFramePtr));
        if (cacheFrameQueuePtr->size() > 0) {
            destFramePtr = av_frame_alloc();
      
          gglScale.scaleAndLoadTextureData(destFramePtr);
          
          unique_lock<mutex> lock{drawMtx};
          if (currentFramePtr!=nullptr) {
            av_frame_free(&currentFramePtr);
          }
          currentFramePtr = destFramePtr;
          shouldDrawVideoTex = true;
          lock.unlock();
        }
        }
    }
}