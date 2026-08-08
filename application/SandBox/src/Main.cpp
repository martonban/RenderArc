#include "GLCore.hpp"

int main() {

    GLWindowSettings windowSettings {};
    
    GLCore::Init(windowSettings);
    GLCore::InitRenderer();
    
    GLCore::TestUpload();

    while (!GLCore::ShouldClose()) {
        GLCore::BeginFrame();

        GLCore::TestDrawCall();
        GLCore::EndFrame();
    }

    GLCore::Shutdown();
    return 0;
}