/*
 * SeventhEngine, an SDL-based general-purpose
 * game engine. Made for learning purposes
 *
 * Copyright (C) 2012 Alberto Fernández
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 *
 * @author	Alberto Fernández <albertofem@gmail.com>
 * @version	0.1
 *
 */

#include "common.h"
#include "Engine/CEngine.h"

namespace Seventh
{
	// initialize static configuration vars
	std::string CEngine::__CONFIG_INI = "";
	std::string CEngine::__RESOURCES_XML = "";

	RESOURCE_MANAGER CEngine::Resources;
	ENTITY_MANAGER CEngine::Entities;
	boost::shared_ptr<CClock> CEngine::Clock = CClock::getInstance();
	bool CEngine::s_Running = true;

	CEngine::CEngine()
	{
		// empty constructor, user must call the "Initialize()"
		// method in order to start the engine
	}

	CEngine::~CEngine()
	{
	}

	void CEngine::Initialize()
	{
		/*
		 * start and get config
		 */
		EngineConfig.reset(new CEngineConfig);
		EngineConfig->setConfigFile(CEngine::get__CONFIG_INI());
		EngineConfig->Start();

		/*
		 * start entity manager
		 */
		Entities.reset(new CEntityManager());
		Entities->Start();

		/*
		 * start display core
		 */
		Display.reset(new CDisplayCore(EngineConfig));
		Display->Start();

		/*
		 * start gameplay core
		 */
		Gameplay.reset(new CGameplayCore);
		Gameplay->Start();

		/*
		 * start events core
		 */
		Events.reset(new CEventsCore(this));
		Events->Start();

		/*
		 * start resources
		 */
		Resources.reset(new CResourceManager(__RESOURCES_XML, this));
		Resources->Start();
	}

	// main loop, everything happens here
	void CEngine::RunGame()
	{
		/*
		 * After systems had been initialized, we enter
		 * in the main game loop where all the operations
		 * takes place. This is controlled directly by the
		 * engine itself, leaving to the client the programming
		 * of the game logic and presentation, using the engine
		 * tools, classes and methods
		 */

		// local variable for the main loop, to force clients
		// to use the signal system in order to stop the engine
		bool running = true;

		// events
		SDL_Event event;

		// set first measure of the internal clock
		Clock->init();

		// main game loop
		while(running)
		{
			Clock->reset();

			while(Clock->logic())
			{

				/*
				 * events loop; loop for queued
				 * events and register in the events
				 * core class for future handling
				 */
				while(SDL_PollEvent(&event))
				{
					Events->RegisterEvent(event);
				}

				// do update game logic
				UpdateGameLogic();

				// update clock
				Clock->update();

				// render
				RenderGame();
			}

			// stop loop in the static variable has
			// been modified
			if(s_Running != true)
			{
				running = false;
			}

		}

		Shutdown();
	}

	void CEngine::EngineCall(const ENGINE_SIGNAL signal)
	{
		switch(signal)
		{
		case STOP_ENGINE:
			s_Running = false;
			TRACE("Received call to stop engine!");
			break;
		}
	}

	void CEngine::Shutdown()
	{
		// finish subsystem in reverse order
		Gameplay->Shutdown();
		Display->Shutdown();
		EngineConfig->Shutdown();
		Events->Shutdown();
	}

	void CEngine::UpdateGameLogic() throw()
	{
		// update different subsystems game logic
		Display->UpdateGameLogic();
		Entities->UpdateGameLogic();
	}

	void CEngine::RenderGame() throw()
	{
		Display->Render();
	}
}
