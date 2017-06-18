#include "shape.hpp"

Shape::Shape ():
    color_ {0.0f, 0.0f, 0.0f},
    name_ {"Shape"} {}

Shape::Shape (Color const& color, std::string const& name):
    color_ {color},
    name_ {name} {}

Shape::~Shape() {

}

std::string Shape::getName() const{
    return name_;
}

Color Shape::getColor() const{
    return color_;
}

std::ostream& Shape::print(std::ostream& os) const{
    os << "Name: " << name_ << ", \nRgb: " << color_;
    return os;
}

std::ostream& operator<<(std::ostream& os, Shape const& s){
    return s.print(os);
}