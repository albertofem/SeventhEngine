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
 * @since		2011.0819
 *
 */

#include "common.h"

#include "DisplayCore/CTextureManager.h"
#include "DisplayCore/CDisplayCore.h"
#include "DisplayCore/CLayer.h"

namespace Seventh
{
	CLayer::CLayer()
	{
	}

	CLayer::~CLayer()
	{
	}

	void CLayer::CreateOverallTexture(std::string name, std::string filename)
	{
		U32 texture_id = CDisplayCore::_Textures()->CreateTexture(filename);

		m_OverallTextures[name] = texture_id;
	}

	void CLayer::RegisterOverallTexture(U32 texture_id)
	{
	}

	void CLayer::RenderOverallTextures()
	{
		// iterate map of overall textures
		std::map< std::string, U32 >::const_iterator it;

		for(it=m_OverallTextures.begin(); it!=m_OverallTextures.end(); it++)
		{
			CDisplayCore::_Textures()->RenderTexture(m_OverallTextures[it->first]);
		}
	}

	void CLayer::TransformOverallTexture(std::string name, STH_Transform transform)
	{
		//TRACE("Getting transformation on texture ID (%d)", m_OverallTextures[name]);
		CDisplayCore::_Textures()->TransformTexture(m_OverallTextures[name], transform);
	}

	void CLayer::Render()
	{

		// render in order the textures from maps, entities
		// and overall textures
		RenderOverallTextures();
	}
}
