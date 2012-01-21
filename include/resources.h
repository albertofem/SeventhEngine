/**
 * SeventhEngine, an SDL-based general-purpose
 * game engine. Made for learning purposes
 *
 * Copyright (C) 2011 Alberto Fernández
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
 * @version	0.1
 *
 */

#include "common.h"

#include <vector>

#ifndef STH_RESOURCES_H_
#define STH_RESOURCES_H_

namespace Seventh
{
	struct s_Texture
	{
		std::string src;
		std::string format;
	};

	struct s_Tile
	{
		U16 posx, posy;
		U16 width, height;

		s_Tile(U16 x, U16 y, U16 w, U16 h)
			: posx(x), posy(y), width(w), height(h)
		{
		}

		s_Tile()
		{
		}
	};

	struct s_Tileset
	{
		std::string src;
		std::string format;

		// map with contained tiled
		std::map< std::string, s_Tile > tiles;
	};

	enum e_AnimationType
	{
		ANIM_TEXTURE = 0,
		ANIM_TILE
	};

	struct s_AnimationTile
	{
		std::string tileset;
		std::string tile;
	};

	struct s_Animation
	{
		e_AnimationType type;
		U16 frame_rate;

		// vector containing the frames of the animation
		// when the type is a texture animation
		std::vector< std::string > texture_frames;

		// vector containing the frames of the animation
		// when the type is a tile animation
		std::vector< s_AnimationTile > tile_frames;
	};

	typedef s_Texture s_Map;

	enum e_ResourceType
	{
		TEXTURE = 0x0,
		TILESET,
		ANIMATION,
		MAP
	};

	enum e_EntityAsset
	{
		ENTITY_ASSET_NONE = 0x0,
		ENTITY_ASSET_TEXTURE,
		ENTITY_ASSET_ANIMATION,
		ENTITY_ASSET_TILE
	};

	/**
	 * Generic resource struct
	 */
	template< typename R >
	struct SRenderingResource
	{
		boost::shared_ptr< R > resource;
		U32 refcount;

		SRenderingResource()
			: refcount(0)
		{
		}
	};

	enum e_TextureFormat
	{
		TEXTURE_NORMAL,
		TEXTURE_TILE
	};
}

#endif
