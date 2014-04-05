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

#include "SceneManager.h"
#include "Scene.h"

namespace Seventh
{
	template<> SceneManager* Singleton<SceneManager>::mInstance = 0;

	SceneManager::SceneManager(SeventhEngine* engine)
		: EngineComponent(engine)
	{
		LOG_INFO("SceneManager: initialized")
	}

	SceneManager::~SceneManager()
	{
		LOG_INFO("SceneManager: shutdown")
	}

	bool SceneManager::addScene(Scene* scene)
	{
		std::map<std::string, Scene*>::iterator iterator = mScenes.find(scene->getName());

		if(iterator != mScenes.end())
		{
			LOG_WARN("SceneManager: Trying to add a duplicate scene with name: '%s'", scene->getName().c_str());
			return false;
		}

		mScenes[scene->getName()] = scene;

		return true;
	}

	void SceneManager::setCurrentScene(std::string scene_name)
	{
		std::map<std::string, Scene*>::iterator iterator = mScenes.find(scene_name);

		if(iterator == mScenes.end())
		{
			LOG_EXCEPTION("SceneManager: Trying to load a scene that does not exists '%s'", scene_name.c_str())
			throw new std::exception();
		}

		mCurrentScene = iterator->second;
	}

	void SceneManager::setCurrentScene(Scene* scene)
	{
		addScene(scene);
		setCurrentScene(scene->getName());
	}

	Scene* SceneManager::getCurrentScene()
	{
		return mCurrentScene;
	}

	void SceneManager::update()
	{
		getCurrentScene()->update();
	}

}