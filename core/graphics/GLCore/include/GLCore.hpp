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


typedef struct GLRendererSettings {
    int windowWidth = 640;
    int windowHeight = 480;
} GLRendererSettings;





namespace GLCore {
    GL_CORE_LIB_API void Init(const GLRendererSettings& settings);
    GL_CORE_LIB_API void StartWindow();

}


#endif