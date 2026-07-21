#ifndef SHADER_HPP
#define SAHDER_HPP

#include <iostream>
#include <fstream>
#include <sstream>
#include <string>

#include <GL/glew.h>

#include "shader/ShaderProgramSouce.hpp"

class Shader {
    public:
        Shader(const std::string& filePath);
        unsigned int GetId();
        
    private:

        unsigned int id;
        ShaderProgramSource src {};

        static int CreateShader(const std::string& vertexShader, const std::string& fragmentShader);
        static int CompileShader(unsigned int type, const std::string& source);
        static ShaderProgramSource ParseShader(const std::string& filePath);

        // TO-DO Uniforms
};

#endif