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
        destFramePtr->width = parPtr->width;
        destFramePtr->height = parPtr->height;
        destFramePtr->format = AV_PIX_FMT_RGBA;
        destFramePtr->pts = currentFramePtr->pts;
        destFramePtr->time_base=currentFramePtr->time_base;
        av_frame_get_buffer(destFramePtr, 0);
        int32_t height = sws_scale(swsContextPtr, currentFramePtr->data,
                                   currentFramePtr->linesize, 0, currentFramePtr->height,
                                   destFramePtr->data, destFramePtr->linesize);
        if(height<=0){
            throw runtime_error("scale out 0!");
        }
        // av_frame_unref(currentFramePtr);
        av_frame_free(&currentFramePtr);
    }
    void GglSwScale::createSwsContext(){
        swsContextPtr =
            sws_getContext(parPtr->width, parPtr->height, AV_PIX_FMT_YUV420P,
                           parPtr->width, parPtr->height, AV_PIX_FMT_RGBA,
                           SWS_FAST_BILINEAR, nullptr, nullptr, nullptr);
        cout << "frame width==" << parPtr->width << endl;
        cout << "frame height==" << parPtr->height << endl;
        cout << "frame format==" << parPtr->format << endl;
    }
}