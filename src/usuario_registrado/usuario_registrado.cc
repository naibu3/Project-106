/*
usuario.cc

Clase que representa al usuario registrado.
*/

#include "usuario_registrado.h"

/*Función que se ejecuta si todos los requisitos del método inscribir_usuario()
de Curso se cumplen.*/
bool Usuario_registrado::inscribirse(Curso c){
    
    std::string id_curso=c.get_id();

    //COMPROBAR SI HAY AFORO
    if(c.get_lista_inscritos().size()==c.get_aforo()){
        printf("El curso está completo\n");
        return false;
    }

    //COMPROBAR SI SE TIENE EL NIVEL DE ESTUDIO SUFICIENTE
    if( estudios_ != c.get_estudio() ){
        printf("No tiene los estudios requeridos para este curso\n");
        return false;
    }

    //COMPROBAR SI EL CURSO YA HA COMENZADO
    /*
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
    */

    //COMPROBAR QUE NO ESTUVIERAS YA INSCRITO
    if(!c.inscribir_usuario(this->get_id())){
        printf("Ya estás inscrito!\n");
        return false;
    }
    return true;
}
