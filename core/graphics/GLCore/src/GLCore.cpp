#include "GLCore.hpp"

void GLCore::Init(const Renderer::WindowBaseSetting& settings) {
    GLInstance::GetInstance().Init(settings.windowWidth, settings.windowHeight);
}

void GLCore::StartWindow() {
    GLInstance::GetInstance().StartWindow();
}