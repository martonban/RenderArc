#include "instance/GLInstance.hpp"

void GLInstance::Init(const char* title, const int& windowWidth, const int& windowHeight, const WindowAPI& api) {
    mStatus = GL_CORE_INITIALIZED;
    mWindowSys = std::make_unique<WindowHandler>(title, windowWidth, windowHeight);
    
    if(mWindowSys->CheckStatus()) {
        mStatus = GL_CORE_WINDOWING_SYS_INITIALIZED;
    }
}

void GLInstance::InitRenderer() {
    if(mStatus < GL_CORE_WINDOWING_SYS_INITIALIZED) {
        std::cerr << "GLCore Error: The windowing system is not ready for the rendering process. Tip: Please check your codebase and ensure that GLCore::Init() or GLCore::Init(const GLWindowSettings& settings) are called." << std::endl;
    }

    mRenderer = std::make_shared<GLRenderer>();
    mStatus = GL_CORE_RENDERING_SYS_INITIALIZED;

    mWindowSys->AttachRenderer(mRenderer);
    mStatus = GL_CORE_RENDERER_ATTACHED_TO_WINDOW; 

}

bool GLInstance::ShouldClose() const {
    if(mStatus < GL_CORE_WINDOWING_SYS_INITIALIZED) {
        std::cerr << "GLCore Error: There is no window to query. Tip: Please check your codebase and ensure that GLCore::Init() or GLCore::Init(const GLWindowSettings& settings) are called." << std::endl;
        return true;
    }

    return mWindowSys->ShouldClose();
}

void GLInstance::BeginFrame() {
     glClear(GL_COLOR_BUFFER_BIT);
}

void GLInstance::EndFrame() {
    glfwSwapBuffers(mWindowSys->GetWindow());
    glfwPollEvents();
}

void GLInstance::Destroy() {
    glfwTerminate();
}


void GLInstance::TestUpload() {

    float position[] = {
        -0.5f, -0.5f,
         0.5f, -0.5f,
         0.5f,  0.5f,
        -0.5f,  0.5f
    };

    unsigned int indeces[] = {
        0, 1, 2,
        2, 3, 0
    };


    glClearColor(0.1f, 0.1f, 0.1f, 1.0f);

    mTestVA = std::make_unique<VertexArray>();

    mTestVB = std::make_unique<VertexBuffer>(position, 4 * 2 * sizeof(float));

    VertexBufferLayout layout;
    layout.Push<float>(2);
    mTestVA->AddBuffer(*mTestVB, layout);

    mTestIB = std::make_unique<IndexBuffer>(indeces, 6);

    mTestShader = std::make_unique<Shader>("../../../application/SandBox/assets/Basics.glsl");
    mTestShader->Bind();
    mTestShader->SetUniform4f("u_Color", 0.2f, 0.3f, 0.8f, 1.0f);

    mTestVA->Unbind();
    mTestShader->Unbind();
    mTestVB->Unbind();
    mTestIB->Unbind();
}


void GLInstance::TestDrawCall() {
    mTestShader->Bind();

    mTestVA->Bind();
    mTestIB->Bind();

    glDrawElements(GL_TRIANGLES, 6, GL_UNSIGNED_INT, nullptr);
}


void GLInstance::GLClearError() {
    while (glGetError() != GL_NO_ERROR);
}

bool GLInstance::GLLogCall(const char* fuction, const char* file, int line) {
    while(GLenum error = glGetError()) {
        std::cout << "[OpenGL Error] (" << error << "): " << fuction << 
         " " << file << ":" << line << std::endl;
        return false;
    }

    return true;
}