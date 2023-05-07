#include"GglDemuxProcess.h"

namespace mystd{
    using namespace std;
GglDemuxProcess::GglDemuxProcess(std::string filePath){
  this->filePath = filePath;
  this->audioIndex=-1;
  this->videoIndex=-1;
  this->audioQuePtr=make_unique<GglAVPacketQueue>();
  this->videoQuePtr = make_unique<GglAVPacketQueue>();
  if(initDemux(filePath)!=0){
    cout<<"初始化视频解包失败"<<endl;
    return;
  }
  findAudioCodecParameters();
  findVideoCodecParameters();
}
GglDemuxProcess ::~GglDemuxProcess(){
    threadStopFlag=true;
    demuxThread->join();
    avformat_close_input(&formatContextPtr);

      // 高版本不能使用 avformat_free_context(formatContextPtr);
}
void GglDemuxProcess ::runDemux() {
    threadStopFlag = false;
    demuxThread=new std::thread(&GglDemuxProcess::demux,this);
    
}
int32_t GglDemuxProcess ::getAudioIndex(){return audioIndex;}
int32_t GglDemuxProcess ::getVideoIndex(){return videoIndex;}
AVFormatContext* GglDemuxProcess ::getFormatContext() {return formatContextPtr;}
AVCodecParameters* GglDemuxProcess ::getVideoCodecParameters() {return videoPar;}
AVCodecParameters* GglDemuxProcess ::getAudioCodecParameters(){return audioPar;}
GglAVPacketQueue& GglDemuxProcess::getVideoPacketQueue(){return *videoQuePtr;}
GglAVPacketQueue& GglDemuxProcess::getAudioPacketQueue(){return *audioQuePtr;}
void GglDemuxProcess ::findAudioCodecParameters() {
    if (audioIndex != AVERROR_STREAM_NOT_FOUND) {
    audioPar = formatContextPtr->streams[audioIndex]->codecpar;
    return;
    }
    throw runtime_error("audioIndex is invalid!");
}
void GglDemuxProcess ::findVideoCodecParameters() {
    if (videoIndex != AVERROR_STREAM_NOT_FOUND) {
    videoPar = formatContextPtr->streams[videoIndex]->codecpar;
    return;
    }
    return;
    throw runtime_error("videoIndex is invalid!");
}
int32_t GglDemuxProcess::initDemux(std::string filePath) {
    formatContextPtr=avformat_alloc_context();
    int res=avformat_open_input(&formatContextPtr,filePath.c_str(),nullptr,nullptr);
    if(res!=0){
        av_strerror(res,msgBuffer,1024);
        cout<<msgBuffer<<endl;
        return -1;
    }
    av_dump_format(formatContextPtr,0,filePath.c_str(),0);
    res=avformat_find_stream_info(formatContextPtr,nullptr);
    if (res != 0) {
        av_strerror(res, msgBuffer, 1024);
        cout << msgBuffer << endl;
        return -1;
    }
    //                                                                 传入-1表示自动查找
    audioIndex= av_find_best_stream(formatContextPtr,AVMEDIA_TYPE_AUDIO,-1,-1,nullptr,0);
    videoIndex= av_find_best_stream(formatContextPtr, AVMEDIA_TYPE_VIDEO, -1, -1, nullptr,
                        0);
    if(audioIndex<0||videoIndex<0){
        if (audioIndex != AVERROR_STREAM_NOT_FOUND) {
            return 0;
        }
        cout<<"获取音视频流下标失败"<<endl;
        return -1;
    }

    return 0;
}
void GglDemuxProcess::demux() {
    AVPacket* pt;
    int32_t res;
    for(;!threadStopFlag;){
        pt = av_packet_alloc();
        res=av_read_frame(formatContextPtr,pt);
        if(res!=0){
          av_strerror(res, msgBuffer, 1024);
          if(res==AVERROR_EOF){
            break;
          }
          throw runtime_error(msgBuffer);
          return;
        }
        for(;(videoQuePtr->size()>1000)&&(!threadStopFlag);){
            cout<<"full v pts"<<videoQuePtr->front()->pts<<endl;
            cout << "full a pts" << audioQuePtr->front()->pts << endl;
            this_thread::sleep_for(chrono::milliseconds(10));
        }
        if(pt->stream_index==audioIndex){
            audioQuePtr->push(pt);
        }else if(pt->stream_index==videoIndex){
            videoQuePtr->push(pt);
        }
    }
}
}