#pragma once
#include <al.h>
#include<alc.h>
#include"GglFrameVector.h"
#include"GglAudioPlayTask.h"
namespace mystd{
    class GglAudioPlayer{
        public:
         GglAudioPlayer(GglAudioPlayTask& playTask);
         ~GglAudioPlayer();
         void playAudioFrame();
        void pause();
        void stop();
        void play();
        void setPlaySec(int32_t sec);

       private:
        int32_t initOpenAL();
         ALCdevice* alDevice;
         ALCcontext* alContext;
         uint32_t sourceId;
         GglAudioPlayTask& playTask;
         int32_t bufferSize;
         std::vector<uint32_t> bufIds;
         int32_t usedBufSize;
         int32_t freq;
         int32_t playSec;
    };
}
