#include "test.h"

using namespace Seventh;

// set initial configuration

myGame::myGame()
{
	setInitialConfig();
	Initialize();
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
