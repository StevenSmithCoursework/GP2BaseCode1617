#version 410
layout(location=0)in vec3 vertexPosition;
layout(location=1) in vec2 vertexTextureCoords;
out vec2 vertexTexCoordsOut;

uniform mat4 MYP;

void main()
{
	vertexTexCoordsOut = vertexTextureCoords;
	gl_Position = MVP*vec4(vertexPosition, 1.0);
}