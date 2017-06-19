#include "shape.hpp"

Shape::Shape ():                    //ctor - constructor
    color_ {0.0f, 0.0f, 0.0f},
    name_ {"Shape"} { std::cout << "ctor - base class Shape \n"; }

Shape::Shape (Color const& color, std::string const& name):
    color_ {color},
    name_ {name} { std::cout << "ctor - base class Shape \n"; }

Shape::~Shape() {                  //dtor - destructor
    std::cout << "dtor - base class Shape \n";
}

std::string Shape::getName() const{
    return name_;
}

Color Shape::getColor() const{
    return color_;
}

std::ostream& Shape::print(std::ostream& os) const{
    os << "Name: " << name_ << ", \n Rgb: " << color_;
    return os;
}

std::ostream& operator<<(std::ostream& os, Shape const& s){
    return s.print(os);
}