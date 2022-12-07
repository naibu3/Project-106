/*
curso.cc

Clase que representa un curso de extension
*/

#include "curso.h"
#include "usuario_registrado.h"

void Curso::inscribir_usuario(Usuario_registrado usuario){
    std::list<Usuario_registrado>::iterator it;
    for(it = lista_inscritos_.begin(); it != lista_inscritos_.end(); it++){
        if(it->get_id())
    }
}