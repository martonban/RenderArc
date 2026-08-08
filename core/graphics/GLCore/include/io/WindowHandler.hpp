#ifndef WINDOW_HANDLER_HPP
#define WINDOW_HANDLER_HPP


#include <iostream>
#include <memory>

#include <GL/glew.h>
#include <GLFW/glfw3.h>


#include "render_utils/GLRenderer.hpp"

class WindowHandler {
    private:
        GLFWwindow* mWindow = nullptr;
        std::shared_ptr<GLRenderer> mRenderer;
        bool mStatus = false;
    public:
        WindowHandler(const char* title, const int& windowWidth, const int& windowHeight);
        void AttachRenderer(std::shared_ptr<GLRenderer> renderer);
        bool CheckStatus();
        GLFWwindow* GetWindow() const { return mWindow; }
        bool ShouldClose() const;
};

#endif