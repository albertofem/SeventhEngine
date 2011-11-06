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

#ifndef STH_CLAYERMANAGER_H_
#define STH_CLAYERMANAGER_H_

namespace Seventh
{
	class CLayer;
	class CEntity;
	class CMap;

	class CLayerManager
	{
	public:
		CLayerManager();
		~CLayerManager();

		void Render();

		/**
		 * deprecated
		 */
		U16 CreateLayer();

		boost::shared_ptr<CLayer> _Layer(U16 layer_id);

		void RegisterOverallTexture(std::string name, std::string filename);
		void TransformOverallTexture(std::string name, STH_Transform transform);

	private:
		// layers
		std::map< U16, boost::shared_ptr<CLayer> > m_Layers;

		// overall entities
		std::map< U16, CEntity* > m_OverallEntities;

		std::map< std::string, U32 > m_OverallTextures;

		// current map
		CMap* m_CurrentMap;

		// num of layers
		U16 m_Total;

		void RenderOverallTextures();
	};
}

#endif
