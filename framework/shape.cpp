#include "shape.hpp"

Shape::Shape ():                    //ctor - constructor
    material_ {},
    name_ {"Shape"} {}

Shape::Shape (Material const& material, std::string const& name):
    material_ {material},
    name_ {name} {}

Shape::Shape (Color const& color, std::string const& name):
    color_ {color},
    name_ {name} {}

Shape::~Shape() {                  //dtor - destructor
    std::cout << "dtor - base class Shape \n";
}

std::string Shape::getName() const{
    return name_;
}

Color Shape::getColor() const{
    return color_;
}

Material Shape::getMaterial() const {
    return material_;
}

std::ostream& Shape::print(std::ostream& os) const{
    os << "Name: " << name_ << ", \nRgb: " << color_;
    return os;
}

std::ostream& operator<<(std::ostream& os, Shape const& s){
    return s.print(os);
}