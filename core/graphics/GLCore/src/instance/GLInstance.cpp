#include "instance/GLInstance.hpp"

void GLInstance::Init(const char* title, const int& windowWidth, const int& windowHeight, const WindowAPI& api) {
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

    VertexArray va;
    
    VertexBuffer vb(position,  4 * 2 * sizeof(float));

    VertexBufferLayout layout;
    layout.Push<float>(2);
    va.AddBuffer(vb, layout);

    IndexBuffer ib(indeces, 6);


    Shader shader {"../../../application/SandBox/assets/Basics.glsl"};
    shader.Bind();
    shader.SetUniform4f("u_Color", 0.2f, 0.3f, 0.8f, 1.0f);


    va.Unbind();
    shader.Unbind();
    vb.Unbind();
    ib.Unbind();

    while(!glfwWindowShouldClose(window)) {
        glClear(GL_COLOR_BUFFER_BIT);

        shader.Bind();

        va.Bind();
        ib.Bind();

        GLCall(glDrawElements(GL_TRIANGLES, 6, GL_UNSIGNED_INT, nullptr));
        

        glfwSwapBuffers(window);
        glfwPollEvents();
    }

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