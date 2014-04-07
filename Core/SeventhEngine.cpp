/*
 * SeventhEngine
 *
 * Copyright (c) Alberto Fernández
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
 */

#include "SeventhEngine.h"

#include "EngineConfig.h"
#include "EventDispatcher.h"
#include "Game.h"

#include "ResourceManager/ResourceManager.h"
#include "SceneManager/SceneManager.h"
#include "Rendering/Rendering.h"
#include "Input/InputManager.h"

namespace Seventh
{
	LogLevel logLevel = LogLevel::DEBUG;

	template<> SeventhEngine* Singleton<SeventhEngine>::mInstance = 0;

	SeventhEngine::SeventhEngine()
	{
		mLogger = new Logger(this);
		mEngineConfig = new EngineConfig(this, "./engine.cfg");
		mResourceManager = new ResourceManager(this);
		mEventDispatcher = new EventDispatcher(this);
		mSceneManager = new SceneManager(this);
		mRendering = new Rendering();
		mInputManager = new InputManager(this);
	}

	Logger* SeventhEngine::getLogger()
	{
		return mLogger;
	}

	SeventhEngine::~SeventhEngine()
	{
		delete mResourceManager;
		delete mEngineConfig;
		delete mLogger;
		delete mEventDispatcher;
		delete mSceneManager;
		delete mRendering;
		delete mInputManager;
	}

	bool SeventhEngine::run()
	{
		int running = true;

		LOG_INFO("%d", mEngineConfig->getScreenWidth());

		// initialize rendering
		if(!mRendering->initialize(
			mEngineConfig->getScreenWidth(), 
			mEngineConfig->getScreenHeight(), 
			mEngineConfig->getFullScreen(), 
			mEngineConfig->getGameTitle()
		))
		{
			return false;
		}

		// initialize input
		mInputManager->initialize(mRendering->getCurrentWindow());

		LOG_DEBUG("SeventhEngine: Ready to run main game loop")

		while(running)
		{
			mSceneManager->update();

			if(!mRendering->render())
				running = false;
		}

		mRendering->shutdown();

		return true;
	}

	EngineConfig* SeventhEngine::getEngineConfig()
	{
		return mEngineConfig;
	}

	bool SeventhEngine::loadGame(Game* game)
	{
		LOG_INFO("SeventhEgine: Loading game '%s'", game->getName().c_str());

		game->setEngine(this);
		game->onLoad();

		try
		{
			mSceneManager->setCurrentScene(game->getFirstScene());
		}
		catch(...)
		{
			LOG_CRIT("SventhEngine: Cannot load game, shutting down...");
			return false;
		}

		return true;
	}

	SceneManager* SeventhEngine::getSceneManager()
	{
		return mSceneManager;
	}

	EventDispatcher* SeventhEngine::getEventDispatcher()
	{
		return mEventDispatcher;
	}

	Rendering* SeventhEngine::getRendering()
	{
		return mRendering;
	}

	InputManager* SeventhEngine::getInputManager()
	{
		return mInputManager;
	}
}