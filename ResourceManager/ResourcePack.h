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

#include "ResourceObject.h"

#include "Vendor/rapidxml_utils.hpp"

#ifndef _RESOURCE_PACK_H_
#define _RESOURCE_PACK_H_

namespace Seventh
{
	class Resource;

	class ResourcePack : public ResourceObject
	{
	public:
		explicit ResourcePack(std::string filename) : ResourceObject(filename) {};
		bool load();
		void unload() {};

		Resource* getResource(std::string name);

	private:
		std::map<std::string, Resource*> mResources;
		rapidxml::xml_document<> mXmlDocument;
	};
}

#endif