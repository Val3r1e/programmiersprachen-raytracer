#include "shape.hpp"
#ifndef BUW_BOX_HPP
#define BUW_BOX_HPP

class Box : public Shape{

    public:

        Box();

        Box(Material const& material, std::string const& name, glm::vec3 const& min, glm::vec3 const& max);

        Box(glm::vec3 const& min, glm::vec3 const& max, Color const& color, std::string const& name);

        ~Box() override;

        //~Box();

        virtual float  area() const override;

        virtual float volume() const override;

        glm::vec3 const& getMin() const;

        glm::vec3 const& getMax() const;

        virtual std::ostream& print(std::ostream& os) const override;

        virtual bool intersect(Ray const& ray, float& distance) const override;

    private:

        glm::vec3 min_;
        glm::vec3 max_;

};

#endif