#shader vertex
#version 440 core

layout(location=0) in vec4 positions;
layout(location=1) in vec2 texCoord;

out vec2 outTexCoord;
void main(){
    gl_Position=positions;
    outTexCoord=texCoord;
}

#shader fragment
#version 440 core 

layout(location=0) out vec4 color;

uniform vec4 uColor;

uniform sampler2D uTexture;

in vec2 outTexCoord;

void main(){
    vec4 texColor=texture(uTexture,outTexCoord);
    color=texColor;
}