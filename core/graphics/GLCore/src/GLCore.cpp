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


void GLCore::TestUpload() {
    GLInstance::GetInstance().TestUpload();
}

void GLCore::TestDrawCall() {
    GLInstance::GetInstance().TestDrawCall();
}