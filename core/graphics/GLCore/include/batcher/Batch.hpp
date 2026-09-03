#ifndef BATCH_HPP
#define BATCH_HPP

#include <memory>

#include "GeoCore.hpp"

#include "render_utils/buffers/VertexBuffer.hpp"
#include "render_utils/buffers/IndexBuffer.hpp"
#include "render_utils/buffers/VertexArray.hpp"
#include "render_utils/buffers/TextureBuffer.hpp"

#include "render_utils/shader/Shader.hpp"

class Batch {
    private:
        std::unique_ptr<VertexArray> mVAO;
        std::unique_ptr<VertexBuffer> mVBO;
        std::unique_ptr<IndexBuffer> mIBO;
        std::unique_ptr<TextureBuffer> mTexture;
        std::shared_ptr<Shader> mShader;
    public:
        Batch(const GeoCore::Quad& quad, const VertexBufferLayout& layout, std::shared_ptr<Shader> shader, const std::string& textureFilePath);
        
        void Bind() const;
        void Unbind() const;

        inline unsigned int GetIndexCount() const { return mIBO->GetCount(); }
};

#endif