#pragma once
extern"C"{
#include <libswresample/swresample.h>
#include<libavutil/avutil.h>
#include<libavformat/avformat.h>
}
#include"GglAVFrameQueue.h"

namespace mystd{
    class GglSwResample{
     public:
      GglSwResample(GglAVFrameQueue* frameQueuePtr, AVCodecParameters* par);
      ~GglSwResample();
      void resampleAndLoadPCMData(AVFrame* destFramePtr);

     private:
      void createSwrContext();
      AVCodecParameters* parPtr;
      SwrContext* swrContextPtr;
      GglAVFrameQueue* frameQueuePtr;
      AVFrame* currentFramePtr;
      char errBuffer[1024];
    };
}
