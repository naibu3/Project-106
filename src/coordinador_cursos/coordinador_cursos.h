/*
coordinador_cursos.h

Clase que representa al coordinador de cursos, quien gestiona los cursos.
*/

#ifndef __COORDINADOR_CURSOS_H__
#define __COORDINADOR_CURSOS_H__

#include "usuario_registrado.h"
#include "lista_cursos.h"
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
                set_type("COORDINADOR");
                set_privilegios(2);
        }

        void crear_curso(Lista_cursos &lista);
        void borrar_curso(Lista_cursos &lista, std::string id);
        void modificar_curso(Curso &curso);
        
};

#endif