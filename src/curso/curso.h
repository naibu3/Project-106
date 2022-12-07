/*
curso.h

Clase que representa un curso de extension
*/

#ifndef __CURSO_H__
#define __CURSO_H__

#include <string>
#include <list>
#include "usuario_registrado.h"

class Curso{

    private:

        std::string name_;
        std::string id_;
        std::list<Usuario_registrado> lista_inscritos_;

    public:

        Curso(std::string id,
                std::string name){
                
                id_=id;
                name_=name;
        }

        inline std::string get_name(){return name_;}
        inline std::string get_id(){return id_;}

        bool inscribir_usuario(Usuario_registrado usuario);
};

#endif

