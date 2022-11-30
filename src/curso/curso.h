/*
curso.h

Clase que representa un curso de extension
*/

#ifndef __CURSO_H__
#define __CURSO_H__

#include <string>

class Curso{

    private:

        std::string name_;
        std::string id_;

    public:

        Curso(std::string id,
                std::string name){
                
                id_=id;
                name_=name;
        }

        inline std::string get_name(){return name_;}
        inline std::string get_id(){return id_;}
};

#endif

