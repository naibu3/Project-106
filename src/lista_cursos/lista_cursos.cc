/*
lista_cursos.cc

Clase que implementa un listado con todos los cursos de extension y metodos
para su manejo.
*/

#include "lista_cursos.h"
#include "curso.h"


bool Lista_cursos::add_curso(std::string id){
    std::list<Curso>::iterator it;
    for(it = lista_cursos_.begin(); it != lista_cursos_.end(); it++){
        if(it->get_id()==id){
            return false;       //el curso ya se encuentra en la lista
        }
    }
    lista_cursos_.push_back(*it);
    return true;
}

bool Lista_cursos::add_curso(Curso curso){ Lista_cursos::add_curso(curso.get_id());}

bool Lista_cursos::remove_curso(std::string id){
    std::list<Curso>::iterator it;
    for(it = lista_cursos_.begin(); it != lista_cursos_.end(); it++){
        if(it->get_id()==id){
            lista_cursos_.erase(it);
            return true;
        }
    }
    return false;               //el curso no esta en la lista
}

bool Lista_cursos::remove_curso(Curso curso){Lista_cursos::add_curso(curso.get_id());}

