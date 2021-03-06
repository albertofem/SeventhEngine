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

#include "Common.h"

#ifndef _ENGINE_H_
#define _ENGINE_H_

namespace Seventh
{
	class Logger;
	class EngineConfig;
	class EventDispatcher;
	class SceneManager;
	class Game;
	class ResourceManager;
	class Rendering;
	class InputManager;

	class SeventhEngine : public Singleton<SeventhEngine>, public AllocatedObject
	{
	public:
		SeventhEngine();
		~SeventhEngine();

		bool run();

	public:
		Logger* getLogger();
		EngineConfig* getEngineConfig();
		ResourceManager* getResourceMananger();
		SceneManager* getSceneManager();
		EventDispatcher* getEventDispatcher();
		Rendering* getRendering();
		InputManager* getInputManager();

		bool loadGame(Game* game);

	protected:
		Logger* mLogger;
		EngineConfig* mEngineConfig;
		ResourceManager* mResourceManager;
		SceneManager* mSceneManager;
		EventDispatcher* mEventDispatcher;
		Rendering* mRendering;
		InputManager* mInputManager;
	};
}

#endif