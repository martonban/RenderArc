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

#include "GLCommon.hpp"
#include "instance/GLInstance.hpp" 


namespace GLCore {
    GL_CORE_LIB_API void Init();
    GL_CORE_LIB_API void Init(const GLWindowSettings& settings);

    GL_CORE_LIB_API void InitRenderer();

    GL_CORE_LIB_API bool ShouldClose();
    GL_CORE_LIB_API void BeginFrame();
    GL_CORE_LIB_API void EndFrame();   
    GL_CORE_LIB_API void Shutdown();

    GL_CORE_LIB_API void TestUpload();

    GL_CORE_LIB_API void TestDrawCall();


}

#endif