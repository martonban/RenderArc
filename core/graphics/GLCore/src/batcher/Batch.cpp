#include "batcher/Batch.hpp"

Batch::Batch(const GeoCore::Quad& quad, const VertexBufferLayout& layout, std::shared_ptr<Shader> shader, const std::string& textureFilePath) {
    
    glEnable(GL_BLEND);
    glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
    
    
    mVAO = std::make_unique<VertexArray>();
    
    mVBO = std::make_unique<VertexBuffer>(quad.vertices.data(), quad.vertices.size() * sizeof(GeoCore::Vertex));

    mVAO->AddBuffer(*mVBO, layout);

    mIBO = std::make_unique<IndexBuffer>(quad.indices.data(), quad.indices.size());

    
    mShader = shader;
    mShader->Bind();
    mShader->SetUniform4f("u_Color", 0.2f, 0.3f, 0.8f, 1.0f);

    mTexture = std::make_unique<TextureBuffer>(textureFilePath);
    mTexture->Bind();
    
    mShader->SetUniform1i("u_Texture", 0);

    mVAO->Unbind();
    mShader->Unbind();
    mVBO->Unbind();
    mIBO->Unbind();

}
        
void Batch::Bind() const {
    mVAO->Bind();
    mShader->Bind();
    mTexture->Bind(0);
    mVBO->Bind();
    mIBO->Bind();
}

void Batch::Unbind() const {
    mVAO->Unbind();
    mShader->Unbind();
    mVBO->Unbind();
    mIBO->Unbind();
}