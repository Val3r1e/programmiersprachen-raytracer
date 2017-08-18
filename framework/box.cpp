#include "box.hpp"

//Konstruktoren

Box::Box():
    Shape {},
    min_{-1.0f},
    max_{1.0f} {}

Box::Box(Material const& material, std::string const& name, glm::vec3 const& min, glm::vec3 const& max):
    Shape{material, name},
    min_{min},
    max_{max} {}

Box::Box(glm::vec3 const& min, glm::vec3 const& max, Color const& color, std::string const& name):
    Shape {color, name},
    min_{min},
    max_{max} {}

Box::~Box(){
    
}

//get-Methoden

glm::vec3 const& Box::getMin() const{
    return min_;
}

glm::vec3 const& Box::getMax() const{
    return max_;
}

//Shape Methoden

float Box::area() const{                           
    auto diff = max_ - min_;
    return 2*((diff.x * diff.y) + (diff.y * diff.z) + (diff.x * diff.z));

}

float Box::volume() const{
    auto diff = max_ - min_;
    return diff.x * diff.y * diff.z;
}

std::ostream& Box::print(std::ostream& os) const{
    Shape::print(os);
    os << "Min coordinates: (" << min_.x << "," << min_.y << "," << min_.z << "), \n" 
    << "Max coordinates: (" << max_.x << "," << max_.y << "," << max_.z << ") \n \n";
    return os;
}

bool Box::intersect(Ray const& ray, float& distance) const{
    float tx1 = (min_.x - ray.origin_.x)/ray.direction_.x;
    float tx2 = (max_.x - ray.origin_.x)/ray.direction_.x;

    float ty1 = (min_.y - ray.origin_.y)/ray.direction_.y;
    float ty2 = (max_.y - ray.origin_.y)/ray.direction_.y;

    float tz1 = (min_.z - ray.origin_.z)/ray.direction_.z;
    float tz2 = (max_.z - ray.origin_.z)/ray.direction_.z;

    float tfarx = std::max(tx1, tx2);
    float tnearx = std::min(tx1, tx2);

    float tfary = std::max(ty1, ty2);
    float tneary = std::min(ty1, ty2);

    float tfar = std::min(tfarx, tfary);
    float tnear = std::max(tnearx, tneary);

    if(tfar < tnear){
        return false;
    }

    tfar = std::min(tz2, tfar);
    tnear = std::max(tz1, tnear);       //tnear ist schnittpunkt

    if(tfar < tnear){
        return false;
    }
    //Eigentlichen Schnittpunkt berechnen
    distance = std::abs(tnear);
    return true;
   
}

