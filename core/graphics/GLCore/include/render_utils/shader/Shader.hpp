#ifndef SHADER_HPP
#define SHADER_HPP

#include <iostream>
#include <fstream>
#include <sstream>
#include <string>

#include <unordered_map>

#include <GL/glew.h>

struct ShaderProgramSource {
    std::string vertexSource;
    std::string fragmentSource;
};


class Shader {
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

        unsigned int GetId();

    private:
        ShaderProgramSource ParseShader();
        unsigned int CompileShader(unsigned int type, const std::string& source);
        unsigned int CreateShader(const std::string& vertexShader, const std::string& fragmentShader);
                
        int GetUniformLocation(const std::string& name);

        
};

#endif