#ifndef BUW_LIGHT_HPP
#define BUW_LIGHT_HPP
#include <string>
#include <glm/vec3.hpp>

struct Light{

    std::string name_;
    glm::vec3 position_;
    Color Ia_;
    Color Ip_;

    Light():
        name_{"Default"},
        position_{-1,-1,-1},
        Ia_{0.0f},
        Ip_{0.0f}

    Light(std::string name, glm::vec3 position, Color Ia, Color Ip){
        name_{name},
        position_{position},
        Ia_{Ia},
        Ip_{Ip}
    }

};

#endif