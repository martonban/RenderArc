#include "GLCore.hpp"

int main() {

    GLRendererSettings settings{};

    GLCore::Init(settings);
    GLCore::StartWindow();
    return 0;
}