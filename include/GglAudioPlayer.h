#pragma once
#include <al.h>
#include<alc.h>
#include<al
#include"GglFrameVector.h"
#include"GglAudioPlayTask.h"
namespace mystd{
    class GglAudioPlayer{
        public:
         GglAudioPlayer(GglAudioPlayTask& playTask);
         ~GglAudioPlayer();
         void playAudioFrame();

        private:
        int32_t initOpenAL();
         ALCdevice* alDevice;
         ALCcontext* alContext;
         uint32_t audioDataBuffer[2];
         uint32_t sourceId;
         GglAudioPlayTask& playTask;
         int32_t dataOffset;
         int32_t bufferSize;
    };
}
