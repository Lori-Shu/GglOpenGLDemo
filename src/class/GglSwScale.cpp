#include"GglSwScale.h"

namespace mystd{
    using namespace std;
    GglSwScale::GglSwScale(GglAVFrameQueue* frameQueuePtr,
                           AVCodecParameters* par) {
      this->frameQueuePtr = frameQueuePtr;
      this->parPtr=par;
      createSwsContext();
    }
    GglSwScale::~GglSwScale(){
        sws_freeContext(swsContextPtr);
    }

    void GglSwScale::scaleOneTextureData(uint32_t textureId) {
      if (frameQueuePtr->size() > 0) {
        currentFramePtr = frameQueuePtr->front();
        frameQueuePtr->pop();
        AVFrame* destFramePtr = av_frame_alloc();
        destFramePtr->width=currentFramePtr->width;
        destFramePtr->height = currentFramePtr->height;
        destFramePtr->format = AV_PIX_FMT_RGBA;
        av_frame_get_buffer(destFramePtr,0);
        int32_t height = sws_scale(swsContextPtr, currentFramePtr->data,
                                   currentFramePtr->linesize, 0, currentFramePtr->height,
                                   destFramePtr->data, destFramePtr->linesize);
        cout << "scaled height==" << height << endl;
        glActiveTexture(GL_TEXTURE0);
        glBindTexture(GL_TEXTURE_2D, textureId);
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_CLAMP_TO_EDGE);
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_CLAMP_TO_EDGE);
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
        glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA, destFramePtr->width, destFramePtr->height, 0, GL_RGBA,
                     GL_UNSIGNED_BYTE, destFramePtr ->data[0]);
      
        av_frame_free(&currentFramePtr);
        av_frame_free(&destFramePtr);
      }
    }
    void GglSwScale::createSwsContext(){
      swsContextPtr =
          sws_getContext(parPtr->width, parPtr->height, AV_PIX_FMT_YUV420P,
                         parPtr->width, parPtr->height, AV_PIX_FMT_RGBA,
                         SWS_BILINEAR, nullptr, nullptr, nullptr);
      cout << "frame width==" << parPtr->width << endl;
      cout << "frame height==" << parPtr->height << endl;
      cout << "frame format==" << parPtr->format << endl;
    }
}