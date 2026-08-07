#include "GLCore.hpp"

void GLCore::Init() {
    GLRendererSettings st;
    GLInstance::GetInstance().Init(st.title, st.windowWidth, st.windowHeight, st.windowApi);
}

void GLCore::Init(const GLRendererSettings& settings) {
    GLInstance::GetInstance().Init(settings.title, settings.windowWidth, settings.windowHeight, settings.windowApi);
}

void GLCore::StartWindow() {
    GLInstance::GetInstance().StartWindow();
}