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

	MyGame();
	~MyGame();

private:

	GLuint m_VBO;
	GLuint m_VAO;

};
#endif
