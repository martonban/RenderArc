#ifndef VERTEX_ARRAY_HPP
#define VERTEX_ARRAY_HPP

#include <GL/glew.h>

#include "render_utils/buffers/VertexBuffer.hpp"
#include "render_utils/buffers/VertexBufferLayout.hpp"

class VertexArray {
    public:
        VertexArray();
        ~VertexArray();

        void Bind() const;
        void Unbind() const;
      
        void AddBuffer(const VertexBuffer& vb, const VertexBufferLayout& layout);
    private:
        unsigned int mRendererID;
};

#endif