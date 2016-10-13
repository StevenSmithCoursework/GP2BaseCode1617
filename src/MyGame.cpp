#include "MyGame.h"

struct Vertex 
{
	float x, y, z;
};

const std::string ASSET_PATH = "Assets";
const std::string SHADER_PATH = "/Shaders";


void MyGame::initScene()
{
	Vertex verts[] = {
		{-0.5f, -0.5f, 0.0f},
		{0.5f, -0.5f, 0.0f},
		{0.0f, 0.5f, 0.0f}
	};

	glGenBuffers(1, &m_VBO);
	glBindBuffer(GL_ARRAY_BUFFER, m_VBO);
	glBufferData(GL_ARRAY_BUFFER, 3 * sizeof(Vertex), verts, GL_STATIC_DRAW);
	glGenVertexArrays(1, &m_VAO);
	glBindVertexArray(m_VAO);
	glBindBuffer(GL_ARRAY_BUFFER, m_VBO);
	glEnableVertexAttribArray(0);
	glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, sizeof(Vertex), NULL);
}

void GameApplication::initScene()
{
}

void MyGame::destroyScene()
{
	glDeleteVertexArrays(1, &m_VAO);
	glDeleteBuffers(1, &m_VBO);
}

void GameApplication::destroyScene()
{
}

void MyGame::render()
{
}

void GameApplication::render()
{
}

void MyGame::update()
{
}

void GameApplication::update()
{
}

MyGame::MyGame()
{
	m_VBO = 0;
	m_VAO = 0;
}

MyGame::~MyGame()
{

}
