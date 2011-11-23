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

#include "common.h"

#ifndef STH_CTEXTURE_H_
#define STH_CTEXTURE_H_

namespace Seventh
{

    enum e_TextureType
    {
        TEXTURE_NORMAL = 0x0,
        TEXTURE_TILE
    };

    class CTexture
    {
    public:
        CTexture();
        CTexture(std::string filename);
        CTexture(const CTexture& lhs);
        CTexture& operator=(const CTexture& lhs);

        CTexture(std::string filename, U16 x, U16 y, U16 w, U16 h);

        ~CTexture();

        void UpdateGameLogic();
        void Render();

        GLuint GetTexture();

        bool LoadSurfaceMemory();

    private:
        std::string m_ResourceFile;

        bool m_Draw;
        bool m_ResourceLoaded;

        GLuint m_Texture;
        SDL_Rect SDL_Coords;

        void Position(S32 pos_x, S32 pos_y);

        static U64 m_TextureCounter;
        U64 m_TextureID;

        SDL_Rect Tile_Coords;
        e_TextureType m_TextureType;

        void ExtractTile(SDL_Surface* sfc_origin);

    public:
        inline std::string GetSourceFile()
        {
            return m_ResourceFile;
        }

        // getters
        inline bool needToDraw()
        {
            return m_Draw;
        }

        inline SDL_Rect getSDLRect()
        {
            return SDL_Coords;
        }

    public:
        inline void SetDraw(bool set)
        {
            m_Draw = set;
        }

        inline U32 GetWidth()
        {
            return SDL_Coords.w;
        }

        inline U32 GetHeight()
        {
            return SDL_Coords.h;
        }

    friend class CTextureManager;
    };
}

#endif
