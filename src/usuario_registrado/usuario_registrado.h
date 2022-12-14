/*
usuario_registrado.h

Clase que representa al usuario registrado.
*/

#ifndef __USUARIO_REGISTRADO_H__
#define __USUARIO_REGISTRADO_H__

#include "usuario.h"
#include "lista_cursos.h"
#include "curso.h"
#include <string>
#include <list>
#include <iostream>

class Usuario_registrado : public Usuario {

    private:
        std::string username_, email_,estudios_;
        std::list<Curso> cursos_inscritos_;


    public:
        Usuario_registrado(std::string username,
                            std::string email,
                            std::string estudios){
                                
                                username_=username;
                                email_=email;
                                estudios_=estudios;
                            }

        inline std::string get_username(){return username_;}
        inline std::string get_email(){return email_;}
        inline std::string get_estudios(){return estudios_;}
        inline std::list<Curso> get_cursos_inscritos(){return cursos_inscritos_;}

        //std::string set_estudios();
    
        void inscribirse(Curso c, std::list<Curso> lista_cursos_); 

};

#endif
