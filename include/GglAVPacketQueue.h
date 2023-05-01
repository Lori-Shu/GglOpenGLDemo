#pragma once
#include"GglBlockingQueue.h"
#include"PreInclude.h"
extern "C" {
#include <libavformat/avformat.h>
}
namespace mystd{
    class GglAVPacketQueue:public GglBlockingQueue<AVPacket> {
        public:
         GglAVPacketQueue();
         ~GglAVPacketQueue();
    };
}