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

    float position[6] = {
        -0.5f, -0.5f,
         0.0f,  0.5f,
         0.5f, -0.5f 
    };

    glClearColor(0.1f, 0.1f, 0.1f, 1.0f);

    unsigned int buffer;
    glGenBuffers(1, &buffer);
    glBindBuffer(GL_ARRAY_BUFFER, buffer);
    glBufferData(GL_ARRAY_BUFFER, 6 * sizeof(float), position, GL_STATIC_DRAW);

    
    glVertexAttribPointer(0, 2, GL_FLOAT, GL_FALSE, sizeof(float) * 2, 0);
    glEnableVertexAttribArray(0);

    ShaderProgramSource source = ParseShader("../../../application/SandBox/assets/Basics.glsl");

    std::cout << source.vertexSource <<std::endl;
    std::cout << source.fragmentSource <<std::endl;

    unsigned int shader = CreateShader(source.vertexSource, source.fragmentSource);

    glUseProgram(shader);

    while(!glfwWindowShouldClose(window)) {
        glClear(GL_COLOR_BUFFER_BIT);

        glDrawArrays(GL_TRIANGLES, 0, 3);
        
        glfwSwapBuffers(window);
        glfwPollEvents();
    }

    glDeleteProgram(shader);
    glfwTerminate();

}


int GLInstance::CreateShader(const std::string& vertexShader, const std::string& fragmentShader) {
    unsigned int program = glCreateProgram();
    unsigned int vs = CompileShader(GL_VERTEX_SHADER, vertexShader);
    unsigned int fs = CompileShader(GL_FRAGMENT_SHADER, fragmentShader);

    glAttachShader(program, vs);
    glAttachShader(program, fs);

    glLinkProgram(program);

    glValidateProgram(program);

    glDeleteShader(vs);
    glDeleteShader(fs);

    return program;
}


int GLInstance::CompileShader(unsigned int type, const std::string& source) {
    unsigned int id = glCreateShader(type);
    const char* src = source.c_str();
    // 1 = how many program we give it to it
    glShaderSource(id, 1, &src, nullptr);
    glCompileShader(id);

    int result;
    glGetShaderiv(id, GL_COMPILE_STATUS, &result);

    if(!result) {
        int length;
        glGetShaderiv(id, GL_INFO_LOG_LENGTH, &length);
        char* message = (char*)alloca(length * sizeof(char));
        glGetShaderInfoLog(id, length, &length, message);
        std::cout << "Failed to compile: " << (type == GL_VERTEX_SHADER ? "vertex" : "fragment") << " shader!" << std::endl;
        std::cout << message << std::endl;
        glDeleteShader(id);
        return 0;
    }

    return id;
}


ShaderProgramSource GLInstance::ParseShader(const std::string& filePath) {
    std::ifstream stream(filePath);

    if(!stream.is_open()) {
        std::cerr << "Error: Could not open shader file: " << filePath << std::endl;
        return {"", ""};
    }

    enum class ShaderType {
        NONE = -1, VERTEX = 0, FRAGMENT = 1
    };

    std::string line;
    std::stringstream ss[2];
    ShaderType type = ShaderType::NONE;
    while(std::getline(stream, line)) {
        if(line.find("#shader") != std::string::npos) {
            if(line.find("vertex") != std::string::npos) {
                type = ShaderType::VERTEX;
            } else if (line.find("fragment") != std::string::npos) {
                type = ShaderType::FRAGMENT;
            }
        } else if(type != ShaderType::NONE) {
            ss[(int)type] << line << "\n";
        }
    }

    return {ss[0].str(), ss[1].str()};
}
