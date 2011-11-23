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

#include "DisplayCore/CCamera.h"

namespace Seventh
{
	U16 CCamera::s_TotalCameras = 0;

	CCamera::CCamera()
	{
		s_TotalCameras++;
	}

	CCamera::~CCamera()
	{
		// do nothing
	}

	U32 CCamera::GetOffset_X()
	{
		return 0;
	}

	U32 CCamera::GetOffset_Y()
	{
		return 0;
	}

	U16 CCamera::GetCamera_ID()
	{
		return m_CameraID;
	}

	e_CameraType CCamera::GetCameraType()
	{
		return m_CameraType;
	}
}
