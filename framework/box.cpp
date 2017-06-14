#include "box.hpp"

//Konstruktoren

Box::Box():
    min_{-1.0f},
    max_{1.0f} {}


Box::Box(glm::vec3 min, glm::vec3 max):
    min_{min},
    max_{max} {}

//get-Methoden

glm::vec3 const& Box::getMin() const{
    return min_;
}

glm::vec3 const& Box::getMax() const{
    return max_;
}

//Shape Methoden

float Box::area() const{                            //eigentlich std::abs
    float a = abs(abs(max_.x) - abs(min_.x));
    float b = abs(abs(max_.y) - abs(min_.y));
    float c = abs(abs(max_.z) - abs(min_.z));
    return 2*((a * b) + (b * c) + (a * c));

}

float Box::volume() const{
    float a = abs(abs(max_.x) - abs(min_.x));
    float b = abs(abs(max_.y) - abs(min_.y));
    float c = abs(abs(max_.z) - abs(min_.z));
    return a * b * c;
    
}