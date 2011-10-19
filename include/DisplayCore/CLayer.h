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
 * @since		2011.0816
 *
 */

#include <vector>

#ifndef STH_CLAYER_H_
#define STH_CLAYER_H_

namespace Seventh
{
	class CLayer
	{
	public:
		CLayer();
		~CLayer();

		void UpdateGameLogic();
		void Render();

		void CreateOverallTexture(std::string name, std::string filename);
		void RegisterOverallTexture(U32 texture_id);

		void TransformOverallTexture(std::string name, STH_Transform transform);

	private:
		/**
		 * The structure of a layer is simple
		 *
		 * Map: loaded from the map container
		 * Entities: user tells where to locate them
		 * OverallTextures: for effects and such (mist, etc.)
		 *
		 * It must be rendered in this order, to keep
		 * layer strata OK
		 *
		 */
		// contained map layer
		//boost::shared_ptr<CMapLayer> m_MapLayer;

		// contained map of contained entities
		std::map< std::string, U32 > m_Entities;

		// another map of overall textures
		std::map< std::string, U32 > m_OverallTextures;

		// method to render textures, entities and maps
		void RenderOverallTextures();
		void RenderEntities();
		void RenderMap();
	};
}

#endif
