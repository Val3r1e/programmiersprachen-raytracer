#include "shape.hpp"
#ifndef BUW_SPHERE_HPP
#define BUW_SPHERE_HPP

class Sphere : public Shape {

    public:

        Sphere();

        Sphere(glm::vec3 const& center, float radius, Color const& color, std::string const& name);            //mit const& da kein primitiver Datentyp

        ~Sphere() override;

        virtual float  area() const override;

        virtual float volume() const override;

        glm::vec3 const& getCenter() const;

        float getRadius() const;

        virtual std::ostream& print(std::ostream& os) const override;

        bool intersect(Ray const& ray, float& distance) const;

    private:

        glm::vec3 center_;
        float radius_;

};

#endif