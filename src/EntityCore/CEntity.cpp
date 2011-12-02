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
#include "DisplayCore/CTextureManager.h"

namespace Seventh
{
	CEntity::CEntity()
		: m_CurrentAsset(ENTITY_ASSET_NONE)
	{
		m_Position.pos_x = 0;
		m_Position.pos_y = 0;

		m_Show = true;
		m_ResourceID = 0;
	}

	CEntity::CEntity(STH_Position& initial_position)
		: m_CurrentAsset(ENTITY_ASSET_NONE)
	{
		m_Position.pos_x = initial_position.pos_x;
		m_Position.pos_y = initial_position.pos_y;

		m_Show = true;
		m_ResourceID = 0;
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
		// hide entity if we've got another one already loaded
		if(m_ResourceID != 0)
			Hide();

		m_CurrentAsset = ENTITY_ASSET_TEXTURE;
		m_CurrentResourceName = name;

		// look for this texture name
		// load the texture in memory
		// we can handle the rendering in the Render() method
		m_ResourceID = CEngine::_Resources()->LoadTexture(name, m_ResourceID);

		// show again
		Show();
	}

	void CEntity::SetTile(std::string tileset, std::string tile)
	{
		if(m_ResourceID != -1)
			Hide();

		m_CurrentAsset = ENTITY_ASSET_TILE;
		m_CurrentResourceName = tileset;

		m_ResourceID = CEngine::_Resources()->LoadTile(tileset, tile);
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

	void CEntity::UpdateGameLogic()
	{
		if(m_Show == false)
			return;

		if(m_CurrentAsset == ENTITY_ASSET_TEXTURE)
		{
			// render texture
			CDisplayCore::_Textures()->RenderTexture(m_ResourceID, m_Position.pos_x, m_Position.pos_y);
		}
		else if(m_CurrentAsset == ENTITY_ASSET_TILE)
		{
			// render tile
			CDisplayCore::_Textures()->RenderTexture(m_ResourceID, m_Position.pos_x, m_Position.pos_y);
		}
		else if(m_CurrentAsset == ENTITY_ASSET_ANIMATION)
		{
			// render animation
		}
	}

	void CEntity::Hide()
	{
		if(m_Show != true)
			return;

		CDisplayCore::_Textures()->HideTexture(m_ResourceID);

		m_Show = false;
	}

	void CEntity::Show()
	{
		if(m_ResourceID == 0)
		{
			if(m_CurrentAsset == ENTITY_ASSET_TEXTURE)
				SetTexture(m_CurrentResourceName);
		}

		m_Show = true;
	}
}
