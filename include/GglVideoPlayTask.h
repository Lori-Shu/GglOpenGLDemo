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
             std::chrono::duration<int32_t, std::milli>& timePerFrame,GglAVFrameQueue* frameQueuePtr);
         ~GglVideoPlayTask();
         void runPlayThread();
        AVFrame * getCurrentFramePtr();
        std::mutex drawMtx;
        bool shouldDrawVideoTex;

       private:
        void playTask();
        GglSwScale& gglScale;
        std::thread* playThreadPtr;
        bool stopFlag;
        std::chrono::duration<int32_t, std::milli>* timePerFramePtr;

        int32_t playPortWidth;
        int32_t playPortHeight;
        GglAVFrameQueue* cacheFrameQueuePtr;
        AVFrame* currentFramePtr;
    };
}
