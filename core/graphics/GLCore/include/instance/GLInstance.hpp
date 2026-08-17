#ifndef GL_INSTANCE_HPP
#define GL_INSTANCE_HPP


#include <fstream>
#include <sstream>
#include <string>

#include "GLCommon.hpp"

#include "Batch.hpp"

#include "io/WindowHandler.hpp"

#include "render_utils/buffers/VertexBuffer.hpp"
#include "render_utils/buffers/IndexBuffer.hpp"
#include "render_utils/buffers/VertexArray.hpp"

#include "render_utils/shader/Shader.hpp"

#ifdef _MSC_VER
    #define ASSERT(x) if (!(x)) __debugbreak();
#else
    #define ASSERT(x) if (!(x)) __builtin_trap();
#endif

#define GLCall(x) GLClearError();\
    x;\
    ASSERT(GLLogCall(#x, __FILE__, __LINE__))


class GLInstance {
    private:
        GLCoreStatus mStatus {GL_CORE_UNINITIALIZED};
        std::unique_ptr<WindowHandler> mWindowSys;
        std::shared_ptr<GLRenderer> mRenderer;

        // Temporary
        std::vector<Batch> mBatches;



    public:
        static GLInstance& GetInstance() {
            static GLInstance instance;
            return instance;
        }
        void Init(const char* title, const int& windowWidth, const int& windowHeight, const WindowAPI& api);
        void InitRenderer();
        bool ShouldClose() const;
        void BeginFrame();
        void EndFrame();
        void Destroy();

        void AddBatch(const GeoCore::Quad& quad, const VertexBufferLayout& layout, const std::string& shaderFilePath, const std::string& textureFilePath);
        void Draw();

    protected:
        GLInstance() = default;

    private:
        static void GLClearError();
        static bool GLLogCall(const char* fuction, const char* file, int line);

        // Instace realated guard functions 
        GLInstance(const GLInstance&) = delete;
        GLInstance& operator=(const GLInstance&) = delete;

        
};


#endif