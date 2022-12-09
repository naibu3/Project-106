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
        std::string username_, email_,estudios_;
        std::list<Curso> cursos_inscritos_;


    public:
        Usuario_registrado(std::string username,
            std::string email, std::string estudios);

        inline std::string get_username(){return username_;}
        inline std::string get_email(){return email_;}
        inline std::string get_estudios(){return estudios_;}
    //std::string set_estudios();
    
        bool inscribirse(Curso c, std::list<Curso> lista_cursos_);

};

#endif
