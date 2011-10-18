#include "test.h"

using namespace Seventh;

// set initial configuration

myGame::myGame()
{
	setInitialConfig();
	Initialize();

	DoSomeStuff();
}

void myGame::setInitialConfig()
{
	TRACE("Calling initial config");
	set__CONFIG_INI("test/seventh.ini");
}

void myGame::DoSomeStuff()
{
	U16 layerID = _Display()->_Layers()->createLayer();

	STH_Transform mytransform;

	mytransform.move_x = 100;
	mytransform.move_y = 100;

	StateMenu* main_menu = new StateMenu(this);

	_Gameplay()->_StateManager()->RegisterState("main_menu", main_menu);

	_Display()->_Layers()->_Layer(layerID)->CreateOverallTexture("zelda", "./test/zelda.jpg");
	_Display()->_Layers()->_Layer(layerID)->CreateOverallTexture("zelda2", "./test/zelda.jpg");

	_Display()->_Layers()->_Layer(0)->TransformOverallTexture("zelda", mytransform);
}

myGame::~myGame()
{
}

StateMenu::StateMenu(myGame* game_ref)
	: Engine(game_ref)
{
}

StateMenu::~StateMenu()
{
}

void StateMenu::OnEvent(e_EventCases type)
{
	STH_Transform mytransform;

	mytransform.move_x = 10;
	mytransform.move_y = 20;

	switch(type)
	{
	case KEY_PRESS_DOWN:
		Engine->_Display()->_Layers()->_Layer(0)->TransformOverallTexture("zelda", mytransform);
		Engine->_Display()->_Layers()->_Layer(0)->TransformOverallTexture("zelda2", mytransform);
		break;
	}
}

void StateMenu::Update()
{
	TRACE("Doing something in this current state!");
}
