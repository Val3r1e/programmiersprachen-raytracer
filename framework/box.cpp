#include "box.hpp"

//Konstruktoren

Box():
    min_{-1},
    max_{1} {}


Box(glm::vec3 min, glm::vec3 max):
    min_{min},
    max_{max} {}

//get-Methoden

glm::vec3 const& getMin{
    return min_;
}

glm::vec3 const& getMax(){
    return max_;
}

//Shape Methoden

virtual float  area() const override{
    float a = std::abs(max_.x - min_.x);
    float b = std::abs(max_.y - min_.y);
    float c = std::abs(max_.z - min_.z);
    return 2*(a * b + b * c + a * c);

}

virtual float volume() const override{
    float a = std::abs(max_.x - min_.x);
    float b = std::abs(max_.y - min_.y);
    float c = std::abs(max_.z - min_.z);
    return a * b * c;
    
}