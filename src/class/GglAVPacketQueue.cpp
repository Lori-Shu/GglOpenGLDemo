#include"GglAVPacketQueue.h"
namespace mystd{
    using namespace std;
    GglAVPacketQueue::GglAVPacketQueue(){

    }
    GglAVPacketQueue::~GglAVPacketQueue(){
        AVPacket* tempPtr;
        for(;rawQueue.size()>0;){
            tempPtr=rawQueue.front();
            av_packet_free(&tempPtr);
            rawQueue.pop();
        }
    }
    void GglAVPacketQueue::push(AVPacket *pPacket){
        std::unique_lock<std::mutex> lock{queMtx};
        // if (pPacket->time_base.num != 0) {
        //     throw std::runtime_error("er");
        // }
        AVPacket *tempPtr = (AVPacket *)av_malloc(sizeof(AVPacket));
        tempPtr->time_base = pPacket->time_base;
        av_packet_move_ref(tempPtr,pPacket);
        
        rawQueue.push(tempPtr);
        av_packet_free(&pPacket);
        cout<<"packet queue size=="<<rawQueue.size()<<endl;
    }
}