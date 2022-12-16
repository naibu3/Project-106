/*
coordinador_cursos.h

Clase que representa al coordinador de cursos, quien gestiona los cursos.
*/

#ifndef __COORDINADOR_CURSOS_H__
#define __COORDINADOR_CURSOS_H__

#include "usuario_registrado.h"
#include "curso.h"
#include <string>
#include <list>

class Coordinador_cursos : public Usuario_registrado {

    private:


    public:
        
        Coordinador_cursos(std::string username,
                            std::string email="coordinador@uco.es",
                            std::string estudios="coordinador")
        :Usuario_registrado(username, email, estudios){

                set_privilegios(2);
        }

        bool crear_curso();
        bool borrar_curso();
        bool modificar_curso();
        
};

#endif