#include "GglAudioPlayer.h"

namespace mystd {
using namespace std;
GglAudioPlayer::GglAudioPlayer(GglAudioPlayTask& playTask):playTask(playTask) {
    bufferSize=0;
  if (initOpenAL() != 0) {
    throw runtime_error("init OpenAL failed!");
  }
}
GglAudioPlayer::~GglAudioPlayer() {
    stop();
    for(auto &item:bufIds){
  alDeleteBuffers(1, &item);
    }
    alDeleteSources(1,&sourceId);
  alcMakeContextCurrent(NULL);
  alcDestroyContext(alContext);
  alcCloseDevice(alDevice);
}
int32_t GglAudioPlayer::initOpenAL() {
  alDevice = alcOpenDevice(nullptr);
  alContext = alcCreateContext(alDevice, nullptr);
  alcMakeContextCurrent(alContext);
  bool g_bEAX = alIsExtensionPresent("EAX2.0");
  int32_t error;

  // Generate Sources
  alGenSources(1, &sourceId);
  if ((error = alGetError()) != AL_NO_ERROR) {
    cout << "alGenSources 1 : " << error << endl;
    return -1;
  }
  return 0;
}
void GglAudioPlayer::playAudioFrame() {
    int32_t playing;
    for(;;){
        this_thread::sleep_for(chrono::milliseconds(20));
        if(playTask.getStopFlag()){
            return;
        }
    alGetSourcei(sourceId, AL_PLAYING, &playing);
    if(playing<0){
        continue;
    }
    break;
    }
    if(alIsSource(sourceId)){
        cout<<"source is valid"<<endl;
    }
  ALenum error;
  auto currentPtr= playTask.getCurrentFramePtr();

//   alSourcei(sourceId, AL_BUFFER, 0);
//   if ((error = alGetError()) != AL_NO_ERROR) {
//         cout << "alBufferData buffer 0 : " << error << endl;
//         throw runtime_error("bufferDataError!");
//         return;
//   }
  uint32_t buffer;
alGenBuffers(1,&buffer);
if(alIsBuffer(buffer)){
    cout<<"buffer is valid"<<endl;
}
int bytes_per_sample = av_get_bytes_per_sample(static_cast<AVSampleFormat>( currentPtr->format));
int frame_size =
    currentPtr->nb_samples * currentPtr->ch_layout.nb_channels * bytes_per_sample;
alBufferData(buffer, AL_FORMAT_STEREO8, currentPtr->data[0],
             frame_size,
             currentPtr->sample_rate);
             

if ((error = alGetError()) != AL_NO_ERROR) {
    
    cout << "alBufferData buffer 0 : " << error << endl;
    throw runtime_error("bufferDataError!");
    return;
    }
    bufferSize += currentPtr->linesize[0];
    bufIds.push_back(buffer);
    alSourcei(sourceId,AL_BUFFER,buffer);
      if ((error = alGetError()) != AL_NO_ERROR) {
        throw runtime_error(" source queue buffer Error!");
      }
      play();
}
void GglAudioPlayer::pause(){
    int32_t paused;
    alGetSourcei(sourceId,AL_PAUSED,&paused);
    cout<<paused<<endl;
    if(paused==0){
        alSourcePause(sourceId);
    }

}
void GglAudioPlayer::stop(){
    int32_t stopd;
    alGetSourcei(sourceId, AL_STOPPED, &stopd);
    cout << stopd << endl;
    if (stopd == 0) {
        alSourceStop(sourceId);
    }
}
void GglAudioPlayer::play(){
    int32_t playing;
    alGetSourcei(sourceId, AL_PLAYING, &playing);
    cout << playing << endl;
    if (playing > 0) {
        alSourcePlay(sourceId);
    }
}
} // namespace mystd