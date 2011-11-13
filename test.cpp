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
	StateMenu* main_menu = new StateMenu(this);
	MyPlayer* player = new MyPlayer(this);
	MyPlayer2* player2 = new MyPlayer2(this);

	_Gameplay()->_States()->RegisterState("main_menu", main_menu);
	_Display()->_Layers()->RegisterOverallEntity("player1", player);

	_Entities()->Entity("player1")->SetTexture("ryu");
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
		case KEY_PRESS_A:
			TRACE("un event");
			break;

		default:
			// do nothing
			break;
	}
}

void StateMenu::UpdateGameLogic()
{
	TRACE("Doing something in this current state!");
}

MyPlayer::MyPlayer(myGame* game_ref)
{
	Engine = game_ref;

	m_EntityHealth = 100;
	m_CurrentPJ = "Ryu";
}

MyPlayer::~MyPlayer()
{
}


MyPlayer2::MyPlayer2(myGame* game_ref)
{
	Engine = game_ref;
}

MyPlayer2::~MyPlayer2()
{
}


void MyPlayer::OnEvent(EVENT_INFO type)
{
	STH_Transform move_entity(5, 0);

	switch(type.ecase)
	{
		case KEY_PRESS_A:
			if(m_EntityHealth > 0)
			{
				Move(move_entity);
				ReduceHealth(10);

				TRACE("Entity health is now %d", m_EntityHealth);
			}
			else
			{
				TRACE("Entity is dead!");
				Hide();
			}
		break;

		case KEY_PRESS_D:
			if(m_CurrentPJ == "Ryu")
			{
				SetTexture("ken");
				m_CurrentPJ = "Ken";
			}
			else
			{
				SetTexture("ryu");
				m_CurrentPJ = "Ryu";
			}
		break;
	}
}

void MyPlayer::ReduceHealth(S32 health)
{
	m_EntityHealth -= health;
}
