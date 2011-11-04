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

#include <string>

#include "common.h"

#include "Engine/CEngine.h"

#ifndef STH_CENTITY_H_
#define STH_CENTITY_H_

namespace Seventh
{
	class CEntity
	{
	public:
		CEntity();
		virtual ~CEntity();

	private:
		void SetAnimation(std::string animation_name);
		void SetTexture(std::string animation_name);

		U8 m_CurrentRenderingResource;

		CEngine* m_Engine;

		void Render();

	};
}

#endif
