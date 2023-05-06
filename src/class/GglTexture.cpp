#include"GglTexture.h"
#include<stb/stb_image.h>
namespace mystd{
    using namespace std;
    GglTexture::GglTexture(std::string path):filePath(path){
        createTexture();
    }
    GglTexture::~GglTexture(){
        stbi_image_free(localBuffer);
        glDeleteTextures(1,&textureId);
    }
    void GglTexture::updateVideoFrameTexture(GglVideoPlayTask& vT) {
        auto currentFramePtr= vT.getCurrentFramePtr();
        glBindTexture(GL_TEXTURE_2D, textureId);
        // glTexSubImage2D(GL_TEXTURE_2D, 0, 0, 0, 1280, 720, GL_RGBA,
        //                 GL_UNSIGNED_BYTE, vT.getCurrentFramePtr()->data[0]);
        glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA, 1280, 720, 0, GL_RGBA,
                     GL_UNSIGNED_BYTE, currentFramePtr->data[0]);
    }
    void GglTexture::createTexture() {
        stbi_set_flip_vertically_on_load(1);
        localBuffer=stbi_load(filePath.c_str(),&width,&height,&bitsPerPixel,4);
        glGenTextures(1,&textureId);
        glBindTexture(GL_TEXTURE_2D,textureId);
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_CLAMP_TO_EDGE);
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_CLAMP_TO_EDGE);
        glTexParameteri(GL_TEXTURE_2D,GL_TEXTURE_MIN_FILTER,GL_LINEAR);
        glTexParameteri(GL_TEXTURE_2D,GL_TEXTURE_MAG_FILTER,GL_LINEAR);
        

        glTexImage2D(GL_TEXTURE_2D,0,GL_RGBA8,width,height,0,GL_RGBA,GL_UNSIGNED_BYTE,localBuffer);
        
    }

    void GglTexture::bind(uint32_t slot) {
        glActiveTexture(GL_TEXTURE0+slot);
        glBindTexture(GL_TEXTURE_2D, textureId);
    }
    void GglTexture::unBind() { glBindTexture(GL_TEXTURE_2D,0);}
    uint32_t GglTexture::getTextureId() { return textureId;}
}
