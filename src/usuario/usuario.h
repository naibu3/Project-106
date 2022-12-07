/*
usuario.h

Clase que representa al usuario no registrado.
*/

#ifndef __USUARIO_H__
#define __USUARIO_H__

#include <string>

class Usuario{

    private:

        std::string id_;

    public:

        inline std::string get_id(){return id_;}
};

#endif