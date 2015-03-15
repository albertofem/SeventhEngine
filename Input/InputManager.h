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

#include "Core/Common.h"
#include "Core/SeventhEngine.h"
#include "Vendor/glfw/glfw3.h"

#define SE_KEY_SPACE GLFW_KEY_SPACE
#define SE_KEY_ARROW_DOWN GLFW_KEY_DOWN
#define SE_KEY_ARROW_UP GLFW_KEY_UP
#define SE_KEY_ARROW_RIGHT GLFW_KEY_RIGHT
#define SE_KEY_ARROW_LEFT GLFW_KEY_LEFT

namespace Seventh
{
	class InputManager : public EngineComponent<InputManager>
	{
	public:
		InputManager(SeventhEngine* engine);
		~InputManager();

		bool onKeyDown(uint keyVal);
		bool onKeyUp(uint keyVal);

		bool isKeyPressed(uint keyVal);

		void update();

		bool initialize(GLFWwindow* targetWindow);

	private:
		std::map<uint, bool> mKeyStates;
	};
}