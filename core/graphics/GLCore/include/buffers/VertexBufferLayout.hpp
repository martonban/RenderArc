#ifndef VERTEX_BUFFER_LAYOUT_HPP
#define VERTEX_BUFFER_LAYOUT_HPP

#include <vector>
#include <type_traits>
#include <GL/glew.h>


struct VertexBufferElement {
    unsigned int type;
    unsigned int count;
    unsigned char normalized;

    static unsigned int GetSizeOfType(unsigned int type) {
        switch (type) {
            case GL_FLOAT: return 4;
            case GL_UNSIGNED_INT: return 4;
            case GL_UNSIGNED_BYTE: return 1;
        }
        return 0;
    }
};

class VertexBufferLayout {
    private:
        std::vector<VertexBufferElement> mElements;
        unsigned int mStride;

    public:
        VertexBufferLayout()
            : mStride(0) {}

        template<typename T>
        void Push(unsigned int count) {
            if constexpr(std::is_same_v<T, float>) {
                mElements.push_back(VertexBufferElement{GL_FLOAT, count, GL_FALSE});
                mStride += VertexBufferElement::GetSizeOfType(GL_FLOAT) *  count;
            } else if constexpr(std::is_same_v<T, unsigned int>) {
                mElements.push_back(VertexBufferElement{GL_UNSIGNED_INT, count, GL_FALSE});
                mStride += VertexBufferElement::GetSizeOfType(GL_UNSIGNED_INT)  *  count;
            } else if constexpr(std::is_same_v<T, unsigned char>) {
                mElements.push_back(VertexBufferElement{GL_UNSIGNED_BYTE, count, GL_TRUE});
                mStride += VertexBufferElement::GetSizeOfType(GL_UNSIGNED_BYTE)  *  count;
            } else {
                static_assert(false, "Unsupported type for VertexBufferLayout::Push");
            }
        }

        inline const std::vector<VertexBufferElement>& GetElements() const { return mElements; }
        inline unsigned int GetStride() const { return mStride; }


};

#endif