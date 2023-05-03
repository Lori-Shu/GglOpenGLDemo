#include "GglAudioPlayer.h"

namespace mystd {
using namespace std;
GglAudioPlayer::GglAudioPlayer(GglAudioPlayTask& playTask):playTask(playTask) {
    bufferSize=0;
    dataOffset=0;
  if (initOpenAL() != 0) {
    throw runtime_error("init OpenAL failed!");
  }
}
GglAudioPlayer::~GglAudioPlayer() {
  alcMakeContextCurrent(NULL);
  alcDestroyContext(alContext);
  alcCloseDevice(alDevice);
}
int32_t GglAudioPlayer::initOpenAL() {
  alDevice = alcOpenDevice(nullptr);
  alContext = alcCreateContext(alDevice, nullptr);
  alcMakeContextCurrent(alContext);
  bool g_bEAX = alIsExtensionPresent("EAX2.0");
  alGetError();
  alGenBuffers(2, audioDataBuffer);
  ALenum error;
  if ((error = alGetError()) != AL_NO_ERROR) {
    cout << "alGenBuffers :" << error << endl;
    return -1;
  }
  // Generate Sources
  alGenSources(1, &sourceId);
  if ((error = alGetError()) != AL_NO_ERROR) {
    cout << "alGenSources 1 : " << error << endl;
    return -1;
  }
  return 0;
}
void GglAudioPlayer::playAudioFrame() {
  ALenum error;
  alSourceStop(sourceId);
  alSourcei(sourceId, AL_BUFFER, 0);
  if ((error = alGetError()) != AL_NO_ERROR) {
    throw runtime_error("SourceUnqueueBuffers Error!");
    return;
  }
  auto& currentPtr= playTask.getCurrentFramePtr();
  if(bufferSize==0){
  alBufferData(audioDataBuffer[0], AL_FORMAT_STEREO8,
               playTask.getCurrentFramePtr()->data[0],
               102400,
               playTask.getCurrentFramePtr()->sample_rate);
  dataOffset = playTask.getCurrentFramePtr()->linesize[0]-1;
  bufferSize = 102400;
  } else if (bufferSize-dataOffset+1>currentPtr->linesize[0]){
    alBuffer
  }

  if ((error = alGetError()) != AL_NO_ERROR) {
    
    cout << "alBufferData buffer 0 : " << error << endl;
    alDeleteBuffers(2, audioDataBuffer);
    throw runtime_error("bufferDataError!");
    return;
      }
      alSourcei(sourceId, AL_BUFFER, audioDataBuffer[0]);
    // alSourceQueueBuffers(sourceId,1,audioDataBuffer);
      if ((error = alGetError()) != AL_NO_ERROR) {
        cout << "alSourcei AL_BUFFER 0 : " << error << endl;
        throw runtime_error(" source buffer Error!");
      }
      alSourcePlay(sourceId);
} 
} // namespace mystd