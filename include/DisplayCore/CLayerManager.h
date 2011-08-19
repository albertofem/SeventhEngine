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


#include "DisplayCore/CLayer.h"

#ifndef STH_CLAYERMANAGER_H_
#define STH_CLAYERMANAGER_H_

namespace Seventh
{
	class CLayerManager
	{
	public:
		CLayerManager();
		~CLayerManager();

		void Render();

		U16 createLayer();

		boost::shared_ptr<CLayer> _Layer(U16 layer_id);

	private:
		// layers
		std::map< U16, boost::shared_ptr<CLayer> > m_Layers;

		// num of layers
		U16 m_Total;
	};
}

#endif
