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
 * @since		2011.0816
 *
 */

#ifndef STH_CASSETMANAGER_H_
#define STH_CASSETMANAGER_H_

namespace Seventh
{
	class CAssetManager
	{
	public:
		CAssetManager();
		~CAssetManager();

		STH_BOOL GetTexture(std:string);
		STH_BOOL GetMap(std::string);

	private:

	};
}

#endif
