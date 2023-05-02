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
}