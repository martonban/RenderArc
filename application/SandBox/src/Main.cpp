#include "GLCore.hpp"

int main() {

    Renderer::WindowBaseSetting settings{};

    GLCore::Init();
    GLCore::StartWindow(settings);
    return 0;
}