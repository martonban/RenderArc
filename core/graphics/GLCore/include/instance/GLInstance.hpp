#ifndef GL_INSTANCE_HPP
#define GL_INSTANCE_HPP

#include <iostream>
#include <fstream>
#include <sstream>
#include <string>

#include <GL/glew.h>
#include <GLFW/glfw3.h>

#include "shader/Shader.hpp"
#include "shader/ShaderProgramSouce.hpp"

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
  
        // Instace realated guard functions 
        GLInstance(const GLInstance&) = delete;
        GLInstance& operator=(const GLInstance&) = delete;

        
};


#endif