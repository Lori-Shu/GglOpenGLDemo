#include"GglShader.h"

namespace mystd{
    using namespace std;
    GglShader::GglShader(){
        createShader();
    }
    GglShader::~GglShader(){
        glDeleteProgram(program);
    }
    void GglShader::readShaderFile(std::string &vertexShader,
                                          std::string &fragmentShader) {
        string path;
        getProgramDir(path);
        path = path + string("shader/MyShader.shader");
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
        int32_t result;
        glGetProgramiv(program, GL_LINK_STATUS, &result);
        if (result == GL_FALSE) {
        int32_t length;
        glGetProgramiv(program, GL_INFO_LOG_LENGTH, &length);
        char buffer[length + 1];
        glGetProgramInfoLog(program, length + 1, &length, buffer);
        cout << "err link shader =="<< endl;
        cout << buffer << endl;
        }
        glDeleteShader(vs);
        glDeleteShader(fs);
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
    int32_t GglShader::getUniformLocation(std::string name) {
        // do not support double glUniform4d is not ok
        // must use float
        int32_t location;
        if (locationCache.find(name) != locationCache.end()) {
            location = locationCache[name];
            return location;
        }
            location = glGetUniformLocation(program,name.c_str());
            locationCache[name] = location;
        return location;
    }
    void GglShader:: setUniform4f(string uniformName,float v0,float v1,float v2,float v3){
        glUniform4f(getUniformLocation(uniformName), v0, v1, v2, v3);
    }
    void GglShader::setUniform1i(std::string uniformName, int32_t i){
        glUniform1i(getUniformLocation(uniformName),i);
    }
    void GglShader::setUniformMatrix4f(std::string uniformName, glm::mat4 mtx) {
        glUniformMatrix4fv(getUniformLocation(uniformName),1,GL_FALSE,&mtx[0][0]);
    }
    void GglShader::useProgram(){
        glUseProgram(program);
    }
    void GglShader::unUseProgram() { glUseProgram(0); }
}