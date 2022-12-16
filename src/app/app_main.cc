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

void imprimir_menu_ppal(int privilegios);
void imprimir_listado_cursos(std::list<Curso> lista);
void imprimir_menu_mis_cursos();
void imprimir_menu_lista_cursos(int privilegios);
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

void menu_lista_cursos(Lista_cursos* lista_cursos, int privilegios){

    std::string option2;
    bool exit=false;

    while(!exit){

        limpiar_pantalla();
        imprimir_listado_cursos(lista_cursos -> get_list());
        imprimir_menu_lista_cursos(privilegios);

        std::cin>>option2;

        switch(std::stoi(option2)){
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
    }
}

int main()
{

    //VARIABLES
    bool exit=false;
    bool error=false;
    std::string option;
    Lista_cursos lista_cursos_extension;
    //std::list<Coordinador_cursos> lista_coordinadores_cursos;
    
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
    error=false;
    while(!exit){
        
        limpiar_pantalla();
        imprimir_menu_login();

        std::cin>>option;
        switch(std::stoi(option)){
            case 1:{
                privilegios_user=std::stoi(option);
                exit=true;
                break;
            }
            case 2:{
                privilegios_user=std::stoi(option);
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
                error=true;
            }
        }
    }

    //CARGA DE USUARIOS
    if(privilegios_user==1){
        
        std::ifstream fichero_usuarios;
        fichero_usuarios.open("lista_usuarios.txt");
    
        if(fichero_usuarios.is_open()){

            std::string username;
            std::string email;
            std::string estudios;

            std::string linea;
            while(!fichero_usuarios.eof()){
                
                getline(fichero_usuarios, linea); username=linea;
                getline(fichero_usuarios, linea); email=linea;
                getline(fichero_usuarios, linea); estudios=linea;
                getline(fichero_usuarios, linea);

                Usuario_registrado user_it(username, email, estudios);
                lista_usuarios_registrados.insert(std::pair<std::string, Usuario_registrado>(user_it.get_id(), user_it));
            }
        }
    }
    

    //Carga de la lista de cursos
    lista_cursos_extension.leer_datos();

    //BUCLE MENU PPAL
    error=false;
    while(true){

        limpiar_pantalla();
        
        //DEBUG
        std::cout<<privilegios_user<<std::endl;
        auto iter = lista_usuarios_registrados.begin();
        while (iter != lista_usuarios_registrados.end()) {
            std::cout<<"User:"<<(iter->second).get_username()<<std::endl;
            iter++;
        }
        //DEBUG END

        imprimir_menu_ppal(privilegios_user);
        
        if(error){
            //LA OPCION NO EXISTE O ES INVALIDA
            std::cout<<std::endl<<"[ ERROR ] Selecciona una opcion!"<<std::endl<<"(Pulse INTRO)"<<std::endl;
            pulsa_intro();
            error=false;
        }

        std::cin>>option;
        switch(std::stoi(option)){
            case 1:{
                //MOSTRAR LISTA CURSOS
                menu_lista_cursos(&lista_cursos_extension, privilegios_user);
                break;
            }
            case 2:{
                //VER MIS CURSOS
                if(privilegios_user>1){
                    menu_mis_cursos( lista_usuarios_registrados.at(id_user));
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
                error=true;
            }
        }
    }

    //ESTO NO DBERIA EJECUTARSE
    return 1;
}


//FUNCIONES

void pulsa_intro(){
    char a;
    std::cin.clear();
    std::cin.ignore(std::numeric_limits<size_t>::max());
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

void imprimir_menu_ppal(int privilegios){
    std::cout<<std::endl;
    std::cout<<"SISTEMA DE GESTION DE CURSOS DE EXTENSION"<<std::endl;
    std::cout<<"Menu Principal"<<std::endl;
    std::cout<<std::endl;
    std::cout<<"    (1) - Ver cursos."<<std::endl;

    if(privilegios>0){std::cout<<"    (2) - Mis cursos."<<std::endl;}    
    
    std::cout<<"    (9) - Salir."<<std::endl;
    std::cout<<std::endl;
    std::cout<<"Inserte eleccion y pulse intro: ";
}

void imprimir_menu_lista_cursos(int privilegios){

    std::cout<<std::endl;
    std::cout<<"    (1) - Inscribirse."<<std::endl;

    if(privilegios>1){
        std::cout<<"    (2) - Crear curso."<<std::endl;
        std::cout<<"    (3) - Borrar curso."<<std::endl;
        std::cout<<"    (4) - Modificar curso."<<std::endl;
    }
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
    std::cout<<"Pulsa 0 para proceder sin registrarse"<<std::endl;
    std::cout<<std::endl;
    std::cout<<"    (9) - Salir"<<std::endl;
    std::cout<<"Introduce una opcion y pulsa intro: ";

}
