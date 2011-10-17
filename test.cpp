#include "test.h"

using namespace Seventh;

// set initial configuration

myGame::myGame()
{
	setInitialConfig();
	Initialize();
	U16 layerID = _Display()->_Layers()->createLayer();

	STH_Transform mytransform;

	mytransform.move_x = 10;
	mytransform.move_y = 20;

	StateMenu main_menu;

	_Gameplay()->_StateManager()->RegisterState("main_menu", main_menu);

	_Display()->_Layers()->_Layer(layerID)->CreateOverallTexture("zelda", "./test/zelda.jpg");
	_Display()->_Layers()->_Layer(0)->TransformOverallTexture("zelda", mytransform);
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

void StateMenu::OnEvent(e_EventCases type)
{
	STH_Transform mytransform;

	mytransform.move_x = 10;
	mytransform.move_y = 20;

	switch(type)
	{
	case KEY_PRESS_DOWN:
		//myGame::_Display()->_Layers()->_Layer(0)->TransformTexture("zelda", mytransform);
		break;
	}
}

void StateMenu::Update()
{
	TRACE("Doing something in this current state!");
}
