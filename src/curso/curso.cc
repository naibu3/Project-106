/*
curso.cc

Clase que representa un curso de extension
*/

#include "curso.h"
/*
bool Curso::inscribir_usuario(Usuario_registrado user){
    std::list<Usuario_registrado>::iterator it;
    for(it = lista_inscritos_.begin(); it != lista_inscritos_.end(); it++){
        if(it->get_id()==user.get_id()){
            return false;
        }
    }
    if(lista_inscritos_.size()==aforo){
        printf("El curso está completo\n");
        return false;
    }
    if(user.get_estudios()!=estudio){
        printf("No tiene los estudios requeridos para este curso\n");
        return false;
    }

    auto now = chrono::system_clock::now();
    time_t end_time = chrono::system_clock::to_time_t(now);
    std::string ahora = ctime(&end_time); //fecha actual
    std::string ano_actual = ahora.substr(20,23); //comprobación de año
    int actual_year = stoi(ano_actual);
    if(actual_year>year){
        printf("El curso ya ha comenzado\n");
        return false;
    }
    std::string mes_actual = ahora.substr(4,6); //comprobación de mes
    std::string diccionario_meses[12] = {"Jan", "Feb", "Mar", "Apr", "May", "Jun", "Jul", "Aug", "Sep", "Oct", "Nov", "Dec"};
    int nmes_actual, nmes_curso;
    for(int i = 0; i < 12; i++){ //pasa los meses a numeros
        if(mes_actual == diccionario_meses[i]){
            nmes_actual = i;
        }
        else if(month == diccionario_meses[i]){
            nmes_curso = i;
        }
    }
    if(nmes_actual>nmes_curso){
        printf("El curso ya ha comenzado\n");
        return false;
    }
    std::string dia_actual = ahora.substr(9,9); //comprobación de día
    int actual_day = stoi(dia_actual);
    if(actual_day>day){
        printf("El curso ya ha comenzado\n");
        return false;
    }

    lista_inscritos_.push_back(usuario);
    return true;
}

*/