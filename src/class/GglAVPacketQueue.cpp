#include"GglAVPacketQueue.h"
namespace mystd{
    using namespace std;
    GglAVPacketQueue::GglAVPacketQueue(){

    }
    GglAVPacketQueue::~GglAVPacketQueue(){
        AVPacket* tempPtr;
        for(;rawQueue.size()>0;){
            AVPacket& temp=rawQueue.front();
            tempPtr=&temp;
            av_packet_free(&tempPtr);
            rawQueue.pop();
        }
    }
}