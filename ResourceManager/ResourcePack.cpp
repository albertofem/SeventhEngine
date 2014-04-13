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
#include "ResourceTexture.h"

#include "Vendor/rapidxml_utils.hpp"

namespace Seventh
{
	bool ResourcePack::load()
	{
		try
		{
			rapidxml::file<> xmlFile(mFilename.c_str());
			mXmlDocument.parse<0>(xmlFile.data());	
		} catch(std::runtime_error)
		{
			LOG_ERROR("ResourceManager: Could not load resource pack file: '%s'", mFilename.c_str());
			return false;
		}

		LOG_DEBUG("ResourceManager: Loaded successfully resource pack file: '%s'", mFilename.c_str());

		mLoaded = true;

		return true;
	}

	ResourceObject* ResourcePack::getResource(std::string type, std::string name)
	{
		LOG_DEBUG("ResourceManager: Attempt to load resource '%s' in pack '%s'", name, mName);

		if(!mLoaded)
		{
			if(!load())
			{
				LOG_ERROR("ResourceManager: Cannot load resource '%s' in pack '%s'", name, mName);

				return false;
			}
		}

		if (mResources[type][name] != NULL)
		{
			return mResources[type][name];
		}

		rapidxml::xml_node<>* resources;
		
		resources = mXmlDocument.first_node("resources")->first_node(type.c_str());

		for (resources->first_node(); resources; resources->last_node())
		{
			if (resources->first_attribute("name")->value() == name.c_str())
			{
				LOG_DEBUG("ResourceManager: creating resource: '%s', name: '%s'", type.c_str(), name.c_str());

				mResources[type][name] = createResource(type, resources->first_attribute("src")->value());
				return mResources[type][name];
			}
		}

		LOG_WARN("ResourceManager: Cannot find resource with type: '%s', name: '%s'", type.c_str(), name.c_str());

		return NULL;
	}

	ResourceObject* ResourcePack::createResource(std::string type, std::string filename)
	{
		if (type == "texture")
		{
			return new ResourceTexture(filename);
		}

		return NULL;
	}

	ResourcePack::ResourcePack(std::string filename)
	{
		mFilename = filename;
	}

	void ResourcePack::setName(std::string name)
	{
		mName = name;
	}
}