#include "sphere.hpp"

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

}

virtual float volume() const override{

}