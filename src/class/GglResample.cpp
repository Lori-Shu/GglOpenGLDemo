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
        destFramePtr->ch_layout = AV_CHANNEL_LAYOUT_STEREO;
        destFramePtr->sample_rate = tempFramePtr->sample_rate;
        destFramePtr->nb_samples =
            av_rescale_rnd(swr_get_delay(swrContextPtr, tempFramePtr->sample_rate)+
                           tempFramePtr->nb_samples, destFramePtr->sample_rate,
                           tempFramePtr->sample_rate, AV_ROUND_UP);
        destFramePtr->format = AV_SAMPLE_FMT_U8;
        destFramePtr->pts=tempFramePtr->pts;
        destFramePtr->time_base = tempFramePtr->time_base;
        int32_t res = av_samples_alloc(
            destFramePtr->data, destFramePtr->linesize, destFramePtr->ch_layout.nb_channels,
            destFramePtr->nb_samples,
            static_cast<AVSampleFormat>(destFramePtr->format), 0);
        if (res <= 0) {
          av_strerror(res, errBuffer, 1024);
          throw runtime_error(errBuffer);
          return;
        }
        res = swr_convert(swrContextPtr, destFramePtr->data,
                                  destFramePtr->nb_samples, (const uint8_t**)tempFramePtr->data,
                                  tempFramePtr->nb_samples);
   
        if (res != destFramePtr->nb_samples) {
          av_strerror(res, errBuffer, 1024);
          throw runtime_error(errBuffer);
          return;
        }
        av_frame_free(&tempFramePtr);
    }

    void GglSwResample::createSwrContext(){
        swrContextPtr=swr_alloc();
        AVChannelLayout destLayout=AV_CHANNEL_LAYOUT_STEREO;
        int32_t res = swr_alloc_set_opts2(
            &swrContextPtr, &destLayout, AV_SAMPLE_FMT_U8,
            parPtr->sample_rate, &parPtr->ch_layout,
            static_cast<AVSampleFormat>(parPtr->format), parPtr->sample_rate, 0,
            nullptr);
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