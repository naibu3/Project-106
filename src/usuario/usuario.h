/*
usuario.h

Clase que representa al usuario no registrado.
*/

#ifndef __USUARIO_H__
#define __USUARIO_H__

#include <string>
#include <time.h>
#include <stdlib.h>

class Usuario{

    private:

        std::string id_;

    public:
        std::string set_id();
        inline std::string get_id(){return id_;}

};

#endif