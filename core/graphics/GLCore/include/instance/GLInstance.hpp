#ifndef GL_INSTANCE_HPP
#define GL_INSTANCE_HPP

#include <iostream>

#include <GL/glew.h>
#include <GLFW/glfw3.h>

#include "shader/Shader.hpp"

#include "WindowUtils.hpp"

class GLInstance {
    public:
        static GLInstance& GetInstance() {
            static GLInstance instance;
            return instance;
        }
        void Init(const int& windowWidth, const int& windowHeight);
        void StartWindow();
    protected:
        GLInstance() = default;
    private:
        GLFWwindow* window;

        
        static int CreateShader(const std::string& vertexShader, const std::string& fragmentShader);
        static int CompileShader(unsigned int type, const std::string& source);

        // Instace realated guard functions 
        GLInstance(const GLInstance&) = delete;
        GLInstance& operator=(const GLInstance&) = delete;

        std::string vertexShader = R"(
            #version 330 core
            layout(location = 0) in vec4 position;
            void main(){
                gl_Position = position;
            }
        )";
        
    std::string fragmentShader = R"(
        #version 330 core
        out vec4 FragColor;
        void main(){
            FragColor = vec4(1.0, 0.0, 0.0, 1.0);
        }
    )";
};


#endif