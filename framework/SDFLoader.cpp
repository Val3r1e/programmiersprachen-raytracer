#include "SDFLoader.hpp"



void SDFLoader::loadMaterial(std::string const& fileIn) const{

    SDFLoader Loader;                   //Konstruktor?? ist doch vom typ SDFLoader

    std::ifstream file;
    std::string line;
    file.open(fileIn);

    if(file.is_open()){

        while(std::getline(file,line)){     //Solagne linien vorhanden sind
            std::stringstream ss;
            std::string keyword;

            ss<<line;               //geh zu line?
            ss>>keyword;            //lies ersters Wort

            if(keyword == "define"){
                ss<<line;           //heißt hier bleib in selber line?
                ss>>keyword;        //Geh zum nächsten Wort?

                if(keyword == "material"){

                    Material m;

                    ss>>m.name_;

                    ss>> m.ka_.r;
                    ss>> m.ka_.g;
                    ss>> m.ka_.b;
                    ss>> m.kd_.r;
                    ss>> m.kd_.g;
                    ss>> m.kd_.b;
                    ss>> m.ks_.r;
                    ss>> m.ks_.g;
                    ss>> m.ks_.b;
                    ss>> m.m_;

                    Loader.addMaterial(m);
                }
            }
        }
        file.close();
    }
    Loader.print();
}

void SDFLoader::addMaterial(Material const& m){
    materials_.push_back(m);
}

void SDFLoader::print() const{
    for(const auto& i: materials_){
        Material mp{i.name_,i.ka_, i.kd_, i.ks_, i.m_};
        std::cout<< mp;
    }
}