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
#include <stdio.h>


class Usuario_registrado : public Usuario {

    private:
        std::string username_, email_,estudios_, type_;
        std::list<Curso> cursos_inscritos_;


    public:
        Usuario_registrado(std::string username,
                            std::string email,
                            std::string estudios):Usuario(){
                                type_="REGISTRADO";
                                username_=username;
                                email_=email;
                                estudios_=estudios;
                                set_privilegios(1);
                            }
        inline std::string get_type(){return type_;}
        inline void set_type(std::string type){type_=type;}

        inline std::string get_username(){return username_;}
        inline std::string get_email(){return email_;}
        inline std::string get_estudios(){return estudios_;}
        inline std::list<Curso> get_cursos_inscritos(){return cursos_inscritos_;}

        //std::string set_estudios();
    
        bool inscribirse(Curso c);
        bool desinscribirse(Curso c); 

};

#endif
