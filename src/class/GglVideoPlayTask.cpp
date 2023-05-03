#include"GglVideoPlayTask.h"

namespace mystd{
    using namespace std;
    GglVideoPlayTask::GglVideoPlayTask(
        GglSwScale& gglScale,
        std::chrono::duration<int32_t, std::milli>& timePerFrame,
        GglFrameVector& fVector, GglAVFrameQueue& frameQueue)
        : gglScale(gglScale), fVector(fVector),frameQueue(frameQueue) {
      this->stopFlag = false;
      this->timePerFramePtr=&timePerFrame;
      this->playPortWidth=1280;
      this->playPortHeight = 720;
    }
    GglVideoPlayTask::~GglVideoPlayTask(){
        stopFlag=true;
        loadThreadPtr->join();
        playThreadPtr->join();
        
    }
    void GglVideoPlayTask::runPlayThread(){
        loadThreadPtr = new thread(&GglVideoPlayTask::loadTask,this);
        playThreadPtr = new thread(&GglVideoPlayTask::playTask,this);
        
    }
    AVFrame* GglVideoPlayTask::getCurrentFramePtr() {return currentFramePtr;}
    void GglVideoPlayTask::playTask(){
        auto& rawVt= fVector.getVector();
        for (; rawVt.size() == 0;) {
          this_thread::sleep_for(chrono::milliseconds(10));
        }
        currentIndex=0;
        currentFramePtr=rawVt[currentIndex];
        for(;!stopFlag;){
          this_thread::sleep_for(*timePerFramePtr);
          if(currentIndex== rawVt.size()-1){
            continue;
          }
          ++currentIndex;
          currentFramePtr = rawVt[currentIndex];
        }
    }
    void GglVideoPlayTask::loadTask() {
        for(;!stopFlag;){
            this_thread::sleep_for(chrono::milliseconds(20));
        if (frameQueue.size() > 0) {
          AVFrame* destFramePtr = av_frame_alloc();
          destFramePtr->width = playPortWidth;
          destFramePtr->height = playPortHeight;
          destFramePtr->format = AV_PIX_FMT_RGBA;
          av_frame_get_buffer(destFramePtr, 0);
          gglScale.scaleAndLoadTextureData(destFramePtr);
          fVector.getVector().push_back(destFramePtr);
        }
        }
    }
}