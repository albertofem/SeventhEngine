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
 * @since		2011.1104
 *
 */

#include "DisplayCore/CDisplayCore.h"
#include "EntityCore/CEntity.h"

namespace Seventh
{
	CEntity::CEntity()
	{
		m_Position.pos_x = 0;
		m_Position.pos_y = 0;
	}

	CEntity::CEntity(STH_Position& initial_position)
	{
		m_Position.pos_x = initial_position.pos_x;
		m_Position.pos_y = initial_position.pos_y;
	}

	CEntity::~CEntity()
	{
	}

	void CEntity::SetAnimation(std::string animation_name)
	{
		//TRACE("Animation in top CEntity");
	}

	void CEntity::SetTexture(std::string name)
	{
		m_CurrentAsset = ENTITY_ASSET_TEXTURE;

		// look for this texture name
		// load the texture in memory
		// we can handle the rendering in the Render() method
	}
}
