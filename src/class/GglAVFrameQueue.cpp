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
    void GglAVFrameQueue ::push(AVFrame *pFrame) {
      std::unique_lock<std::mutex> lock{queMtx};
      AVFrame *pTemp = (AVFrame *)av_malloc(sizeof(AVFrame));
      av_frame_move_ref(pTemp, pFrame);
      rawQueue.push(pTemp);
      av_frame_free(&pFrame);
      cout<<"frameQueue size=="<<rawQueue.size()<<endl;
    }
}