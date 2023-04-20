#shader vertex
#version 440 

layout(location=0) in vec4 positions;
layout(location=1) in vec2 texCoord;

out vec2 outTexCoord;
uniform mat4 uMVP;
void main(){
    gl_Position=uMVP*positions;
    outTexCoord=texCoord;
}

#shader fragment
#version 440  

out vec4 outPutColor;

uniform vec4 uColor;

uniform sampler2D uTexture;

in vec2 outTexCoord;

void main(){
    outPutColor=texture(uTexture,outTexCoord);
}