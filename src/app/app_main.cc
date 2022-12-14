#include "lista_cursos.h"
#include <string>
#include <iostream>
#include <fstream>

//PARA COMPATIBILIDAD AL LIMPIAR PANTALLA ENTRE WIN Y LINUS
#ifdef _WIN32
  #include<windows.h>
#endif  

void limpiar_pantalla()
{
    #ifdef _WIN32
        system("cls");
    #else
        system("clear");
    #endif
}

void imprimir_logos(){

    std::string nombreArchivo = "banner.txt";
    std::ifstream archivo(nombreArchivo);

    if (!archivo.is_open())
    {
        std::cout <<"Error al abrir " << nombreArchivo << "\n";
        exit(EXIT_FAILURE);
    }

    std::string linea;
    while (getline(archivo, linea)) {

        std::cout << linea << std::endl;
    }

    archivo.close();
}

void imprimir_menu(){
    std::cout<<std::endl;
    std::cout<<"    (1) - Ver cursos."<<std::endl;
    std::cout<<"    (9) - Salir."<<std::endl;
    std::cout<<std::endl;
    std::cout<<"Inserte eleccion y pulse intro: ";
}

void pulsa_intro(){
    char a;
    while(a = std::cin.get()){
        if(a == '\n'){
            break;
        }
    }
}

int main()
{
    limpiar_pantalla();

    imprimir_logos();
    pulsa_intro();
    //Lista_cursos lista_cursos_extension;

    //Menu ppal
    int option;
    while(true){
        limpiar_pantalla();
        imprimir_menu();
        std::cin>>option;

        switch(option){
            case 1:{
                //MOSTRAR LISTA CURSOS
                break;
            }
            case 9:{
                //SALIR
                return 0;
            }

            default:{
                //LA OPCION NO EXISTE O ES INVALIDA
                std::cout<<"[ ERROR ] Selecciona una opcion!"<<std::endl;
                std::cout<<"(Pulse INTRO)"<<std::endl;
                pulsa_intro();
                break;
            }

        }
    }
    return 0;
}
