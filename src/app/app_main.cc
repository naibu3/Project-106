#include "lista_cursos.h"
#include "curso.h"
#include "usuario_registrado.h"
#include <string>
#include <iostream>
#include <fstream>

//PARA COMPATIBILIDAD AL LIMPIAR PANTALLA ENTRE WIN Y LINUS
#ifdef _WIN32
  #include<windows.h>
#endif  

//CABECERAS
void pulsa_intro();
void limpiar_pantalla();
void imprimir_logos();

void imprimir_menu_ppal();
void imprimir_listado_cursos(std::list<Curso> lista);
void imprimir_menu_mis_cursos();
void imprimir_menu_lista_cursos();

void menu_mis_cursos(Usuario_registrado* user){

    int option2;
    bool exit=false;

    do{

        limpiar_pantalla();
        imprimir_listado_cursos(user -> get_cursos_inscritos());
        imprimir_menu_mis_cursos();

        std::cin>>option2;

        switch(option2){
            case 1:{
                //DESINSCRIBIRSE
                
                break;
            }
            case 9:{
                //VOLVER
                exit=true;
                std::cout<<"[ SALIENDO ] Pulsa INTRO "<<std::endl;
                pulsa_intro();
                break;
            }

            default:{
                //LA OPCION NO EXISTE O ES INVALIDA
                std::cout<<"[ ERROR ] Selecciona una opcion!"<<std::endl;
                std::cout<<"(Pulse INTRO)"<<std::endl;
                pulsa_intro();
                break;
            }
        }

    }while(!exit);

}

void menu_lista_cursos(Lista_cursos* lista_cursos){

    int option2;
    bool exit=false;

    do{

        limpiar_pantalla();
        imprimir_listado_cursos(lista_cursos -> get_list());
        imprimir_menu_lista_cursos();

        std::cin>>option2;

        switch(option2){
            case 1:{
                //INSCRIBIRSE
                
                break;
            }
            case 9:{
                //VOLVER
                exit=true;
                std::cout<<"[ SALIENDO ] Pulsa INTRO "<<std::endl;
                pulsa_intro();
                break;
            }

            default:{
                //LA OPCION NO EXISTE O ES INVALIDA
                std::cout<<"[ ERROR ] Selecciona una opcion!"<<std::endl;
                std::cout<<"(Pulse INTRO)"<<std::endl;
                pulsa_intro();
                break;
            }
        }

    }while(!exit);

}

int main()
{
    //INICIALIZACION
    limpiar_pantalla();

    imprimir_logos();
    pulsa_intro();
    
    //LOGIN

    Lista_cursos lista_cursos_extension;

    //BUCLE MENU PPAL
    int option;
    while(true){

        limpiar_pantalla();
        imprimir_menu_ppal();
        std::cin>>option;

        switch(option){
            case 1:{
                //MOSTRAR LISTA CURSOS
                menu_lista_cursos(&lista_cursos_extension);
                break;
            }
            case 2:{
                //VER MIS CURSOS
                //menu_mis_cursos(mi_usuario);
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

    //ESTO NO DBERIA EJECUTARSE
    return 1;
}


//FUNCIONES

void pulsa_intro(){
    char a;
    while(a = std::cin.get()){
        if(a == '\n'){
            break;
        }
    }
}

void limpiar_pantalla(){
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

void imprimir_menu_ppal(){
    std::cout<<std::endl;
    std::cout<<"SISTEMA DE GESTION DE CURSOS DE EXTENSION"<<std::endl;
    std::cout<<"Menu Principal"<<std::endl;
    std::cout<<std::endl;
    std::cout<<"    (1) - Ver cursos."<<std::endl;
    std::cout<<"    (2) - Mis cursos."<<std::endl;
    std::cout<<"    (9) - Salir."<<std::endl;
    std::cout<<std::endl;
    std::cout<<"Inserte eleccion y pulse intro: ";
}

void imprimir_menu_lista_cursos(){

    std::cout<<std::endl;
    std::cout<<"    (1) - Inscribirse."<<std::endl;
    std::cout<<"    (9) - Volver."<<std::endl;
    std::cout<<std::endl;
    std::cout<<"Inserte eleccion y pulse intro: ";
}

void imprimir_menu_mis_cursos(){

    std::cout<<std::endl;
    std::cout<<"    (1) - Desinscribirse."<<std::endl;
    std::cout<<"    (9) - Volver."<<std::endl;
    std::cout<<std::endl;
    std::cout<<"Inserte eleccion y pulse intro: ";
}

void imprimir_listado_cursos(std::list<Curso> lista){
    
    std::cout<<std::endl;

    std::list<Curso>::iterator it_lista_cursos;
    if(!lista.empty()){
        
        //Si la lista tiene cursos, se listan;
        std::cout<<"Cursos disponibles"<<std::endl<<std::endl;

        for(it_lista_cursos=lista.begin(); it_lista_cursos!=lista.end(); it_lista_cursos++){

            std::cout<<"("<<(it_lista_cursos->get_id())<<")"
                            <<" - "<<(it_lista_cursos->get_name())<<std::endl;
        }
    
    }
    else{

        //Si no hay cursos o hay algun error se comunica al usuario.
        std::cout<<"NO HAY CURSOS O NO HA SIDO POSIBLE RECUPERARLOS"<<std::endl;
    }
    
}