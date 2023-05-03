#pragma once
#include"PreInclude.h"
#include"GglSwScale.h"
#include"GglFrameVector.h"
extern "C"{
    #include<libavformat/avformat.h>
}
namespace mystd{
    class GglVideoPlayTask{
        public:
         GglVideoPlayTask(
             GglSwScale& gglScale,
             std::chrono::duration<int32_t, std::milli>& timePerFrame,
             GglFrameVector& fVectorl,GglAVFrameQueue& frameQueue);
         ~GglVideoPlayTask();
         void runPlayThread();
        AVFrame * getCurrentFramePtr();
        private:
         void playTask();
         void loadTask();
         GglSwScale& gglScale;
         std::thread* playThreadPtr;
         std::thread* loadThreadPtr;
         bool stopFlag;
         std::chrono::duration<int32_t, std::milli>* timePerFramePtr;
         GglFrameVector& fVector;
         int32_t playPortWidth;
         int32_t playPortHeight;
         GglAVFrameQueue& frameQueue;
         AVFrame *currentFramePtr;
         int32_t currentIndex;
    };
}
