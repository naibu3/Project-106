#include "headers_main.h"

//SUBMENUS
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

//MENU LISTADO DE CURSOS (Usuario registrado)
void menu_lista_cursos(Lista_cursos* lista_cursos, Usuario_registrado& user){

    std::string option2;
    bool exit=false;

    while(!exit){

        //limpiar_pantalla();
        imprimir_listado_cursos(lista_cursos->get_list());
        imprimir_menu_lista_cursos(user.get_privilegios());

        std::cin>>option2;

        switch(std::stoi(option2)){
            case 1:{
                //INSCRIBIRSE
                if(user.get_privilegios()==1){
                    std::string eleccion;
                    std::cout<<"Inserte id del curso y pulse intro: ";
                    std::cin>>eleccion;
                    if(user.inscribirse( lista_cursos->get_curso(eleccion)) ){
                        std::cout<<std::endl<<"Inscrito con exito!"<<std::endl;
                        pulsa_intro();
                    }
                }
                
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

//MENU LISTADO DE CURSOS (Sobrecarga para el Coordinador de cursos)
void menu_lista_cursos(Lista_cursos* lista_cursos, Coordinador_cursos& user){

    std::string option2;
    bool exit=false;

    while(!exit){

        limpiar_pantalla();
        imprimir_listado_cursos(lista_cursos -> get_list());
        imprimir_menu_lista_cursos(user.get_privilegios());

        std::cin>>option2;

        switch(std::stoi(option2)){
            case 1:{
                //INSCRIBIRSE
                std::cout<<"[ ERROR ] El coordinador no debería inscribirse! Pulsa INTRO"<<std::endl;
                pulsa_intro();
                break;
            }
            case 2:{
                //CREAR CURSO
                user.crear_curso(*lista_cursos);
                break;
            }
            case 3:{
                //BORRAR CURSO
                //user.borrar_curso(*lista_cursos);
                break;
            }
            case 4:{
                //MODIFICAR CURSO
                //user.modificar_curso();
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

//MENU LISTADO DE CURSOS (Sobrecarga para el Usuario no registrado)
void menu_lista_cursos(Lista_cursos lista_cursos){

    std::string option2;
    bool exit=false;

    while(!exit){

        limpiar_pantalla();
        imprimir_listado_cursos(lista_cursos.get_list());
        imprimir_menu_lista_cursos(0);

        std::cin>>option2;

        switch(std::stoi(option2)){
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
    if(privilegios>0){
        std::cout<<"    (1) - Inscribirse."<<std::endl;
    }

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
