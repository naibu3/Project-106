/*
curso.cc

Clase que representa un curso de extension
*/

#include "curso.h"

bool Curso::inscribir_usuario(std::string id){

    //COMPROBAR SI YA ESTA INSCRITO
    std::list<std::string>::iterator it;
    for(it = lista_inscritos_.begin(); it != lista_inscritos_.end(); it++){
        if( (*it) == id ){
            return false;
        }
    }
    
    lista_inscritos_.push_back(id);
    return true;
}

/*

    auto now = chrono::system_clock::now();
    time_t end_time = chrono::system_clock::to_time_t(now);
    std::string ahora = ctime(&end_time); //fecha actual
    std::string ano_actual = ahora.substr(ahora.length()-5,4); //comprobación de año
    int actual_year = stoi(ano_actual);
    if(actual_year>year){
        printf("El curso ya ha comenzado\n");
        return false;
    }
    std::string mes_actual = ahora.substr(4,3); //comprobación de mes
    std::string diccionario_meses[12] = {"Jan", "Feb", "Mar", "Apr", "May", "Jun", "Jul", "Aug", "Sep", "Oct", "Nov", "Dec"};
    int nmes_actual, nmes_curso;
    for(int i = 0; i < 12; i++){ //pasa los meses a numeros
        if(mes_actual == diccionario_meses[i]){
            nmes_actual = i+1;
        }
        else if(month == diccionario_meses[i]){
            nmes_curso = i+1;
        }
    }
    if(nmes_actual>nmes_curso){
        printf("El curso ya ha comenzado\n");
        return false;
    }
 */