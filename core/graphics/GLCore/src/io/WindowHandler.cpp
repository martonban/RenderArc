#include "io/WindowHandler.hpp"

WindowHandler::WindowHandler(const char* title, const int& windowWidth, const int& windowHeight) {
   
    if(!glfwInit()) {
        std::cerr << "GLFW Error: GLFW initalizing stage has some issues!" << std::endl;
    }

    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE); 

    mWindow = glfwCreateWindow(windowWidth, windowHeight, "Hello World", NULL, NULL);
    if(!mWindow) {
        glfwTerminate();
        std::cerr << "GLFW Error: Having issues in the window creation!" << std::endl;
    }

    glfwMakeContextCurrent(mWindow);

    if(glewInit() != GLEW_OK ) {
        mStatus = false;
        std::cerr << "GLEW Error: GLEW initalizing stage has some issues!" << std::endl;
    } else {
       mStatus = true; 
    }
}

void WindowHandler::AttachRenderer(std::shared_ptr<GLRenderer> renderer) {
    mRenderer = renderer;
}

bool WindowHandler::CheckStatus() {
    return mStatus;
}

bool WindowHandler::ShouldClose() const {
    if(!mWindow) {
        return true;
    }

    return glfwWindowShouldClose(mWindow);
}
