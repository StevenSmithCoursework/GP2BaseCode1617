#version 410

out vec4 FragColor;

struct DirectionalLight
{
	vec3 direction;

	vec4 ambientColour;
	vec4 diffuseColour;
	vec4 specularColour;
};

in vec3 vertexNormalOut;
in vec3 cameraDirectionOut;
in vec2 vertexTextureCoordsOut;
in vec4 vertexColoursOut;
in vec3 lightDirectionOut;

uniform vec4 ambientMaterialColour=vec4(0.5f,0.0f,0.0f,1.0f);
uniform float specularPower=25.0f;

uniform sampler2D diffuseSampler;
uniform sampler2D specularSampler;
uniform sampler2D normalSampler;

uniform DirectionalLight directionLight;

void main()
{
	vec3 bumpNormals = 2.0f * (texture(normalSampler, vertexTextureCoordsOut).xyz) - 1.0f;
	
	bumpNormals = normalize(bumpNormals);
	
	vec3 lightDir =  normalize(-directionLight.direction);
	float diffuseTerm = dot(bumpNormals, lightDir);
	vec3 halfWayVec = normalize(cameraDirectionOut + lightDir);
	float specularTerm = pow(dot(bumpNormals, halfWayVec), specularPower);
	
	vec4 diffuseTextureColor = texture(diffuseSampler, vertexTextureCoordsOut);
	vec4 specularTextureColor = texture(specularSampler, vertexTextureCoordsOut);

	FragColor = (ambientMaterialColour*directionLight.ambientColour) + (diffuseTextureColor*directionLight.diffuseColour*diffuseTerm) + (specularTextureColor*directionLight.specularColour*specularTerm);
	
}
