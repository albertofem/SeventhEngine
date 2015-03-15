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

#include "Core/Common.h"
#include "Vector2.h"

#ifndef _RENDERING_RESOURCE_H_
#define _RENDERING_RESOURCE_H_

namespace Seventh
{
	class RenderingResource : public AllocatedObject
	{
	public:
		RenderingResource() : mWidth(0), mHeight(0) {};
		virtual ~RenderingResource() {};

		virtual bool load() = 0;
		virtual void unload() = 0;
		virtual void render() = 0;

		uint getWidth() { return mWidth; };
		uint getHeight() { return mHeight; };

		Vector2 getPosition() { return mPosition; };

		void setPosition(Vector2 position) { mPosition = position; };

		void setPosition(float x, float y) {
			LOG_DEBUG("Translating to position %f - %f", x, y);
			mPosition.x = x; mPosition.y = y;
		};

	protected:
		uint mWidth;
		uint mHeight;

		Vector2 mPosition;
	};
}

#endif