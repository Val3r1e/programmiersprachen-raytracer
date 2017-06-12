#include "sphere.hpp"
#include "cmath"

//Konstruktoren

Sphere(): 
    center_{0},
    radius_{1.0f} {}

Sphere(glm::vec3 const& center, float radius):
    center_{center},
    radius_{radius} {}

//get-Methoden

 glm::vec3 const& getCenter(){
    return center_;
}

float getRadius(){
    return radius_;
}

//Shape Methoden 

virtual float  area() const override{
    return 4 * M_PI * pow(radius_, 2);
}

virtual float volume() const override{
    return (4/3) * M_PI * pow(radius_, 3);
}