#ifndef GL_COMMON_HPP
#define GL_COMMON_HPP

#include <filesystem>
#include <vector>

#include "render_utils/buffers/VertexBufferLayout.hpp"

typedef enum {
    GLFW_API
} WindowAPI;

typedef enum {
    GL_CORE_UNINITIALIZED = -1,
    GL_CORE_INITIALIZED = 0,
    GL_CORE_WINDOWING_SYS_INITIALIZED = 1,
    GL_CORE_RENDERING_SYS_INITIALIZED = 2,
    GL_CORE_RENDERER_ATTACHED_TO_WINDOW = 3
} GLCoreStatus;


namespace GLCore {
    // State structs
    typedef struct WindowSettings {
        const char* title = "Application Name";
        int windowWidth = 640;
        int windowHeight = 480;
        WindowAPI windowApi = GLFW_API;
    } GLWindowSettings;


    // Rendering classes
    typedef struct DrawableObject {
        std::vector<float> verteces;
        std::vector<float> indeces;
        VertexBufferLayout layout;
        unsigned int shaderID;
    } DrawableObject;  



}


#endif