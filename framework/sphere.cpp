#include "sphere.hpp"


//Konstruktoren

Sphere::Sphere(): 
    Shape {},
    center_{0.0f},
    radius_{1.0f} {}

Sphere::Sphere(Material const& material, std::string const& name, glm::vec3 const& center, float radius):
    Shape {material, name},
    center_{center},
    radius_{radius} {}

Sphere::Sphere(glm::vec3 const& center, float radius, Color const& color, std::string const& name):
    Shape {color, name},
    center_{center},
    radius_{radius} {}

Sphere::~Sphere(){
    //std::cout << "dtor - derived class Sphere \n";
}

//get-Methoden

 glm::vec3 const& Sphere::getCenter() const{
    return center_;
}

float Sphere::getRadius() const{
    return radius_;
}

//Shape Methoden 

float Sphere::area() const{
    return 4.0f * M_PI * radius_ * radius_;
}

float Sphere::volume() const{
    return ((4.0f * M_PI * pow(radius_, 3))/3);
}

std::ostream& Sphere::print(std::ostream& os) const{
    Shape::print(os);
    os << "Radius: " << radius_ << ", \nCenter point: (" << center_.x << "," << center_.y << "," << center_.z << ") \n \n";
    return os;
}

bool Sphere::intersect(Ray const& ray, float& distance) const{
    return glm::intersectRaySphere(ray.origin_, ray.direction_, center_, radius_ * radius_, distance);
}