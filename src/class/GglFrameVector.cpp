#include"GglFrameVector.h"

namespace mystd{
    using namespace std;
    GglFrameVector::GglFrameVector(){

    }
    GglFrameVector::~GglFrameVector(){
        for(auto &item:rawVector){
            av_frame_free(&item);
        }
    }
    std::vector<AVFrame*>& GglFrameVector::getVector(){return rawVector;}
}