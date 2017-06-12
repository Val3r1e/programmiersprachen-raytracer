#include "shape.hpp"
#include <glm/vec3.hpp>
#ifndef BUW_BOX_HPP
#define BUW_BOX_HPP

class Box : public Shape{

    public:

        Box();

        Box(glm::vec3 min_, glm::vec3 max_);

        virtual float  area() const override;

        virtual float volume() const override;

        glm::vec3 const& getMin();

        glm::vec3 const& getMax();

    private:

        glm::vec3 min_;
        glm::vec3 max_;

};

#endif