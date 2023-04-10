#include"GglShader.h"
#include<GL/glew.h>
namespace mystd{
    using namespace std;
    GglShader::GglShader(){
        createShader(readVertexShader(),readFragShader());
    }
    GglShader::~GglShader(){
        glDeleteProgram(program);
    }
    std::string GglShader::readVertexShader() {
        string path =
            shaderFolder + string("VertexShader.txt");
        return readFile(path);
    }
    std::string GglShader::readFragShader() {
        string path =
            shaderFolder + string("FragmentShader.txt");
     return readFile(path);
    }
    std::string GglShader::readFile(std::string &path) {
     ifstream ifs{path, ios::in};
     stringstream ss{ios::out};
     ss << ifs.rdbuf();
     string shaderStr = ss.str();
     ifs.close();
     return shaderStr;
    }
    void GglShader::createShader(std::string vertexShader,std::string fragShader){
        program= glCreateProgram();
        uint32_t vs=  compileShader(GL_VERTEX_SHADER,vertexShader);
        uint32_t fs = compileShader(GL_FRAGMENT_SHADER,fragShader);
        glAttachShader(program,vs);
        glAttachShader(program,fs);
        glLinkProgram(program);
        glValidateProgram(program);

        glDeleteShader(vs);
        glDeleteShader(fs);
        glUseProgram(program);
    }
    uint32_t GglShader::compileShader(uint32_t type, std::string &shader) {
        uint32_t id=glCreateShader(type);
        const char *source = shader.c_str();
         glShaderSource(id, 1,&source , nullptr);
         glCompileShader(id);
        int32_t result;
        glGetShaderiv(id,GL_COMPILE_STATUS,&result);
        if(result==GL_FALSE){
            int32_t length;
            glGetShaderiv(id,GL_INFO_LOG_LENGTH,&length);
            char  buffer[length];
            glGetShaderInfoLog(id,length,&length,buffer);
            cout<<"err compile shader =="<<(type==GL_VERTEX_SHADER?"vertexShader":"fragShader")<<endl;
            cout<<buffer<<endl;
        }
        return id;

    }
}