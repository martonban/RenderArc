#include "instance/GLInstance.hpp"

void GLInstance::Init(const int& windowWidth, const int& windowHeight) {
    if(!glfwInit()) {
        std::cerr << "GLFW Error: GLFW initalizing stage has some issues!" << std::endl;
    }

    window = glfwCreateWindow(windowWidth, windowHeight, "Hello World", NULL, NULL);
    if(!window) {
        glfwTerminate();
        std::cerr << "GLFW Error: Having issues in the window creation!" << std::endl;
    }

    glfwMakeContextCurrent(window);

    if(glewInit() != GLEW_OK ) {
        std::cerr << "GLEW Error: GLEW initalizing stage has some issues!" << std::endl;
    }
}


void GLInstance::StartWindow() {

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

    unsigned int buffer;
    glGenBuffers(1, &buffer);
    glBindBuffer(GL_ARRAY_BUFFER, buffer);
    glBufferData(GL_ARRAY_BUFFER, 6 * 2 * sizeof(float), position, GL_STATIC_DRAW);

    unsigned int ibo;
    glGenBuffers(1, &ibo);
    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, ibo);
    glBufferData(GL_ELEMENT_ARRAY_BUFFER, 3 * 2 * sizeof(unsigned int), indeces, GL_STATIC_DRAW);


    glVertexAttribPointer(0, 2, GL_FLOAT, GL_FALSE, sizeof(float) * 2, 0);
    glEnableVertexAttribArray(0);


    Shader shader {"../../../application/SandBox/assets/Basics.glsl"};

    unsigned int shaderId = shader.GetId();

    glUseProgram(shaderId);

    while(!glfwWindowShouldClose(window)) {
        glClear(GL_COLOR_BUFFER_BIT);

        glDrawElements(GL_TRIANGLES, 6, GL_UNSIGNED_INT, nullptr);
        
        glfwSwapBuffers(window);
        glfwPollEvents();
    }

    glDeleteProgram(shaderId);
    glfwTerminate();

}


