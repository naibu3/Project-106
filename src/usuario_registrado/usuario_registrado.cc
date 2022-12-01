/*
usuario.cc

Clase que representa al usuario no registrado.
*/

#include "usuario_registrado.h"

bool Usuario_registrado::inscribirse(Curso c,std::list<Curso> lista_cursos_){
    std::string id_curso=c.get_id();
    std::list<Curso> iterator it;
    for(it=lista_cursos_.begin();it!=lista_cursos_.end();it++){
        if(it->get_id()==id_curso){
            cursos_inscritos_.push_back(c);
            return true;
        }
    }
   return false;
}