#include "render_utils/buffers/TextureBuffer.hpp"

TextureBuffer::TextureBuffer(const std::string& path) : 
        mFilePath(path), mLocalBuffer(nullptr), mWidth(0), mHeight(0), mBPP(0) {
    
    stbi_set_flip_vertically_on_load(1);
    mLocalBuffer = stbi_load(path.c_str(), &mWidth, &mHeight, &mBPP, 4);

    if(!mLocalBuffer) {
        std::cerr << "GLCore Error: Failed to load texture: " << path
                  << " (" << stbi_failure_reason() << ")" << std::endl;
    }

    glGenTextures(1, &mRenderID);
    glBindTexture(GL_TEXTURE_2D, mRenderID);

    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_CLAMP_TO_EDGE);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_CLAMP_TO_EDGE);

    glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA8, mWidth, mHeight, 0, GL_RGBA, GL_UNSIGNED_BYTE, mLocalBuffer);
    glBindTexture(GL_TEXTURE_2D, 0);

    if(mLocalBuffer) {
        stbi_image_free(mLocalBuffer);
    }
    
}

TextureBuffer::~TextureBuffer() {
    glDeleteTextures(1, &mRenderID);
}

void TextureBuffer::Bind(unsigned int slot) const {
    glActiveTexture(GL_TEXTURE0 + slot);
    glBindTexture(GL_TEXTURE_2D, mRenderID);
}

void TextureBuffer::Unbind() const {
    glBindTexture(GL_TEXTURE_2D, 0);
}
