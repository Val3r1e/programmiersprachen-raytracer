#ifndef BUW_MATERIAL_HPP
#define BUW_MATERIAL_HPP
#include "color.hpp"
#include <iostream>
#include <string>

struct Material{

    Material():
        name_{"tolles Material"},
        ka_{Color{}},
        kd_{Color{}},
        ks_{Color{}},
        m_{1.0f} {}

    Material(std::string name, Color ka, Color kd, Color ks, float m):
        name_{name},
        ka_{ka},
        kd_{kd},
        ks_{ks},
        m_{m} {}

    friend std::ostream& operator<<(std::ostream& os, Material const& m){
        os << "Material: " << m.name_ << 
            "\nKa: " << m.ka_ << 
            "Kd: " << m.kd_ << 
            "Ks: " << m.ks_ << 
            "Float: " << m.m_ << "\n";
        return os;
    }

    std::string name_;
    Color ka_;
    Color kd_;
    Color ks_;
    float m_;
};

#endif