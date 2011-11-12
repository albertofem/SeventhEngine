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

#include "Engine/CEngine.h"
#include "DisplayCore/CDisplayCore.h"
#include "EntityCore/CEntity.h"

namespace Seventh
{
	CEntity::CEntity()
		: m_CurrentAsset(ENTITY_ASSET_NONE)
	{
		m_Position.pos_x = 0;
		m_Position.pos_y = 0;

		m_Show = true;
		m_EntityTextureName = "";
	}

	CEntity::CEntity(STH_Position& initial_position)
		: m_CurrentAsset(ENTITY_ASSET_NONE)
	{
		m_Position.pos_x = initial_position.pos_x;
		m_Position.pos_y = initial_position.pos_y;

		m_Show = true;
		m_EntityTextureName = "";
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

		// hide entity if we've got another one already loaded
		if(m_EntityTextureName != "")
			Hide();

		// look for this texture name
		// load the texture in memory
		// we can handle the rendering in the Render() method
		CEngine::_Resources()->LoadTexture(name);
		m_EntityTextureName = name;

		// show again
		Show();
	}

	void CEntity::MoveToPosition(STH_Position& new_position)
	{
		m_Position.pos_x = new_position.pos_x;
		m_Position.pos_y = new_position.pos_y;
	}

	void CEntity::Move(STH_Transform& transform)
	{
		m_Position.pos_x += transform.move_x;
		m_Position.pos_y += transform.move_y;
	}

	void CEntity::Render()
	{
		if(m_Show == false)
			return;

		if(m_CurrentAsset == ENTITY_ASSET_TEXTURE)
		{
			// render texture
			CEngine::_Resources()->RenderTexture(m_EntityTextureName, m_Position.pos_x, m_Position.pos_y);
		}
		else if(m_CurrentAsset == ENTITY_ASSET_ANIMATION)
		{
			// render animation
		}
	}

	void CEntity::Hide()
	{
		CEngine::_Resources()->HideTexture(m_EntityTextureName);

		m_Show = false;
	}

	void CEntity::Show()
	{
		m_Show = true;
	}
}
