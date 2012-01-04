/**
 * SeventhEngine, an SDL-based general-purpose
 * game engine. Made for learning purposes
 *
 * Copyright (C) 2011 Alberto Fernández
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 *
 * @author	Alberto Fernández <albertofem@gmail.com>
 * @version	0.1
 *
 */

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
			Clear();

		m_CurrentAsset = ENTITY_ASSET_TEXTURE;
		m_CurrentResourceName = name;

		// look for this texture name
		// load the texture in memory
		// we can handle the rendering in the Render() method
		m_ResourceID = CEngine::_Resources()->LoadTexture(name);
	}

	void CEntity::SetTile(std::string tileset, std::string tile)
	{
		if(m_ResourceID != -1)
			Hide();

		m_CurrentAsset = ENTITY_ASSET_TILE;
		m_CurrentResourceName = tileset;

		m_ResourceID = CEngine::_Resources()->LoadTile(tileset, tile);

		m_Show = true;
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
			CDisplayCore::_Render().RenderTexture(m_ResourceID, m_Position.pos_x, m_Position.pos_y);
		}
		else if(m_CurrentAsset == ENTITY_ASSET_TILE)
		{
			// render tile
			//CDisplayCore::_Render().RenderTile(m_ResourceID, m_Position.pos_x, m_Position.pos_y);
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

		Clear();

		m_Show = false;
	}

	void CEntity::Clear()
	{
		if(m_CurrentAsset == ENTITY_ASSET_TEXTURE)
			CDisplayCore::_Render().HideTexture(m_ResourceID);
	}

	void CEntity::Show()
	{
		m_Show = true;
	}
}
