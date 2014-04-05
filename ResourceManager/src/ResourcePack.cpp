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

#include "ResourcePack.h"

#include "Vendor/rapidxml_utils.hpp"

namespace Seventh
{
	bool ResourcePack::load()
	{
		try
		{
			rapidxml::file<> xmlFile(getFilename().c_str());
			mXmlDocument.parse<0>(xmlFile.data());	
		} catch(std::runtime_error)
		{
			LOG_ERROR("ResourceManager: Could not load resource pack file: '%s'", getFilename().c_str())
			return false;
		}

		LOG_DEBUG("ResourceManager: Loaded successfully resource pack file: '%s'", getFilename().c_str())
		mLoaded = true;

		return true;
	}

	Resource* ResourcePack::getResource(std::string name)
	{
		if(!isLoaded())
		{
			if(!load())
			{
				LOG_ERROR("ResourceManager: Cannot load resource '%s' in pack '%s'", name, mName)
				return false;
			}
		}

		rapidxml::xml_node<>* resources;
		
		resources = mXmlDocument.first_node("resources");

		std::cout << resources->name() << std::endl;

		for(resources->first_node(); resources; resources->next_sibling())
		{
			LOG_DEBUG("Parsing node: '%s'", resources->name())
		}
	}
}