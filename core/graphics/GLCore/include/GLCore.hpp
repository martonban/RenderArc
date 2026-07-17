#ifndef GL_CORE_LIB_HPP
#define GL_CORE_LIB_HPP

#ifdef _WIN32
    #ifdef GL_CORE_LIB_EXPORT
        #define GL_CORE_LIB_API __declspec(dllexport)
    #else
        #define GL_CORE_LIB_API __declspec(dllimport)
    #endif
#else
    #define GL_CORE_LIB_API
#endif

#include "instance/GLInstance.hpp"

namespace GLCore {
    GL_CORE_LIB_API void Init();
    GL_CORE_LIB_API void StartWindow(const Renderer::WindowBaseSetting& settings);

}


#endif