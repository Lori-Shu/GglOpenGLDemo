#include "GglAudioPlayer.h"

namespace mystd {
using namespace std;
GglAudioPlayer::GglAudioPlayer(GglAudioPlayTask& playTask)
    : playTask(playTask) {
  bufferSize = 0;
  usedBufSize = 0;
  if (initOpenAL() != 0) {
    throw runtime_error("init OpenAL failed!");
  }
}
GglAudioPlayer::~GglAudioPlayer() {
  stop();
  alDeleteBuffers(bufIds.size(), bufIds.data());
  alDeleteSources(1, &sourceId);
  alcMakeContextCurrent(NULL);
  alcDestroyContext(alContext);
  alcCloseDevice(alDevice);
}
int32_t GglAudioPlayer::initOpenAL() {
  alDevice = alcOpenDevice(nullptr);
  alContext = alcCreateContext(alDevice, nullptr);
  alcMakeContextCurrent(alContext);
  bool g_bEAX = alIsExtensionPresent("EAX2.0");
  alcGetIntegerv(alDevice, ALC_FREQUENCY, sizeof(int32_t), &freq);
  cout << "supported sample rate==" << freq << endl;
  int32_t error;

  // Generate Sources
  alGenSources(1, &sourceId);
  if ((error = alGetError()) != AL_NO_ERROR) {
    cout << "alGenSources 1 : " << error << endl;
    return -1;
  }
  alSourcei(sourceId, AL_LOOPING, AL_FALSE);

  //   事先创建buffer
  for (int32_t index = 0; index < 100;) {
    uint32_t buffer;
    alGenBuffers(1, &buffer);
    bufIds.push_back(buffer);
    ++index;
  }
  return 0;
}
void GglAudioPlayer::playAudioFrame() {
  ALenum error;
  auto currentPtr = playTask.getCurrentFramePtr();
  for (; bufIds.size() < 100 && !playTask.getStopFlag();) {
    this_thread::sleep_for(chrono::milliseconds(1));
  }
  int32_t processedSize;
  int32_t state = AL_PLAYING;
  uint32_t bufferId;
  alGetSourcei(sourceId, AL_SOURCE_STATE, &state);
  cout << "state==" << state << endl;
  if (usedBufSize < bufIds.size()) {
    bufferId = bufIds[usedBufSize];
    ++usedBufSize;
  } else if (state == AL_PLAYING || state == AL_PAUSED) {
    for (processedSize = 0; processedSize < 1 && !playTask.getStopFlag();) {
      //   cout<<"processedSize =="<<processedSize<<endl;
      this_thread::sleep_for(chrono::milliseconds(1));
      alGetSourcei(sourceId, AL_BUFFERS_PROCESSED, &processedSize);
    }
    cout << "get unqueued bufid============" << endl;
    alSourceUnqueueBuffers(sourceId, 1, &bufferId);
  }

  alBufferData(bufferId, AL_FORMAT_STEREO8, currentPtr->data[0],
               currentPtr->linesize[0], currentPtr->sample_rate);
  if ((error = alGetError()) != AL_NO_ERROR) {
    cout << "alBufferData buffer 0 : " << error << endl;
    throw runtime_error("bufferDataError!");
    return;
  }

  bufferSize += currentPtr->linesize[0];
  cout << "audio buffer size==" << bufferSize << endl;
  alSourceQueueBuffers(sourceId, 1, &bufferId);

  if ((error = alGetError()) != AL_NO_ERROR) {
    throw runtime_error(" source queue buffer Error!");
  }
  int32_t queuedSize;
  alGetSourcei(sourceId, AL_BUFFERS_QUEUED, &queuedSize);
  alGetSourcei(sourceId, AL_BUFFERS_PROCESSED, &processedSize);
  if(usedBufSize>25){
    play();
  }
}
void GglAudioPlayer::pause() {
  int32_t paused;
  alGetSourcei(sourceId, AL_SOURCE_STATE, &paused);
  cout << paused << endl;
  if (paused != AL_PAUSED) {
    alSourcePause(sourceId);
  }
}
void GglAudioPlayer::stop() {
  int32_t stopd;
  alGetSourcei(sourceId, AL_SOURCE_STATE, &stopd);
  cout << stopd << endl;
  if (stopd != AL_STOPPED) {
    alSourceStop(sourceId);
  }
}
void GglAudioPlayer::play() {
  int32_t playing;
  alGetSourcei(sourceId, AL_SOURCE_STATE, &playing);
  cout << playing << endl;
  if (playing != AL_PLAYING) {
    alSourcePlay(sourceId);
  }
}
void GglAudioPlayer::pauseIfBufferNotReady() {
  int32_t processed = 0;
  int32_t buffered = 0;
  alGetSourcei(sourceId, AL_BUFFERS_PROCESSED, &processed);
  alGetSourcei(sourceId, AL_BUFFERS_QUEUED, &buffered);
  if (buffered - processed < 25) {
    pause();
  }
}
}  // namespace mystd