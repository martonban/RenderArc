#ifndef TEXTURE_BUFFER_HPP
#define TEXTURE_BUFFER_HPP

#include <iostream>
#include <string>

#include <GL/glew.h>
#include "render_utils/texture/stb_image.h"

class TextureBuffer {
    private:
        unsigned int mRenderID;
        std::string mFilePath;
        unsigned char* mLocalBuffer;
        int mWidth, mHeight, mBPP;
    public:
        TextureBuffer(const std::string& path);
        ~TextureBuffer();

        void Bind(unsigned int slot = 0) const;
        void Unbind() const;

        inline int GetWidth() const { return mWidth; }
        inline int GetHeight() const { return mHeight; }

};

#endif