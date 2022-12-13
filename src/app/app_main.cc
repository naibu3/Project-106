#include "lista_cursos.h"
#include <string>
#include <iostream>

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

    std::cout<<"                  %@@%:.                "<<std::endl;
    std::cout<<"              .%888X8888S..             "<<std::endl;
    std::cout<<"          .t@88X88 @ 888X88@t;.         "<<std::endl;
}

void imprimir_menu(){
    std::cout<<std::endl;
    std::cout<<"    (1) - Ver cursos."<<std::endl;
    std::cout<<"    (9) - Salir."<<std::endl;
    std::cout<<std::endl;
    std::cout<<"Inserte eleccion y pulse intro: ";
}

int main()
{
    limpiar_pantalla();

    imprimir_logos();

    //Lista_cursos lista_cursos_extension;

    //Menu ppal
    int option;
    while(true){
        limpiar_pantalla();
        imprimir_menu();
        std::cin>>option;

        switch(option){
            case 1:{
                break;
            }

            case 9:{
                return 0;
            }

            default:{
                break;
            }

        }
    }

    return 0;
}
