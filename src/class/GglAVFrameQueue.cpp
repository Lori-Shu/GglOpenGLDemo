#include"GglAVFrameQueue.h"

namespace mystd{
    using namespace std;
    GglAVFrameQueue::GglAVFrameQueue() {

    }
    GglAVFrameQueue ::~GglAVFrameQueue(){
      AVFrame *tempPtr;
      for (; rawQueue.size() > 0;) {
        tempPtr = rawQueue.front();
        av_frame_free(&tempPtr);
        rawQueue.pop();
      }
    }
}