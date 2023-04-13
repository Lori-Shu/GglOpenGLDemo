#shader vertex
#version 440 core

layout(location=0) in vec4 positions;

void main(){
    gl_Position=positions;
}

#shader fragment
#version 440 core 

layout(location=0) out vec4 color;

layout(location=1) uniform vec4 uColor;

void main(){
    color=uColor;
}