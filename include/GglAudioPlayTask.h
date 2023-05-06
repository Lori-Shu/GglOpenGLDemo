#pragma once

#include"GglSwResample.h"
#include"GglFrameVector.h"
#include"GglVideoPlayTask.h"
#include"PreInclude.h"
namespace mystd{
    // 前置声明避免互相引用
    class GglAudioPlayer;
    class GglAudioPlayTask{
        public:
         GglAudioPlayTask(GglSwResample& gglResample,
                          GglAVFrameQueue& cacheFrameQueue, 
                          GglVideoPlayTask& vTask);
         ~GglAudioPlayTask();
         void runPlayTask(GglAudioPlayer* instance);
         AVFrame * getCurrentFramePtr();
         bool getStopFlag();
        private:
         void playTask(GglAudioPlayer* instance);
         std::thread* playThreadPtr;
         GglSwResample& gglResample;
         GglAVFrameQueue& cacheFrameQueue;
         bool stopFlag;
         AVFrame* currentFramePtr;
         AVFrame* lastVideoFramePtr;
         GglVideoPlayTask& vTask;
         char errBuffer[1024];
        };
}


