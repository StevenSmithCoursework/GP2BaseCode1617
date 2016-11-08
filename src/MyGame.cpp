#include "MyGame.h"



const std::string ASSET_PATH = "assets";
const std::string SHADER_PATH = "/shaders";
const std::string TEXTURE_PATH = "/textures";
const std::string MODEL_PATH = "/models";

MyGame::MyGame()
{
	m_TestObject = nullptr;
	m_LoadObject = nullptr;
}

MyGame::~MyGame()
{

}

void MyGame::initScene()
{
	
	Vertex verts[] = {
	{vec3(-0.5f, -0.5f, 0.0f), vec4(1.0f,1.0f,1.0f,1.0f), vec2(0.0f,3.0f)},
	//{vec3(0.5f, -0.5f, 0.0f), vec4(1.0f,1.0f,1.0f,1.0f), vec2(3.0f,3.0f)},
	{vec3(-0.5f,  0.5f, 0.0f), vec4(1.0f,1.0f,1.0f,1.0f), vec2(0.0f,0.0f)},
		//{vec3(-0.5f, 0.5f, 0.0f), vec4(1.0f,1.0f,1.0f,1.0f), vec2(0.0f,0.0f)},
		{vec3(0.5f, 0.5f, 0.0f), vec4(1.0f,1.0f,1.0f,1.0f), vec2(3.0f,0.0f)},
		{vec3(0.5f,  -0.5f, 0.0f), vec4(1.0f,1.0f,1.0f,1.0f), vec2(3.0f,3.0f)}
	};

	int indices[] = {
		0, 3, 1,
		1, 3, 2
	};

	

	m_TestObject = new GameObject();
	m_LoadObject = new GameObject();



	string vsPath = ASSET_PATH + SHADER_PATH + "/simpleVS.glsl";
	string fsPath = ASSET_PATH + SHADER_PATH + "/textureFS.glsl";
	string modelPath = ASSET_PATH + MODEL_PATH + "/utah-teapot.fbx";

	
	m_LoadObject = loadModelFromFile(modelPath);
	m_LoadObject->loadShaders(vsPath, fsPath);

	m_TestObject->loadShaders(vsPath, fsPath);


	

	

	//lets load texture
	string texturePath = ASSET_PATH + TEXTURE_PATH + "/texture.png";
	m_TestObject->loadTexture(texturePath);
	m_LoadObject->loadTexture(texturePath);

	m_TestObject->copyVertexData(verts, 4, indices, 6);
}

void MyGame::destroyScene()
{
	if (m_TestObject)
	{
		m_TestObject->onDestroy();
		delete m_TestObject;
		m_TestObject = nullptr;
	}
	if (m_LoadObject)
	{
		m_TestObject->onDestroy();
		delete m_LoadObject;
		m_LoadObject = nullptr;
	}
}

void MyGame::update()
{
	GameApplication::update();

	m_ProjMatrix = perspective(radians(45.0f), (float)m_WindowWidth / (float)m_WindowHeight, 0.1f, 100.0f);
	m_ViewMatrix = lookAt(vec3(0.0f, 0.0f, 10.0f), vec3(0.0f, 0.0f, 0.0f), vec3(0.0f, 1.0f, 0.0f));
	m_ModelMatrix = translate(mat4(1.0f), vec3(0.0f, 0.0f, -0.2f));

	m_TestObject->onUpdate();
	m_LoadObject->onUpdate();
}

void MyGame::render()
{
	GameApplication::render();
	m_TestObject->onRender(m_ViewMatrix, m_ProjMatrix);
	m_LoadObject->onRender(m_ViewMatrix, m_ProjMatrix);
	
}
