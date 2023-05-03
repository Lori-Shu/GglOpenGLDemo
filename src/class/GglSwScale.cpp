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

    void GglSwScale::scaleAndLoadTextureData(AVFrame* destFramePtr) {
        currentFramePtr = frameQueuePtr->front();
        frameQueuePtr->pop();
        int32_t height = sws_scale(swsContextPtr, currentFramePtr->data,
                                   currentFramePtr->linesize, 0, currentFramePtr->height,
                                   destFramePtr->data, destFramePtr->linesize);
        av_frame_free(&currentFramePtr);
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