#include"GglTexture.h"
#include<stb_image.h>
namespace mystd{
    using namespace std;
    GglTexture::GglTexture(std::string path):filePath(path){
        createTexture();
    }
    GglTexture::~GglTexture(){
        stbi_image_free(localBuffer);
        glDeleteTextures(1,&textureId);
    }
    void GglTexture::createTexture() {
        
        glGenTextures(1,&textureId);
        glBindTexture(GL_TEXTURE_2D,textureId);
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_CLAMP_TO_EDGE);
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_CLAMP_TO_EDGE);
        glTexParameteri(GL_TEXTURE_2D,GL_TEXTURE_MIN_FILTER,GL_LINEAR);
        glTexParameteri(GL_TEXTURE_2D,GL_TEXTURE_MAG_FILTER,GL_LINEAR);
        // stbi_set_flip_vertically_on_load(1);
        localBuffer =
            stbi_load(filePath.c_str(), &width, &height, &bitsPerPixel, 0);

        glTexImage2D(GL_TEXTURE_2D,0,GL_RGB,width,height,0,GL_RGB,GL_UNSIGNED_BYTE,localBuffer);
        // glGenerateMipmap(GL_TEXTURE_2D);
    }

    void GglTexture::bind(uint32_t slot) {
        glActiveTexture(GL_TEXTURE0);
        glBindTexture(GL_TEXTURE_2D, textureId);
    }
    void GglTexture::unBind() { glBindTexture(GL_TEXTURE_2D,0);}
    uint32_t GglTexture::getTextureId() {return textureId;}
    int32_t GglTexture::getWidth(){return width;}
    int32_t GglTexture::getHeight(){return height;}
}
