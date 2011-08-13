#include "test.h"

using namespace Seventh;

// set initial configuration

myGame::myGame()
{
	setInitialConfig();
	Initialize();

	StateMenu myState;

	// testing state manager
	_Gameplay()->_StateManager()->registerState("test", myState);
	STATE test = _Gameplay()->_StateManager()->getStatePtr("test");

	test->setNextState();

	test->OnUpdate();
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
