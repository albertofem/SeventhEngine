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
 * @author Alberto Fernández <albertofem@gmail.com>
 */

#include "Player.h"
#include "Rendering/Texture.h"

using Seventh::Texture;

Player::Player()
{
	LOG_DEBUG("Creating player");

	mId = "my_player";

	Texture* texture = new Texture("sample", "ryu");
	setRenderingResource(texture);
}

Player::~Player()
{
}

void Player::update()
{
	uint speed = 1;
	uint currentX = mPosition.x;
	uint currentY = mPosition.y;

	if (GameInput.isKeyPressed(SE_KEY_ARROW_RIGHT)) {
		setPosition(currentX + speed, currentY);
	}

	if (GameInput.isKeyPressed(SE_KEY_ARROW_DOWN)) {
		setPosition(currentX, currentY + speed);
	}

	if (GameInput.isKeyPressed(SE_KEY_ARROW_LEFT)) {
		setPosition(currentX - speed, currentY);
	}

	if (GameInput.isKeyPressed(SE_KEY_ARROW_UP)) {
		setPosition(currentX, currentY - speed);
	}

	if (GameInput.isKeyPressed(SE_KEY_SPACE)) {
		setPosition(0.0f, 0.0f);
	}
}
