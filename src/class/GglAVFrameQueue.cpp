#include"GglAVFrameQueue.h"

namespace mystd{
    using namespace std;
    GglAVFrameQueue::GglAVFrameQueue() {

    }
    GglAVFrameQueue ::~GglAVFrameQueue(){
      AVFrame *tempPtr;
      for (; rawQueue.size() > 0;) {
        AVFrame& temp = rawQueue.front();
        tempPtr=&temp;
        av_frame_free(&tempPtr);
        rawQueue.pop();
      }
    }
}