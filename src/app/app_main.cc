#include "lista_cursos.h"
#include "curso.h"
#include "usuario_registrado.h"
#include "usuario.h"
#include <map>
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
void imprimir_menu_login();

void menu_mis_cursos(Usuario_registrado &user){

    int option2;
    bool exit=false;

    do{

        limpiar_pantalla();
        imprimir_listado_cursos(user.get_cursos_inscritos());
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

    //VARIABLES
    bool exit=false;
    int option=0;
    Lista_cursos lista_cursos_extension;
    
    std::map<std::string, Usuario_registrado> lista_usuarios_registrados;
    //std::map<Coordinador_cursos> lista_coordinadores_recursos;

    std::string id_user;
    int privilegios_user;

    //PANTALLA DE INICIO
    limpiar_pantalla();
    imprimir_logos();
    pulsa_intro();
    
    //LOGIN
    exit=false;
    while(!exit){
        
        limpiar_pantalla();
        imprimir_menu_login();

        std::cin>>option;
        switch(option){
            case 1 || 2:{
                privilegios_user=option;
                exit=true;
                break;
            }
            case 3:{
                std::cout<<std::endl<<"Aun no disponible, pulse intro."<<std::endl;
                pulsa_intro();
                break;
            }
            case 9:{
                limpiar_pantalla();
                return 0;
                break;
            }
            default:{
                privilegios_user=0;
                exit=true;
                break;
            }
        }
    }

    //Comprobacion de existencia del usuario y creacion
    

    //BUCLE MENU PPAL
    while(true){

        limpiar_pantalla();
        std::cout<<privilegios_user<<std::endl;
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
                if(privilegios_user>1){
                    menu_mis_cursos( lista_usuarios_registrados.at(id_user) );
                }
                else{
                    std::cout<<"[ ERROR ] Debes estar inscrito para ver tus cursos!"<<std::endl;
                    std::cout<<"Pulsa INTRO"<<std::endl;
                }
                break;
            }
            case 9:{
                //SALIR
                limpiar_pantalla();
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
            a='a';
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

void imprimir_menu_login(){

    std::cout<<std::endl;
    std::cout<<"Inicio de sesion"<<std::endl;
    std::cout<<std::endl;
    std::cout<<"Que tipo de usuario es: "<<std::endl;
    std::cout<<std::endl;
    std::cout<<"    (1) - Usuario registrado"<<std::endl;
    std::cout<<"    (2) - Coordinador de cursos"<<std::endl;
    std::cout<<"    (3) - Coordinador de recursos"<<std::endl;
    std::cout<<std::endl;
    std::cout<<"Dejar en blanco para proceder sin registrarse"<<std::endl;
    std::cout<<std::endl;
    std::cout<<"    (9) - Salir"<<std::endl;

}
