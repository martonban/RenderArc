#include "GLCore.hpp"
#include "GeoCore.hpp"

int main() {

    GLCore::GLWindowSettings windowSettings {};
    
    GLCore::Init(windowSettings);
    GLCore::InitRenderer();



    GeoCore::Quad quad { glm::fvec3{0.0f, 0.0f, 0.0f}, 0.5f, 0.5f };

    VertexBufferLayout layout;
    layout.Push<float>(3);
    
    GLCore::AddBatch(
        quad,
        layout,
        "../../../application/SandBox/assets/materials/shaders/Basics.glsl"
    );


    while (!GLCore::ShouldClose()) {
        GLCore::BeginFrame();
        GLCore::Draw();
        GLCore::EndFrame();
    }

    GLCore::Shutdown();
    return 0;
}