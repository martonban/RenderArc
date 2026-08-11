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
    
    glClearColor(0.1f, 0.1f, 0.1f, 1.0f);
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

void GLInstance::AddBatch(const GeoCore::Quad& quad, const VertexBufferLayout& layout, const std::string& filePath) {
    mBatches.emplace_back(quad, layout, filePath);
}

void GLInstance::Draw() {
    for(const auto& batch: mBatches) {
        batch.Bind();
        glDrawElements(GL_TRIANGLES, batch.GetIndexCount(), GL_UNSIGNED_INT, nullptr);
        batch.Unbind();
    }
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