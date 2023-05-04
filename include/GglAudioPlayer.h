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

       private:
        int32_t initOpenAL();
         ALCdevice* alDevice;
         ALCcontext* alContext;
         uint32_t sourceId;
         GglAudioPlayTask& playTask;
         int32_t bufferSize;
         std::vector<uint32_t> bufIds;
    };
}
