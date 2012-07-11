
/*
 *
 * SeventhEngine, an SDL-based general-purpose
 * game engine. Made for learning purposes
 *
 * Licensed under GNU General Public License v3
 * <http://www.gnu.org/licenses/gpl.html>
 *
 * @author	Alberto Fernández <albertofem@gmail.com>
 * @version	1.0
 * @since		2011.1025
 *
 */

#include "common.h"

#ifndef STH_MAPCOMPILER_H_
#define STH_MAPCOMPILER_H_

namespace Seventh
{
	class CMapCompiler
	{
	public:
		CMapCompiler();
		~CMapCompiler();

		CMap* CompileMap(std::string map_source);

	private:
		std::string m_MapSource;
	};
}

#endif
