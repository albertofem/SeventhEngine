/*
 * SeventhEngine
 *
 * Copyright (C) 2013 Alberto Fernández
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

#ifndef _RESOURCE_MANAGER_H_
#define _RESOURCE_MANAGER_H_

namespace Seventh
{
	typedef enum ResourceType
	{
		RESOURCE_NULL = 0,
		RESOURCE_GRAPHIC = 1,
		RESOURCE_ANIMATION = 2,
		RESOURCE_AUDIO = 3,
		RESOURCE_FONT = 4,
	};

	class ResourcePack;

	class ResourceManager : public Singleton<ResourceManager>, public AllocatedObject
	{
	public:
		ResourceManager();
		~ResourceManager();

		ResourcePack* getPack(std::string name);
		bool loadPackFromFile(std::string filename);

	private:
		std::map<std::string, ResourcePack*> mResourcePacks;
	};
}

#endif