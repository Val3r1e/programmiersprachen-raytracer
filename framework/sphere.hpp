#include "shape.hpp"
#include <glm/vec3.hpp>
#ifndef BUW_SPHERE_HPP
#define BUW_SPHERE_HPP

class Sphere : public Shape {

    public:

        Sphere();

        Sphere(glm::vec3 const& center_, float radius_);            //mit const& da kein primitiver Datentyp

        virtual float  area() const override;

        virtual float volume() const override;

        glm::vec3 const& getCenter();

        float getRadius();

    private:

        glm::vec3 center_;
        float radius_;

};

#endif