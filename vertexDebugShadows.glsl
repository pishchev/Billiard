#version 330

in vec3 posAttr;
in vec2 texCoord;

out vec2 ftexCoord;

void main()
{
    ftexCoord = texCoord ;
    gl_Position = vec4(posAttr,1);
}
