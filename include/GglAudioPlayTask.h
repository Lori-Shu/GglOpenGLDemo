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
         GglAudioPlayTask(GglSwResample& gglResample, GglFrameVector& fVector,
                          GglAVFrameQueue& frameQueue, 
                          GglVideoPlayTask& vTask);
         ~GglAudioPlayTask();
         void runPlayTask(GglAudioPlayer* instance);
         AVFrame * getCurrentFramePtr();
         bool getStopFlag();
        private:
         void playTask(GglAudioPlayer* instance);
         void loadTask();
         std::thread* playThreadPtr;
         std::thread* loadThreadPtr;
         GglSwResample& gglResample;
         GglFrameVector& fVector;
         GglAVFrameQueue& frameQueue;
         bool stopFlag;
         AVFrame* currentFramePtr;
         AVFrame* lastVideoFramePtr;
         int32_t currentIndex;
         GglVideoPlayTask& vTask;
         char errBuffer[1024];
        };
}

