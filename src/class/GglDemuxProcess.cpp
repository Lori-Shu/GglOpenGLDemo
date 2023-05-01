#include"GglDemuxProcess.h"

namespace mystd{
    using namespace std;
GglDemuxProcess::GglDemuxProcess(std::string filePath){
  this->filePath = filePath;
  this->audioIndex=-1;
  this->videoIndex=-1;
  if(initDemux(filePath)!=0){
    cout<<"初始化视频解包失败"<<endl;
    return;
  }
}
GglDemuxProcess ::~GglDemuxProcess(){
    threadStopFlag=true;
    demuxThread->join();
    avformat_close_input(&formatContextPtr);
}
void GglDemuxProcess ::runDemux() {
    demuxThread=new std::thread(&GglDemuxProcess::demux,this);
    threadStopFlag=false;
}
void GglDemuxProcess::getAudioParameters() {
    if(audioIndex!=-1){
        audioPar= formatContextPtr->streams[audioIndex]->codecpar;
        return;
    }
    throw runtime_error("audioIndex is invalid!");

}
void GglDemuxProcess::getVideoParameters() {
    if (audioIndex != -1) {
        audioPar = formatContextPtr->streams[audioIndex]->codecpar;
        return;
    }
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
        cout<<"获取音视频流下标失败"<<endl;
        return -1;
    }

    return 0;
}
void GglDemuxProcess::demux() {
    AVPacket pt;
    int32_t res;
    for(;!threadStopFlag;){
        res=av_read_frame(formatContextPtr,&pt);
        if(res!=0){
          av_strerror(res, msgBuffer, 1024);
          cout << msgBuffer << endl;
          return;
        }
        if(pt.stream_index==audioIndex){
            audioque.push(pt);
        }else if(pt.stream_index==videoIndex){
            videoque.push(pt);
        }
    }
}
}