#include "common.h"
#include "Engine/CEngine.h"
#include "DisplayCore/CLayerManager.h"
#include "DisplayCore/CLayer.h"
#include "GameplayCore/CGameplayCore.h"

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

	void Update();

	void OnEvent(e_EventCases type);

	friend class myGame;

private:
	myGame* Engine;
};
