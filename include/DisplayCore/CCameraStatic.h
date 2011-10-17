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

#include "DisplayCore/CCamera.h"

#ifndef STH_CCAMERASTATIC_H_
#define STH_CCAMERASTATIC_H_

namespace Seventh
{
	class CCameraStatic : public CCamera
	{
	public:
		CCameraStatic();
		~CCameraStatic();

		U32 GetOffset_X() { return 0; }
		U32 GetOffset_Y() { return 0; }
	};
}

#endif
