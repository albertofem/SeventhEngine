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
#include "Entity.h"

namespace Seventh
{
	bool Scene::changeScene(std::string name)
	{
		return mSceneManager->setCurrentScene(name);
	}

	bool Scene::changeScene(Scene* scene)
	{
		return mSceneManager->setCurrentScene(scene);
	}

	void Scene::setSceneManager(SceneManager* scene_manager)
	{
		mSceneManager = scene_manager;
	}

	void Scene::registerEntity(Entity *entity)
	{
		mEntityRegister[entity->getId()] = entity;
	}

	void Scene::removeEntity(Entity *entity)
	{
		mEntityRegister.erase(entity->getId());
	}

	void Scene::update()
	{
		for (auto& entityRegister : mEntityRegister) {
			entityRegister.second->update();
		}
	}
}