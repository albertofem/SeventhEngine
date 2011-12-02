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
 * @since		2011.1202
 *
 */

#include "common.h"

#include "DisplayCore/CTexture.h"

#ifndef STH_CRENDERING_H_
#define STH_CRENDERING_H_

namespace Seventh
{
	template< typename R >
	struct s_RenderingResource
	{
		T* resource;
		U32 refcount;
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
		 * This generic function is used by the
		 * resource manager, to load in memory
		 * the resource needed. No further action
		 * requeride, the loaded memory will clean
		 * itself once it's no longer needed
		 */
		U64 ResourceLoad_Texture(s_Texture texture);
		U64 ResourceLoad_Animation(s_Animation animation);
		U64 ResourceLoad_Map(s_Map map);
		U64 ResourceLoad_Tileset(s_Tileset tileset);
		U64 ResourceLoad_Tile(s_Tileset tileset, s_Tile tile);

	private:
		/**
		 * Containers, contains all the
		 * data needed by the rendering pipeline
		 * Each class has its internal IDs, because
		 * they are refered to each others constantly
		 * and we need to keep separate IDs in tĥis class
		 */
		std::map < U64, s_RenderingResource< CTexture > > m_Textures;
		//std::map < U64, CTile* > m_Tiles;
		//std::map < U64, CAnimation* > m_Animations;
		//std::map < U64, CTileset* > m_Tilesets;
		//std::map < U64, CMapLayer* > m_MapLayers;

		/**
		 * Loaders, functions to be called internally
		 * that get the job of loading textures and
		 * managing resources efficiently
		 */
		U64 CreateTexture(s_Texture texture);
		U64 CreateAnimation(s_Animation animation);
		U64 CreateMapLayer(s_Map map, U8 layer);
		U64 CreateTile(s_Tileset tileset, s_Tile tile);
		U64 CreateTileset(s_Tileset tileset);

		/**
		 * Destructors for the previous functions
		 */
		void DestroyTexture();
		void DestroyAnimation();
		void DestroyMapLayer();
		void DestroyTile();
		void DestroyTileset();

		/**
		 * Resources loaded, keeps a raw list
		 * of resources already loaded
		 */
		std::map < std::string, U64 > m_ResourcesLoaded;
	}
}

#endif
