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

#include "Core/Common.h"
#include "Core/EngineComponent.h"

#include "Scene.h"

#ifndef _SCENE_MANAGER_H_
#define _SCENE_MANAGER_H_

namespace Seventh
{
	class SeventhEngine;

	class SceneManager : public EngineComponent<SceneManager>
	{
	public:
		SceneManager() {};
		SceneManager(SeventhEngine* engine);
		~SceneManager();

		bool addScene(Scene* scene);
		void setCurrentScene(std::string scene_name);
		void setCurrentScene(Scene* scene);
		Scene* getCurrentScene();

		void update();

	private:
		std::map<std::string, Scene*> mScenes;
		Scene* mCurrentScene;
	};
}

#endif