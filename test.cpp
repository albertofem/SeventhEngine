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
	set__CONFIG_INI("./seventh.ini");
	set__RESOURCES_XML("./resources/resources.xml");
}

void myGame::DoSomeStuff()
{
	U16 layerID = _Display()->_Layers()->CreateLayer();

	StateMenu* main_menu = new StateMenu(this);
	MyPlayer player(this);

	_Gameplay()->_States()->RegisterState("main_menu", main_menu);

	_Resources()->LoadTexture("zelda_overall_01");
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
		Engine->_Display()->_Layers()->TransformOverallTexture("zelda_overall_01", STH_Transform(0, 5));
		break;

	case KEY_PRESS_UP:
		Engine->_Display()->_Layers()->TransformOverallTexture("zelda_overall_01", STH_Transform(0, -5));
		break;

	case KEY_PRESS_RIGHT:
		Engine->_Display()->_Layers()->TransformOverallTexture("zelda_overall_01", STH_Transform(5, 0));
		break;

	case KEY_PRESS_LEFT:
		Engine->_Display()->_Layers()->TransformOverallTexture("zelda_overall_01", STH_Transform(-5, 0));
		break;

	case KEY_PRESS_A:

		break;

	default:
		// do nothing
		break;
	}
}

void StateMenu::Update()
{
	TRACE("Doing something in this current state!");
}

MyPlayer::MyPlayer(myGame* game_ref)
{
	Engine = game_ref;
}

MyPlayer::~MyPlayer()
{

}
