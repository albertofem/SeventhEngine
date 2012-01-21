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

// rendering needed assets
#include "resources.h"
#include "Rendering/GLtexture.h"
#include "Rendering/CTexture.h"
#include "Rendering/CTile.h"

#ifndef STH_CRENDERING_H_
#define STH_CRENDERING_H_

namespace Seventh
{
	struct SResourceLoaded
	{
		U64 resource_id;
		e_ResourceType type;
	};

	class CRendering
	{
	public:
		CRendering();
		~CRendering();

		/**
		 * Public rendering methods
		 * The rendering pipeline offers
		 * a simple way to render something
		 * on the screen without caring about
		 * anything else
		 */
		void RenderTexture(U64 resource_id, U64 pos_x, U64 pos_y);
		void RenderAnimation(U64 resource_id, U64 pos_x, U64 pos_y);
		void RenderMapLayer(U64 resource_id, U64 pos_x, U64 pos_y);
		void RenderTile(U64 resource_id, U64 pos_x, U64 pos_y);

		/**
		 * Same as before, but for hiding
		 * resources in the screen
		 */
		void HideTexture(U64 resource_id);
		void HideAnimation(U64 resource_id);
		void HideMapLayer(U64 resource_id);
		void HideTile(U64 resource_id);

		/**
		 * This generic function is used by the
		 * resource manager, to load in memory
		 * the resource needed. No further action
		 * required, the loaded memory will clean
		 * itself once it's no longer needed
		 */
		U64 ResourceLoad_Texture(s_Texture* texture);
		U64 ResourceLoad_Animation(s_Animation* animation);
		U64 ResourceLoad_Map(s_Map* map);
		U64 ResourceLoad_Tile(s_Tileset* tileset, s_Tile* tile);

	private:
		// loading a tileset should be used only within this class
		U64 ResourceLoad_Tileset(s_Tileset* tileset);

	private:

		/**
		 * Containers, contains all the
		 * data needed by the rendering pipeline
		 * Each class has its internal IDs, because
		 * they are refered to each others constantly
		 * and we need to keep separate IDs in tĥis class
		 */
		std::map< U64, SRenderingResource< CTexture > > m_Textures;
		std::map< U64, SRenderingResource< CTile > > m_Tiles;

		/**
		 * Counters
		 */
		U64 m_CounterTextures;
		U64 m_CounterTiles;

		/**
		 * Resources loaded, keeps a raw list
		 * of resources already loaded
		 */
		std::map < std::string, boost::shared_ptr< GLtexture > > m_TexturesLoaded;
		std::map < s_Tile*, boost::shared_ptr< GLtexture > > m_TilesLoaded;

		/**
		 * Misc. methods
		 */
		boost::shared_ptr< GLtexture > CheckResourceLoaded(std::string filename);

		/**
		 * Rendering collision methods
		 */
		bool CheckTextureCollision(CTexture* top_side, CTexture* down_side);

		void ClearScreen();

		/**
		 * Generic functions
		 *
		 * This generic functions are used to avoid code
		 * duplication in specific parts of the rendering engine
		 */
		template< typename Key >
		void RedrawRenderingResource(std::map< U64, SRenderingResource< Key > >& map);

		template< typename Key >
		void Render(std::map< U64, SRenderingResource< Key > >& map, U64 resource_id, U64 pos_x, U64 pos_y);
	};
}

#endif
