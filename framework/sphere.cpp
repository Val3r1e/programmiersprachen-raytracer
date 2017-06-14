#include "sphere.hpp"
#include "cmath"

//Konstruktoren

Sphere::Sphere(): 
    center_{0.0f},
    radius_{1.0f} {}

Sphere::Sphere(glm::vec3 const& center, float radius):
    center_{center},
    radius_{radius} {}

//get-Methoden

 glm::vec3 const& Sphere::getCenter() const{
    return center_;
}

float Sphere::getRadius() const{
    return radius_;
}

//Shape Methoden 

float Sphere::area() const{
    return 4 * M_PI * pow(radius_, 2);
}

float Sphere::volume() const{
    return ((4/3) * M_PI * pow(radius_, 3));
}