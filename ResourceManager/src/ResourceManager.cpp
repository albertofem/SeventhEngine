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

#include "ResourceManager.h"
#include "ResourcePack.h"

#include "Vendor/SimpleIni.h"
#include "Core/SeventhEngine.h"
#include "Core/EngineConfig.h"

namespace Seventh
{
	template<> ResourceManager* Singleton<ResourceManager>::mInstance = 0;

	ResourceManager::ResourceManager(SeventhEngine* engine)
		: EngineComponent(engine)
	{
		LOG_INFO("Initialized resource manager subsystem")

		const CSimpleIniA::TKeyVal* resourcePacks = mEngine->getEngineConfig()->getIniReader()->GetSection("resources");
		CSimpleIniA::TKeyVal::const_iterator i; 

		for (i = resourcePacks->begin(); i != resourcePacks->end(); ++i)
		{ 
			createPackFromFile(i->first.pItem, i->second, true);
		}

		// mResourcePacks["sample"]->getResource("hola");
	}

	ResourceManager::~ResourceManager()
	{
		LOG_INFO("Finished resource manager subsystem")
	}

	ResourcePack* ResourceManager::getPack(std::string name)
	{
		std::map<std::string, ResourcePack*>::iterator iterator = mResourcePacks.find(name);

		if(iterator == mResourcePacks.end())
			throw new std::exception("Invalid resource pack");

		return iterator->second;
	}

	bool ResourceManager::createPackFromFile(std::string name, std::string filename, bool loadOnCreation = false)
	{
		LOG_DEBUG("Loading resource pack '%s'", name.c_str())

		ResourcePack* newResourcePack = new ResourcePack(filename);
		mResourcePacks[name] = newResourcePack;

		if(loadOnCreation)
			newResourcePack->load();

		return true;
	}

	Resource* ResourceManager::getResourceFromPack(std::string packName, std::string resourceName)
	{
		ResourcePack* pack = getPack(packName);

		return pack->getResource(resourceName);
	}
}