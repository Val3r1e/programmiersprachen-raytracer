#ifndef BUW_SHAPE_HPP
#define BUW_SHAPE_HPP
#include <glm/vec3.hpp>
#include "color.hpp"
#include "ray.hpp"
#include "material.hpp"
#include "cmath"
#include <iostream>
#include <ostream>
#include <string>

class Shape {

    public:

        Shape ();

        Shape (Material const& material, std::string const& name);

        Shape (Color const& color, std::string const& name);

        virtual ~Shape();

        //~Shape();

        virtual float area() const = 0;

        virtual float volume() const = 0;

        std::string getName() const;

        Color getColor() const;

        Material getMaterial() const;

        virtual std::ostream& print(std::ostream& os) const;

        virtual bool intersect(Ray const& ray, float& distance) const = 0;

    protected:

        std::string name_;
        Color color_;
        Material material_;

};

std::ostream& operator<<(std::ostream& os, Shape const& s);

#endif