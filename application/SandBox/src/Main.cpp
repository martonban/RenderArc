#include "GLCore.hpp"

int main() {

    Renderer::WindowBaseSetting settings{};

    GLCore::Init(settings);
    GLCore::StartWindow();
    return 0;
}