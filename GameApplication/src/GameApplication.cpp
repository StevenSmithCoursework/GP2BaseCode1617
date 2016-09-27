#include "GameApplication.h"

GameApplication::GameApplication()
{
	CREATELOG("log.txt");
	m_pWindow = nullptr;
	m_WindowWidth = 640;
	m_WindowHeight = 480;
	m_WindowCreationFlags = 0;
	m_WindowTitle = "Game";
}

GameApplication::~GameApplication()
{
  CLOSELOG();
}

void GameApplication::parseConfig(int args,char * arg[])
{
  stringstream ss;
  //parse config file
  XMLOptionsParser xmlParser=XMLOptionsParser("settings.xml");
  xmlParser.parse(m_Options);
  ss<<m_Options;
  LOG(INFO,"Settings Parsed\n%s",ss.str().c_str());
  ss.str( std::string());
  ss.clear();
	//parse command line arguments into keyvalue pairs, this should
	//overide options in config files
  CommandLineParser commandLineParser=CommandLineParser(args,arg);
  commandLineParser.parse(m_Options);
  ss<<m_Options;
  LOG(INFO,"Command Line Parsed\n%s",ss.str().c_str());
  ss.str( std::string());
  ss.clear();
}

void createWindow()
{
	//Create a window
	m_pWindow = SDL_CreateWindow(windowTitle.c_str(), // window title
		0,					// x position
		0,					// y position
		width,				// width in pixels
		height,				//height in pixels
		windowFlags 		// flags
	);
}

bool GameApplication::init(int args,char * arg[])
{
	// init everything - SDL, if it is nonzero we have a problem
	if (SDL_Init(SDL_INIT_EVERYTHING) != 0)
	{
		LOG(ERROR, "SDL can't be initialised %s", SDL_GetError());
		return false;
	}

	//m_pWindow = nullptr;
	

	parseConfig(args,arg);

	
	m_WindowWidth = m_Options.getOptionAsInt("WindowWidth");
	m_WindowHeight = m_Options.getOptionAsInt("WindowHeight");
	m_WindowTitle = m_Options.getOption("WindowTitle");

	createWindow(m_WindowTitle, m_WindowWidth, m_WindowHeight);

	return true;
}


void GameApplication::run()
{

}
