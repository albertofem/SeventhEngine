/**
 *
 * SeventhEngine, an SDL-based general-purpose
 * game engine. Made for learning purposes
 *
 * Licensed under GNU General Public License v3
 * <http://www.gnu.org/licenses/gpl.html>
 *
 * @author	Alberto Fernández <albertofem@gmail.com>
 * @version	1.0
 * @since		2011.1026
 *
 */

#include <map>
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
	};

	struct s_Tileset
	{
		std::string src;
		std::string format;

		// map with contained tiled
		std::map< std::string, boost::shared_ptr<s_Tile> > tiles;
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
		std::vector< boost::shared_ptr<s_AnimationTile> > tile_frames;
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
		ENTITY_ASSET_TEXTURE = 0x0,
		ENTITY_ASSET_ANIMATION,
		ENTITY_ASSET_TILE
	};
}

#endif
