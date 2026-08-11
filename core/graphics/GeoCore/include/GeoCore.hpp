#ifndef GEO_CORE_HPP
#define GEO_CORE_HPP

#include <array>

#include <glm/glm.hpp>

#define GEO_CORE_VERSION_MAJOR 0
#define GEO_CORE_VERSION_MINOR 1
#define GEO_CORE_VERSION_PATCH 0

namespace GeoCore {

    inline const char* Version() {
        return "0.1.0";
    }

    class Quad {
        public: 
            std::array<glm::fvec3, 4> vertices;
            std::array<unsigned int, 6> indices;

            Quad (const glm::fvec3& center, const float& width, const float& height) {
                vertices[0] = center + glm::fvec3{-width/2.0, +  height/2.0, 0.0};
                vertices[1] = center + glm::fvec3{ width/2.0, +  height/2.0, 0.0};
                vertices[2] = center + glm::fvec3{ width/2.0, + -height/2.0, 0.0};
                vertices[3] = center + glm::fvec3{-width/2.0, + -height/2.0, 0.0};
                
                indices = { 0, 3, 1,
                            1, 3, 2 };
            }
    };

}

#endif
