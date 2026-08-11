#ifndef GL_RENDERER_HPP
#define GL_RENDERER_HPP

#include <vector>

#include "GLCommon.hpp"



class GLRenderer {
    private:
        std::vector<int> mRenderBatches;

    public:
        GLRenderer();
        void AddRenderQueue(const GLCore::DrawableObject& object);
};

#endif