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

namespace Seventh
{
	class CCameraAttached : public CCamera
	{
	public:
		CCameraAttached();
		~CCameraAttached();

		void SetOffset_X();
		void SetOffset_Y();

		U32 GetOffset_X();
		U32 GetOffset_Y();

	private:
		CEntity* m_CurrentEntity;

	};
}
