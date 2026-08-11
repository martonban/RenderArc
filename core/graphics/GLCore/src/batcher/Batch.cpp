#include "batcher/Batch.hpp"

Batch::Batch(const GeoCore::Quad& quad, const VertexBufferLayout& layout, const std::string& filePath) {
    
    mVAO = std::make_unique<VertexArray>();
    
    mVBO = std::make_unique<VertexBuffer>(quad.vertices.data(), quad.vertices.size() * sizeof(glm::fvec3));

    mVAO->AddBuffer(*mVBO, layout);

    mIBO = std::make_unique<IndexBuffer>(quad.indices.data(), quad.indices.size());

    
    mShader = std::make_unique<Shader>(filePath);
    mShader->Bind();
    mShader->SetUniform4f("u_Color", 0.2f, 0.3f, 0.8f, 1.0f);

    mVAO->Unbind();
    mShader->Unbind();
    mVBO->Unbind();
    mIBO->Unbind();

}
        
void Batch::Bind() const {
    mVAO->Bind();
    mShader->Bind();
    mVBO->Bind();
    mIBO->Bind();
}

void Batch::Unbind() const {
    mVAO->Unbind();
    mShader->Unbind();
    mVBO->Unbind();
    mIBO->Unbind();
}