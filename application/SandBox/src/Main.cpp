#include "GLCore.hpp"
#include "GeoCore.hpp"

int main() {

    GLCore::GLWindowSettings windowSettings {};
    
    GLCore::Init(windowSettings);
    GLCore::InitRenderer();

    // Projection Matrix 
    glm::mat4 proj = glm::ortho(-2.0f, 2.0f, -1.5f, 1.5f, -1.0f, 1.0f);

    GeoCore::Quad quad { glm::fvec3{0.0f, 0.0f, 0.0f}, 0.5f, 0.5f };

    VertexBufferLayout layout;
    layout.Push<float>(3);
    layout.Push<float>(2);

    // Shader
    std::shared_ptr<Shader> shader = std::make_shared<Shader>("../../../application/SandBox/assets/materials/shaders/Basics.glsl");

    GLCore::AddBatch(
        quad,
        layout,
        shader,
        "../../../application/SandBox/assets/textures/texture.png"
    );

    shader->Bind();
    shader->SetUniform4m("u_MVP", proj);
    shader->Unbind();


    while (!GLCore::ShouldClose()) {
        GLCore::BeginFrame();
        GLCore::Draw();
        GLCore::EndFrame();
    }

    GLCore::Shutdown();
    return 0;
}