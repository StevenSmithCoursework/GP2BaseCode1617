#version 410

out vec4 FragColor;
in vec2 vertexTexCoordsOut;

uniform sampler2D diffuseSampler;

void main()
{
	FragColor = texture(diffuseSampler, vertexTexCoordsOut);
}