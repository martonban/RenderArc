#include "GLCore.hpp"

void GLCore::Init(const GLRendererSettings& settings) {
    GLInstance::GetInstance().Init(settings.windowWidth, settings.windowHeight);
}

void GLCore::StartWindow() {
    GLInstance::GetInstance().StartWindow();
}