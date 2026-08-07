#ifndef GL_COMMON_HPP
#define GL_COMMON_HPP

typedef enum {
    GLFW_API
} WindowAPI;


typedef struct GLRendererSettings {
    const char* title = "Application Name";
    int windowWidth = 640;
    int windowHeight = 480;
    WindowAPI windowApi = GLFW_API;
} GLRendererSettings;

#endif