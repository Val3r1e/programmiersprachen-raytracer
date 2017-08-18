#ifndef BUW_SCENE_HPP
#define BUW_SCENE_HPP
#include <vector>
#include <iostream>
#include <fstream>
#include <sstream>
#include <cstdlib>
#include <string>
#include "shape.hpp"
#include "material.hpp"

struct Scene{

    public:

        Scene SDFLoader(std::string const& fileIn) const;
        void addMaterial(Material const& m);
        void print() const;

    private:

        std::vector <std::shared_ptr<Shape>> shapes_;
        std::vector <std::shared_ptr<Material>> materials_;

};

#endif