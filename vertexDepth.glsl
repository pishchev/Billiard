#version 330 core
layout (location = 0) in vec3 posAttr;

uniform mat4 lightSpaceMatrix;
uniform mat4 trmatrix;
uniform mat4 rtmatrix;

void main()
{
    gl_Position = lightSpaceMatrix * trmatrix*rtmatrix * vec4(posAttr, 1.0);
}
