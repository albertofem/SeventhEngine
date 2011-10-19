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

	StateMenu* main_menu = new StateMenu(this);

	_Gameplay()->_StateManager()->RegisterState("main_menu", main_menu);

	_Display()->_Layers()->_Layer(layerID)->CreateOverallTexture("zelda", "./test/zelda.jpg");
	_Display()->_Layers()->_Layer(layerID)->CreateOverallTexture("zelda2", "./test/zelda.jpg");
	_Display()->_Layers()->_Layer(layerID)->CreateOverallTexture("zelda3", "./test/zelda.png");

	_Display()->_Layers()->_Layer(0)->TransformOverallTexture("zelda", STH_Transform(100, 100));
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

void StateMenu::OnEvent(EVENT_INFO type)
{
	switch(type.ecase)
	{
	case KEY_PRESS_DOWN:
		Engine->_Display()->_Layers()->_Layer(0)->TransformOverallTexture("zelda3", STH_Transform(0, 5));
		break;

	case KEY_PRESS_UP:
		Engine->_Display()->_Layers()->_Layer(0)->TransformOverallTexture("zelda3", STH_Transform(0, -5));
		break;

	case KEY_PRESS_RIGHT:
		Engine->_Display()->_Layers()->_Layer(0)->TransformOverallTexture("zelda3", STH_Transform(5, 0));
		break;

	case KEY_PRESS_LEFT:
		Engine->_Display()->_Layers()->_Layer(0)->TransformOverallTexture("zelda3", STH_Transform(-5, 0));
		break;

	case KEY_PRESS_A:
		Engine->_Display()->_Layers()->_Layer(0)->TransformOverallTexture("zelda", STH_Transform(0, 5));
		break;

	case KEY_PRESS_D:
		Engine->_Display()->_Layers()->_Layer(0)->TransformOverallTexture("zelda", STH_Transform(0, -5));
		break;

	case KEY_PRESS_W:
		Engine->_Display()->_Layers()->_Layer(0)->TransformOverallTexture("zelda", STH_Transform(5, 0));
		break;

	case KEY_PRESS_S:
		Engine->_Display()->_Layers()->_Layer(0)->TransformOverallTexture("zelda", STH_Transform(-5, 0));
		break;
	}
}

void StateMenu::Update()
{
	TRACE("Doing something in this current state!");
}
