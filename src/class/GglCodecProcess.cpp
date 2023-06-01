#include"GglCodecProcess.h"

namespace mystd{
    using namespace std;
    GglCodecProcess::GglCodecProcess(AVCodecParameters* par) {
      this->par = par;
      this->cacheQueuePtr=make_unique<GglAVFrameQueue>();
      createCodecContext();
    }
GglCodecProcess::~GglCodecProcess(){
    codecThreadStopFlag=true;
    codecThreadPtr->join();
    avcodec_free_context(&codecContextPtr);
}
// 传入解包过后的一条packetqueue
void GglCodecProcess::runCodec(GglAVPacketQueue* packetQuePtr) {
    codecThreadStopFlag=false;
    codecThreadPtr = new thread(&GglCodecProcess::codec, this, packetQuePtr);
}
GglAVFrameQueue* GglCodecProcess::getCacheFrameQueue(){return cacheQueuePtr.get();}
AVCodecParameters* GglCodecProcess::getCodecPar(){return par;}
void GglCodecProcess::codec(GglAVPacketQueue* packetQuePtr) {
    AVFrame* framePtr;
    AVPacket* tempPacketPtr;
    int32_t res=-1;
    for(;!codecThreadStopFlag;){
        
      for (;cacheQueuePtr->size()>10 && !codecThreadStopFlag;) {
        this_thread::sleep_for(chrono::milliseconds(1));
      }
        if(codecThreadStopFlag){
            return;
        }
        if(packetQuePtr->size()<1){
            this_thread::sleep_for(chrono::milliseconds(1));
            continue;
        }
        tempPacketPtr=packetQuePtr->front();
        packetQuePtr->pop();
        
        res= avcodec_send_packet(codecContextPtr,tempPacketPtr);
        if (res != 0) {
            av_strerror(res, errBuffer, 1024);
            throw runtime_error(errBuffer);
            return;
        }
        
        // av_packet_unref(tempPacketPtr);
        // if (tempPacketPtr->time_base.num != 0) {
        //     throw std::runtime_error("er");
        // }
        for (;!codecThreadStopFlag;){
            framePtr = av_frame_alloc();
            res = avcodec_receive_frame(codecContextPtr, framePtr);
            if (res == AVERROR_EOF||res==AVERROR(EAGAIN)) {
              break;
            }
            if (res != 0) {
              av_strerror(res, errBuffer, 1024);
              throw runtime_error(errBuffer);
              return;
            }
            framePtr->time_base=tempPacketPtr->time_base;
            cacheQueuePtr->push(framePtr);
        }
        av_packet_free(&tempPacketPtr);
        }
}
void GglCodecProcess::createCodecContext() {
    codecContextPtr=avcodec_alloc_context3(nullptr);
    int32_t res= avcodec_parameters_to_context(codecContextPtr,par);
    if (res != 0) {
      av_strerror(res, errBuffer, 1024);
      cout << errBuffer << endl;
      return ;
    }
    decoder= avcodec_find_decoder(codecContextPtr->codec_id);
    res =avcodec_open2(codecContextPtr,decoder,nullptr);
    if (res != 0) {
      av_strerror(res, errBuffer, 1024);
      cout << errBuffer << endl;
      return;
    }
}

}