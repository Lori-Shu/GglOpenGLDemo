#include"GglShader.h"

namespace mystd{
    using namespace std;
    GglShader::GglShader(){
        createShader();
    }
    GglShader::~GglShader(){
        glDeleteProgram(program);
    }
    void GglShader::getProgramDir(std::string &path) {
      char proDir[1024];
    //   只能在Linux环境有效
    #ifdef Linux
      int32_t size = readlink("/proc/self/exe", proDir, 1024);
    #endif
      string tp= string(proDir);
      int32_t lastIndex=tp.find_last_of('/');
      string dir=tp.substr(0,lastIndex+1-0);
      cout << "proDir==" << dir << endl;
      path = dir + string("shader/MyShader.shader");
    }
    void GglShader::readShaderFile(std::string &vertexShader,
                                          std::string &fragmentShader) {
        string path;
        getProgramDir(path);
        ifstream ifs{path, ios::in};
        stringstream ssVertex;
        stringstream ssFrag;
        string line;
        int32_t writeType=-1;
        for(;;){
        getline(ifs,line);
        if(line.find("#shader vertex")!=string::npos){
            writeType=0;
            continue;
        }
        if (line.find("#shader fragment") != string::npos) {
            writeType = 1;
            continue;
        }
        if(writeType==0){
            ssVertex<<line;
            ssVertex << "\n";
        }
        if (writeType == 1) {
            ssFrag << line;
            ssFrag<<"\n";
        }
        if (ifs.eof()) {
            break;
        }
        }
        ifs.close();
        vertexShader=ssVertex.str();
        fragmentShader = ssFrag.str();
    }
    void GglShader::createShader(){
        string vertexShader;
        string fragmentShader;
        readShaderFile(vertexShader,fragmentShader);
        program= glCreateProgram();
        uint32_t vs=  compileShader(GL_VERTEX_SHADER,vertexShader);
        uint32_t fs = compileShader(GL_FRAGMENT_SHADER, fragmentShader);
        glAttachShader(program,vs);
        glAttachShader(program,fs);
        glLinkProgram(program);
        glValidateProgram(program);

        glDeleteShader(vs);
        glDeleteShader(fs);
        glUseProgram(program);
        setUniform();
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
            char  buffer[length+1];
            glGetShaderInfoLog(id,length+1,&length,buffer);
            cout<<"err compile shader =="<<(type==GL_VERTEX_SHADER?"vertexShader":"fragShader")<<endl;
            cout<<buffer<<endl;
        }
        return id;

    }
    void GglShader:: setUniform(){
        // do not support double glUniform4d is not ok
        glUniform4f(1, 0.0f, 0.0f, 0.5f, 1.0f);
    }
}