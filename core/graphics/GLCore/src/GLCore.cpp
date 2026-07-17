#include "GLCore.hpp"

void GLCore::Init() {
    GLInstance::GetInstance().Init();
}

void GLCore::StartWindow(const Renderer::WindowBaseSetting& settings) {
    GLInstance::GetInstance().StartWindow(settings.windowWidth, settings.windowHeight);
}