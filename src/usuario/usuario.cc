#include "usuario.h"

std::string Usuario::set_id(){
    srand(time(NULL));
    long identificador;
    identificador=1+rand()%(100000001-1);
    std::string id=std::string to_string (long identificador);
    return id:
}