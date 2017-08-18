#ifndef BUW_SDFLOADER_HPP
#define BUW_SDFLOADER_HPP

#include "material.hpp"
#include <iostream>
#include <fstream>
#include <sstream>
#include <cstdlib>
#include <string>
#include <vector>



class SDFLoader{

    public:

        void loadMaterial(std::string const& fileIn) const;
        void addMaterial(Material const& m);
        void print() const;

    private:

        std::vector<Material> materials_;

    

};

#endif