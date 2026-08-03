#ifndef GL_INSTANCE_HPP
#define GL_INSTANCE_HPP

#include <iostream>
#include <fstream>
#include <sstream>
#include <string>

#include <GL/glew.h>
#include <GLFW/glfw3.h>

#include "buffers/VertexBuffer.hpp"
#include "buffers/IndexBuffer.hpp"

#include "shader/Shader.hpp"
#include "shader/ShaderProgramSouce.hpp"

#include "WindowUtils.hpp"

#ifdef _MSC_VER
    #define ASSERT(x) if (!(x)) __debugbreak();
#else
    #define ASSERT(x) if (!(x)) __builtin_trap();
#endif

#define GLCall(x) GLClearError();\
    x;\
    ASSERT(GLLogCall(#x, __FILE__, __LINE__))


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
  
        static void GLClearError();
        static bool GLLogCall(const char* fuction, const char* file, int line);

        // Instace realated guard functions 
        GLInstance(const GLInstance&) = delete;
        GLInstance& operator=(const GLInstance&) = delete;

        
};


#endif