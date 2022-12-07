#include "usuario.h"

std::string Usuario::set_id(){
    srand(time(NULL));
    long identificador;
    identificador=1+rand()%(100000001-1);
    std::string id = std::to_string(identificador);
    return id;
}