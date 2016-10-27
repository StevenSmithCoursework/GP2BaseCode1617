#ifndef GAMEOBJECT_H
#define GAMEOBJECT_H

#include "Common.h"
#include "Shader.h"
#include "Texture.h"
#include "Vertex.h"

//TODO: Need to add functions to change position, rotation and scale

class GameObject
{
public:
	GameObject();
	~GameObject();

	void onRender(mat4& view, mat4& projection);
	void onUpdate();
	void onInit();
	void onDestroy();
	
	void loadTexture(const string& filename);
	void loadShaders(const string& vsfilename, const string& fsfilename);
	void copyVertexData(Vertex *pVerts, int numberOfVertices);

	//void changeObject();
	void moveObject();

private:
	GLuint m_VBO;
	GLuint m_VAO;
	
	//Shader Program
	GLuint m_ShaderProgram;

	//matrices
	mat4 m_ViewMatrix;
	mat4 m_ProjMatrix;
	mat4 m_ModelMatrix;

	GLuint m_Texture;
	GLuint m_ClampSampler;

	vec3 m_Position;
	vec3 m_Rotation;
	vec3 m_Scale;

	mat4 m_TranslationMatrix;
	mat4 m_RotationMatrix;
	mat4 m_ScaleMatrix;

	int m_NumberOfVertices;

protected:

};


#endif

