#include "instance/GLInstance.hpp"

void GLInstance::Init(const int& windowWidth, const int& windowHeight) {
    if(!glfwInit()) {
        std::cerr << "GLFW Error: GLFW initalizing stage has some issues!" << std::endl;
    }

    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE); 

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

    unsigned int vao;
    glGenVertexArrays(1, &vao);
    glBindVertexArray(vao);

    VertexBuffer vb(position,  4 * 2 * sizeof(float));



    glVertexAttribPointer(0, 2, GL_FLOAT, GL_FALSE, sizeof(float) * 2, 0);
    glEnableVertexAttribArray(0);

    IndexBuffer ib(indeces, 6);


    Shader shader {"../../../application/SandBox/assets/Basics.glsl"};

    unsigned int shaderId = shader.GetId();

    glUseProgram(shaderId);

    int location = glGetUniformLocation(shaderId, "u_Color");
    glUniform4f(location, 0.2f, 0.3f, 0.8f, 1.0f);

    glBindVertexArray(0);
    glUseProgram(0);
    glBindBuffer(GL_ARRAY_BUFFER, 0);
    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, 0);


    while(!glfwWindowShouldClose(window)) {
        glClear(GL_COLOR_BUFFER_BIT);

        glUseProgram(shaderId);
        glBindVertexArray(vao);
        ib.Bind();

        GLCall(glDrawElements(GL_TRIANGLES, 6, GL_UNSIGNED_INT, nullptr));
        

        glfwSwapBuffers(window);
        glfwPollEvents();
    }

    glDeleteProgram(shaderId);
    glfwTerminate();

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