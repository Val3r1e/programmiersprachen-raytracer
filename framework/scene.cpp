#include "scene.hpp"

void Scene::addMaterial(Material const& m){
    std::cout << "HI3";
    auto p = std::make_shared<Material> (m);
    materials_.push_back(p);
    std::cout<< "Material Name:" << p->name_;
}

void Scene::print() const{
    std::cout << "HI";
    for(const auto& i: materials_){
        std::cout << "HI2";
        Material mp{i->name_,i->ka_, i->kd_, i->ks_, i->m_};
        std::cout<< mp;
    }
}

Scene Scene::SDFLoader(std::string const& fileIn) const{

    Scene scene;                  

    std::ifstream file;
    std::string line;
    file.open(fileIn);      //Öffnen File

    if(file.is_open()){

        while(std::getline(file,line)){     //Solagne linien vorhanden sind
            std::stringstream ss;
            std::string keyword;

            ss<<line;               //geh zu line?
            ss>>keyword;            //lies ersters Wort

            if(keyword == "define"){
                //ss<<line;           //heißt hier bleib in selber line?
                ss>>keyword;        //Geh zum nächsten Wort?

                if(keyword == "material"){

                    Material mat;

                    ss>>mat.name_;

                    ss>> mat.ka_.r;
                    ss>> mat.ka_.g;
                    ss>> mat.ka_.b;
                    ss>> mat.kd_.r;
                    ss>> mat.kd_.g;
                    ss>> mat.kd_.b;
                    ss>> mat.ks_.r;
                    ss>> mat.ks_.g;
                    ss>> mat.ks_.b;

                    ss>> mat.m_;

                    scene.addMaterial(mat);
                }

                /*if(keyword == "shape"){
                    ss<<line;       //was macht das?
                    ss>>keyword;

                    if(keyword == "box"){

                        std::string bname;
                        glm::vec3 bmin;
                        glm::vec3 bmax;

                        ss>> bname;

                        ss>> bmin.x;
                        ss>> bmin.y;
                        ss>> bmin.z;

                        ss>> bmax.x;
                        ss>> bmax.y;
                        ss>> bmax.z;

                        //Material
                        //Box b {Material, bname, bmin, bmax};
                    }

                    if(keyword == "sphere"){

                        std::string sname;
                        glm::vec3 scenter;
                        float sradius;

                        ss>> sname;

                        ss>> scenter.x; 
                        ss>> scenter.y; 
                        ss>> scenter.z;

                        ss>> sradius;

                        //Material

                        //Sphere s {Material, sname, scenter, sradius}; 
                    }*/
                    
                }
            }
        file.close();
        }
    scene.print();

    return scene;
    
    
}
