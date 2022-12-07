/*
usuario.h

Clase que representa al usuario no registrado.
*/

#ifndef __USUARIO_REGISTRADO_H__
#define __USUARIO_REGISTRADO_H__

#include "usuario.h"
#include "lista_cursos.h"

#include <string>
#include <list>

class Usuario_registrado : public Usuario {

    private:
        std::string username_, email_;
        std::list<Curso> cursos_inscritos_;


    public:
        Usuario_registrado(std::string username,
            std::string email);

        inline std::string get_username(){return username_;}
        inline std::string get_email(){return email_;}
        bool inscribirse(Curso c, std::list<Curso> lista_cursos_);

};

#endif