#include <glm/vec3.hpp>
#include <glm/glm.hpp>
#include <glm/gtx/intersect.hpp>

struct Ray{


        Ray():
            origin_ {},
            direction_ {} {}

        Ray(glm::vec3 const& origin, glm::vec3 const& direction):
            origin_ {origin},
            direction_ {glm::normalize(direction)} {}


        glm::vec3 origin_;
        glm::vec3 direction_;

};