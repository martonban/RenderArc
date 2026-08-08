#ifndef GL_COMMON_HPP
#define GL_COMMON_HPP


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


typedef struct GLWindowSettings {
    const char* title = "Application Name";
    int windowWidth = 640;
    int windowHeight = 480;
    WindowAPI windowApi = GLFW_API;
} GLWindowSettings;


#endif