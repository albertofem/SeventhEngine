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
#include "Engine/CEngine.h"
#include "DisplayCore/CLayerManager.h"
#include "DisplayCore/CTextureManager.h"
#include "DisplayCore/CDisplayCore.h"
#include "DisplayCore/CLayer.h"

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

		// render overall textures
		RenderOverallTextures();
	}

	U16 CLayerManager::CreateLayer()
	{
		LAYER temp(new CLayer);

		U16 tempID = m_Total;

		m_Layers[m_Total] = temp;

		m_Total++;

		return tempID;
	}

	void CLayerManager::RegisterOverallTexture(std::string name, std::string filename)
	{
		U32 texture_id = CDisplayCore::_Textures()->CreateTexture(filename);

		m_OverallTextures[name] = texture_id;
	}

	void CLayerManager::RenderOverallTextures()
	{
		// iterate map of overall textures
		std::map< std::string, U32 >::const_iterator it;

		for(it=m_OverallTextures.begin(); it!=m_OverallTextures.end(); it++)
		{
			CDisplayCore::_Textures()->RenderTexture(m_OverallTextures[it->first]);
		}
	}

	void CLayerManager::TransformOverallTexture(std::string name, STH_Transform transform)
	{
		//TRACE("Getting transformation on texture ID (%d)", m_OverallTextures[name]);
		CDisplayCore::_Textures()->TransformTexture(m_OverallTextures[name], transform);
	}
}
