#pragma once
#include"PreInclude.h"
extern "C" {
#include <libavformat/avformat.h>
#include <libavutil/avutil.h>
#include<libavcodec/avcodec.h>
}
#include"GglDemuxProcess.h"
namespace mystd{
    class GglCodecProcess{
        public:
         GglCodecProcess(AVCodecParameters* par);
         ~GglCodecProcess();
         void runCodec(GglAVPacketQueue* packetQuePtr);
        GglAVFrameQueue &getFrameQueue();
        AVCodecParameters* getCodecPar();

       private:
        void codec(GglAVPacketQueue* packetQuePtr);
        void createCodecContext();
        AVCodecContext* codecContextPtr;
        const AVCodec* decoder;
        char errBuffer[1024];
        std::thread* codecThreadPtr;
        bool codecThreadStopFlag;
        AVCodecParameters* par;
        std::unique_ptr<GglAVFrameQueue> frameQueuePtr;
    };
}