#ifndef _MyGame_H
#define _MyGame_H

#include "GameApplication.h"

class MyGame:public GameApplication
{
public:

	void initScene();
	void destroyScene();
	void render();
	void update();

	GLuint m_ShaderProgram;
	GLuint m_Texture;
	GLuint m_Sampler;

	//matrices
	mat4 m_ViewMatrix;
	mat4 m_ProjMatrix;
	mat4 m_ModelMatrix;

	MyGame();
	~MyGame();

private:

	GLuint m_VBO;
	GLuint m_VAO;

};
#endif
