/*
curso.cc

Clase que representa un curso de extension
*/

#include "curso.h"

bool Curso::inscribir_usuario(std::string id){

    //COMPROBAR SI YA ESTA INSCRITO
    std::list<std::string>::iterator it;
    for(it = lista_inscritos_.begin(); it != lista_inscritos_.end(); it++){
        if( (*it) == id ){
            return false;
        }
    }
    
    lista_inscritos_.push_back(id);
    return true;
}
