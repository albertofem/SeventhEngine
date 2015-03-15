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
#include "Core/SeventhEngine.h"
#include "Core/EngineComponent.h"

#ifndef _RESOURCE_MANAGER_H_
#define _RESOURCE_MANAGER_H_

namespace Seventh
{
	class ResourcePack;
	class ResourceObject;

	class ResourceManager : public EngineComponent<ResourceManager>
	{
	public:
		ResourceManager(SeventhEngine* engine);
		ResourceManager();
		~ResourceManager();

		ResourcePack* getPack(std::string name);

		ResourceObject* getResourceFromPack(
			std::string packName, 
			std::string type, 
			std::string resourceName
		);

		bool createPackFromFile(
			std::string name, 
			std::string filename, 
			bool loadOnCreation
		);

	private:
		std::map<std::string, ResourcePack*> mResourcePacks;
	};
}

#endif