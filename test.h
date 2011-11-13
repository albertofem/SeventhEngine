#include "common.h"
#include "Engine/CEngine.h"
#include "DisplayCore/CLayerManager.h"
#include "DisplayCore/CLayer.h"
#include "GameplayCore/CGameplayCore.h"
#include "EntityCore/CEntity.h"

using namespace Seventh;

class myGame : public CEngine
{
public:
	myGame();
	~myGame();

	void DoSomeStuff();

private:
	void setInitialConfig();
};

// test states
class StateMenu : public CState
{
public:
	StateMenu(myGame* game_ref);
	~StateMenu();

	void UpdateGameLogic();
	void OnRegister() {};
	void OnDelete() {};
	void OnCameraChange() {};
	void OnEvent(EVENT_INFO type);

private:
	myGame* Engine;
};

// test entity
class MyPlayer : public CEntity
{
public:
	MyPlayer(myGame* game_ref);
	~MyPlayer();

	U32 m_EntityHealth;

	void ReduceHealth(S32 health);

	std::string m_CurrentPJ;

private:
	myGame* Engine;

	void UpdateGameLogic() {};
	void OnRegister() {};
	void OnDelete() {};
	void OnCameraChange() {};
	void OnEvent(EVENT_INFO type);
};

class MyPlayer2 : public CEntity
{
public:
	MyPlayer2(myGame* game_ref);
	~MyPlayer2();

private:
	myGame* Engine;

	void UpdateGameLogic() {};
	void OnRegister() {};
	void OnDelete() {};
	void OnCameraChange() {};
	void OnEvent(EVENT_INFO type) {};
};
