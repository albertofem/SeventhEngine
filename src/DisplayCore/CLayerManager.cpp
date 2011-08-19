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

#include "common.h"
#include "DisplayCore/CLayerManager.h"

namespace Seventh
{
	CLayerManager::CLayerManager()
		: m_Total(0)
	{
		// do nothing
	}

	CLayerManager::~CLayerManager()
	{
		// do nothing
	}

	void CLayerManager::Render()
	{
		RenderMapContainer(m_Layers);
	}

	U16 CLayerManager::createLayer()
	{
		LAYER temp(new CLayer);

		U16 tempID = m_Total;

		m_Layers[m_Total] = temp;

		m_Total++;

		return tempID;
	}

	boost::shared_ptr<CLayer> CLayerManager::_Layer(U16 layer_id)
	{
		return m_Layers[layer_id];
	}
}
