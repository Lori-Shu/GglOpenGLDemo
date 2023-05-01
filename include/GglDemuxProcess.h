#pragma once
#define __STDC_CONSTANT_MACROS
extern "C" {
#include <libavutil/avutil.h>
#include<libavformat/avformat.h>
}

#include "PreInclude.h"
#include"GglAVPacketQueue.h"
#include"GglAVFrameQueue.h"
namespace mystd{
    class GglDemuxProcess{
        public:
         GglDemuxProcess(std::string filePath);
         ~GglDemuxProcess();
        //  会启动一个独立线程
         void runDemux();

        private:
        void getAudioParameters();
        void getVideoParameters();
        int32_t initDemux(std::string filePath);
        void demux();
         std::string filePath;
         AVFormatContext* formatContextPtr;
         char msgBuffer[1024];
         int32_t audioIndex;
         int32_t videoIndex;
         std::thread * demuxThread;
         bool threadStopFlag;
         std::unique_ptr<GglAVPacketQueue> videoque;
         std::unique_ptr<GglAVPacketQueue> audioque;
         AVCodecParameters * audioPar;
         AVCodecParameters* videoPar;
    };
}