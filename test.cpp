#include "test.h"

using namespace Seventh;

// set initial configuration

myGame::myGame()
{
	setInitialConfig();
	Initialize();
	U16 layerID = _Display()->_Layers()->createLayer();

	_Display()->_Layers()->_Layer(layerID)->CreateOverallTexture("zelda", "./test/zelda.jpg");
}

void myGame::setInitialConfig()
{
	TRACE("Calling initial config");
	set__CONFIG_INI("test/seventh.ini");
}

myGame::~myGame()
{
}

StateMenu::StateMenu()
{
}

StateMenu::~StateMenu()
{
}

void StateMenu::Update()
{
	TRACE("Doing something in this current state!");
}
