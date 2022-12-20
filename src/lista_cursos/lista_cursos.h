/*
lista_cursos.h

Clase que implementa un listado con todos los cursos de extension y metodos
para su manejo.
*/

#ifndef __LISTA_CURSOS_H__
#define __LISTA_CURSOS_H__

#include <list>
#include <iostream>
#include <string>
#include <stdio.h>
#include <fstream>

#include "curso.h"

class Lista_cursos{

    private:

        std::list<Curso> lista_cursos_;

    public:

        inline std::list<Curso> get_list(){return lista_cursos_;}

        bool add_curso(Curso curso);

        Curso get_curso(std::string id);

        bool remove_curso(std::string id);
        bool remove_curso(Curso curso);

        void borrar_lista();

        bool escribir_datos();
        bool leer_datos();

};

#endif
