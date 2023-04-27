#shader vertex
#version 440 

layout(location=0) in vec3 positions;
layout(location=2) in vec2 texCoord;
layout(location=3) in float textureIndex;
out vec2 outTexCoord;
out float ioTextureIndex;
uniform mat4 uMVP;
void main(){
    gl_Position=uMVP*vec4(positions,1.0);
    outTexCoord=texCoord;
    ioTextureIndex=textureIndex;
}

#shader fragment
#version 440  

out vec4 outPutColor;

uniform vec4 uColor;

uniform sampler2D uTexture[2];

in vec2 outTexCoord;

in float ioTextureIndex;

void main(){
    int i=int(ioTextureIndex);
    outPutColor=texture(uTexture[i],outTexCoord);
    // outPutColor=uColor;
}