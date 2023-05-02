#pragma once
#include"PreInclude.h"
extern "C"{
    #include<libswscale/swscale.h>
    #include<libavutil/imgutils.h>
    #include<libavcodec/avcodec.h>
}
#include"GglAVFrameQueue.h"
#include<glad/glad.h>
namespace mystd{
    class GglSwScale{
        public:
         GglSwScale(GglAVFrameQueue* frameQueuePtr,AVCodecParameters* par);
         ~GglSwScale();
         void scaleOneTextureData(uint32_t textureId);
         private:
          void createSwsContext();
          AVCodecParameters* parPtr;
          SwsContext* swsContextPtr;
          GglAVFrameQueue* frameQueuePtr;
          AVFrame* currentFramePtr;
          char errBuffer[1024];
    };
}