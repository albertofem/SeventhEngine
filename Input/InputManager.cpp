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
 * @author Alberto Fernández <albertofem@gmail.com>
 */

#include "InputManager.h"
#include "Input.h"

namespace Seventh
{
	template<> InputManager* Singleton<InputManager>::mInstance = 0;

	InputManager::InputManager(SeventhEngine* engine)
		: EngineComponent(engine)
	{
		LOG_INFO("Input manager: initialized");
	}


	InputManager::~InputManager()
	{
		LOG_INFO("Input manager: shutdown");
	}

	bool InputManager::onKeyDown(uint keyVal)
	{
		if (mKeyStates[keyVal] == true)
			return false;

		LOG_DEBUG("Key down: '%d'", keyVal);

		mKeyStates[keyVal] = true;

		return true;
	}

	bool InputManager::onKeyUp(uint keyVal)
	{
		if (mKeyStates[keyVal] == false)
			return true;

		LOG_DEBUG("Key up: '%d'", keyVal);

		mKeyStates[keyVal] = false;

		return true;
	}

	void InputManager::update()
	{

	}

	bool InputManager::initialize(GLFWwindow* targetWindow)
	{
		glfwSetKeyCallback(targetWindow, glfwInputCallback);

		return true;
	}

	bool InputManager::isKeyPressed(uint keyVal)
	{
		return mKeyStates[keyVal];
	}
}