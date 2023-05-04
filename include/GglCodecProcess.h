#pragma once
#include"PreInclude.h"
extern "C" {
#include <libavformat/avformat.h>
#include <libavutil/avutil.h>
#include<libavcodec/avcodec.h>
}
#include"GglDemuxProcess.h"
namespace mystd{
    /**
     * 将所有解码之后的视频帧保留在内存中是不明智的，坑！
    */
    class GglCodecProcess{
        public:
         GglCodecProcess(AVCodecParameters* par);
         ~GglCodecProcess();
         void runCodec(GglAVPacketQueue* packetQuePtr);
         GglAVFrameQueue* getCacheFrameQueue();
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
         AVFrame* currentFramePtr;
         std::unique_ptr<GglAVFrameQueue> cacheQueuePtr;
    };
}