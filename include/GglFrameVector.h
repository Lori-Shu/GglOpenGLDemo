#pragma once

#include"PreInclude.h"
extern"C"{
#include <libavformat/avformat.h>
}
namespace mystd{
    class GglFrameVector{
        public:
         GglFrameVector();
         ~GglFrameVector();
         std::vector<AVFrame*>& getVector();
         private:
         std::vector<AVFrame*> rawVector;
    };
}
