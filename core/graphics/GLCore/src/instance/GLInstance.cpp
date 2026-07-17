#include "instance/GLInstance.hpp"

void GLInstance::Init() {
    if(!glfwInit()) {
        std::cerr << "GLFW Error: GLFW initalizing stage has some issues" << std::endl;
    }

    glewInit();
}


void GLInstance::StartWindow(const int& windowWidth, const int& windowHeight) {
    window = glfwCreateWindow(windowWidth, windowHeight, "Hello World", NULL, NULL);
    if(!window) {
        glfwTerminate();
        std::cerr << "GLFW Error: Having issues in the window creation!" << std::endl;
    }

    glfwMakeContextCurrent(window);

    glClearColor(0.1f, 0.1f, 0.1f, 1.0f);

    while(!glfwWindowShouldClose(window)) {
        glClear(GL_COLOR_BUFFER_BIT);
        
        glfwSwapBuffers(window);
        glfwPollEvents();
    }

    glfwTerminate();

}