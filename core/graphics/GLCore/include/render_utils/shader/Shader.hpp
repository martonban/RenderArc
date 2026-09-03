#ifndef SHADER_HPP
#define SHADER_HPP

#include <iostream>
#include <fstream>
#include <sstream>
#include <string>

#include <unordered_map>

#include <GL/glew.h>
#include "glm/glm.hpp"
#include "glm/gtc/matrix_transform.hpp"

#ifdef _WIN32
    #ifdef GL_CORE_LIB_EXPORT
        #define GL_CORE_LIB_API __declspec(dllexport)
    #else
        #define GL_CORE_LIB_API __declspec(dllimport)
    #endif
#else
    #define GL_CORE_LIB_API
#endif

struct ShaderProgramSource {
    std::string vertexSource;
    std::string fragmentSource;
};


class GL_CORE_LIB_API Shader {
    private:
        unsigned int mRendererID;
        std::string mFilePath;
        std::unordered_map<std::string, int> mUniformLocationCache;
        ShaderProgramSource mSrc {};
    public:
        Shader(const std::string& filePath);
        ~Shader();

        void Bind() const;
        void Unbind() const;
        
        void SetUniform4f(const std::string& name, const float& v0, const float& v1, const float& v2, const float& v3);
        void SetUniform1i(const std::string& name, const int& v0);
        void SetUniform4m(const std::string& name, const glm::mat4& v);

        unsigned int GetId();

    private:
        ShaderProgramSource ParseShader();
        unsigned int CompileShader(unsigned int type, const std::string& source);
        unsigned int CreateShader(const std::string& vertexShader, const std::string& fragmentShader);
                
        int GetUniformLocation(const std::string& name);

        
};

#endif