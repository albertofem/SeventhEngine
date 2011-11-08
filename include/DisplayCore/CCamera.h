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
 * @since		2011.1015
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
