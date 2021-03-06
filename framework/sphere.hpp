#include "shape.hpp"
#ifndef BUW_SPHERE_HPP
#define BUW_SPHERE_HPP

class Sphere : public Shape {

    public:

        Sphere();

        Sphere(Material const& material, std::string const& name, glm::vec3 const& center, float radius);

        Sphere(glm::vec3 const& center, float radius, Color const& color, std::string const& name);            //mit const& da kein primitiver Datentyp

        ~Sphere() override;

        //~Sphere();

        virtual float  area() const override;

        virtual float volume() const override;

        glm::vec3 const& getCenter() const;

        float getRadius() const;

        virtual std::ostream& print(std::ostream& os) const override;

        virtual bool intersect(Ray const& ray, float& distance) const override;

    private:

        glm::vec3 center_;
        float radius_;

};

#endif