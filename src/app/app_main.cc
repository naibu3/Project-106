#include "lista_cursos.h"

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

int main()
{
    limpiar_pantalla();

    imprimir_logos();


    Lista_cursos lista_cursos_extension;

    


    return 0;
}
