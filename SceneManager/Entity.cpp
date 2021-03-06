/*
 * SeventhEngine
 *
 * Copyright (c) Alberto Fernández
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
 */

#include "Entity.h"
#include "Rendering/Rendering.h"
#include "SceneManager/SceneManager.h"

namespace Seventh
{
	Entity::Entity()
	{
	}


	Entity::~Entity()
	{
	}

	void Entity::setPosition(Vector2 position)
	{
		mPosition = position;

		if (mRenderingResource) {
			mRenderingResource->setPosition(position);
		}
	}

	void Entity::setPosition(float x, float y)
	{
		mPosition.x = x;
		mPosition.y = y;

		if (mRenderingResource) {
			mRenderingResource->setPosition(x, y);
		}
	}

	std::string Entity::getId()
	{
		return mId;
	}

	void Entity::hide()
	{
		GRenderingEngine.removeRenderingResource(mRenderingResource);
	}

	void Entity::show()
	{
		GRenderingEngine.addRenderingResource(mRenderingResource);
	}
}