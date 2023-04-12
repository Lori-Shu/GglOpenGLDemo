#shader vertex
#version 440 core

layout(location=0) in vec4 positions;

void main(){
    gl_Position=positions;
}

#shader fragment
#version 440 core 

layout(location=0) out vec4 color;

layout(location=1) uniform vec4 uColor=vec4(0.0,0.5,0.0,1.0);

void main(){
    color=uColor;
}