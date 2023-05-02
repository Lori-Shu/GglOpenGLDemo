#pragma once
#include"PreInclude.h"
#include"GglBlockingQueue.h"
extern "C" {
#include <libavformat/avformat.h>
}

namespace mystd{
    class GglAVFrameQueue:public GglBlockingQueue<AVFrame*>{
        public:
         GglAVFrameQueue();
         ~GglAVFrameQueue();
    };
}