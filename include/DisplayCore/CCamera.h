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

#include "common.h"

#ifndef STH_CCAMERA_H_
#define STH_CCAMERA_H_

namespace Seventh
{
	class CCamera
	{
	public:
		e_CameraType GetCameraType();

		CCamera();
		virtual ~CCamera() = 0;

	protected:
		virtual U32 GetOffset_X();
		virtual U32 GetOffset_Y();

		U16 GetCamera_ID();

	private:
		static U16 s_TotalCameras;

	protected:
		static U16 GetTotalCameras() { return s_TotalCameras; }

	private:
		U32 m_Offset_X;
		U32 m_Offset_Y;

		U16 m_CameraID;

		e_CameraType m_CameraType;

		friend class CDisplayCore;
	};
}

#endif
