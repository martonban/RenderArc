#include "GLCore.hpp"

void GLCore::Init() {
    GLWindowSettings st;
    GLInstance::GetInstance().Init(st.title, st.windowWidth, st.windowHeight, st.windowApi);
}

void GLCore::Init(const GLWindowSettings& settings) {
    GLInstance::GetInstance().Init(settings.title, settings.windowWidth, settings.windowHeight, settings.windowApi);
}

void GLCore::InitRenderer() {
    GLInstance::GetInstance().InitRenderer();
}


bool GLCore::ShouldClose() {
    return GLInstance::GetInstance().ShouldClose();
}

void GLCore::BeginFrame() {
    GLInstance::GetInstance().BeginFrame();
}

void GLCore::EndFrame() {
    GLInstance::GetInstance().EndFrame();
}   

void GLCore::Shutdown() {
    GLInstance::GetInstance().Destroy();
}

void GLCore::AddBatch(const GeoCore::Quad& quad, const VertexBufferLayout& layout, const std::string& shaderFilePath, const std::string& textureFilePath) {
    GLInstance::GetInstance().AddBatch(quad, layout, shaderFilePath, textureFilePath);
}

void GLCore::Draw() {
    GLInstance::GetInstance().Draw();
}