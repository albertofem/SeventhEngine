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

#include "TiledMap.h"
#include "ResourceManager/ResourceManager.h"

namespace Seventh
{
    TiledMap::TiledMap(std::string packName, std::string mapName)
    {
        resourceMap = (ResourceMap*) GResourceManager.getResourceFromPack(packName, "maps", mapName);

        LOG_DEBUG("Creating map with filename: '%s'", resourceMap->getFilename().c_str());

        tmxMap = new Tmx::Map();
        tmxMap->ParseFile(resourceMap->getFilename());

        if (tmxMap->HasError()) {
            LOG_ERROR("Error loading map: '%s'", tmxMap->GetErrorText().c_str());
        }
    }


    bool TiledMap::load() {
        return false;
    }

    void TiledMap::unload() {

    }

    void TiledMap::render() {

    }
}
