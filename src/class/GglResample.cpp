#include"GglSwResample.h"

namespace mystd{
    using namespace std;
    GglSwResample::GglSwResample(GglAVFrameQueue* frameQueuePtr,
                               AVCodecParameters* par){
    this->frameQueuePtr=frameQueuePtr;
    this->parPtr=par;
    createSwrContext();
    }
    GglSwResample::~GglSwResample(){
        swr_free(&swrContextPtr);
    }
    void GglSwResample::resampleAndLoadPCMData(AVFrame * destFramePtr){
        AVFrame* tempFramePtr= frameQueuePtr->front();
        frameQueuePtr->pop();
        int32_t res=0;
        res = swr_convert(swrContextPtr, destFramePtr->data,
                                  destFramePtr->nb_samples, (const uint8_t**)tempFramePtr->data,
                                  tempFramePtr->nb_samples);
   
        if (res <= 0) {
          av_strerror(res, errBuffer, 1024);
          throw runtime_error(errBuffer);
          return;
        }
        av_frame_free(&tempFramePtr);
    }

    void GglSwResample::createSwrContext(){
        swrContextPtr=swr_alloc();
        int32_t res = swr_alloc_set_opts2(&swrContextPtr, &parPtr->ch_layout,
                                          AV_SAMPLE_FMT_U8P, parPtr->sample_rate,
                                          &parPtr->ch_layout, static_cast<AVSampleFormat>(parPtr->format),
                                          parPtr->sample_rate, 0, nullptr);
        if (res != 0) {
          av_strerror(res, errBuffer, 1024);
          throw runtime_error(errBuffer);
          return;
    }
    res= swr_init(swrContextPtr);
    if (res != 0) {
          av_strerror(res, errBuffer, 1024);
          throw runtime_error(errBuffer);
          return;
    }
    }
}