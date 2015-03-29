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

#ifndef _TILED_MAP_H_
#define _TILED_MAP_H_

#include <Vendor/tmxparser/src/TmxMap.h>
#include "RenderingResource.h"
#include "ResourceManager/ResourceMap.h"

namespace Seventh
{
    class TiledMap : public RenderingResource
    {
    public:
        TiledMap(std::string packName, std::string mapName);

    private:
        Tmx::Map* tmxMap;
        ResourceMap* resourceMap;
    public:
        virtual bool load();

        virtual void unload();

        virtual void render();
    };

}

#endif