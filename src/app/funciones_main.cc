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
                std::string eleccion;
                std::cout<<"Introduce el id del curso que quieras abandonar y pulsa intro: ";
                std::cin>>eleccion;

                user.desinscribirse(eleccion);

                std::cout<<"HOLA"<<std::endl;
                std::cout<<"[ OK ] Datos modificados."<<std::endl;
                break;
                std::cout<<"[ ERROR ] No se han podido modificar los datos."<<std::endl;
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
    bool ver_curso=false;

    while(!exit){

        limpiar_pantalla();
        imprimir_listado_cursos(lista_cursos->get_list());
        imprimir_menu_lista_cursos(user.get_privilegios());

        std::cin>>option2;

        switch(std::stoi(option2)){
            //INFO CURSO
            case 0:{
                ver_curso=true;
                break;
            }
            case 1:{
                //INSCRIBIRSE
                if(user.get_privilegios()==1){
                    std::string eleccion;
                    std::cout<<"Inserte id del curso y pulse intro: ";
                    std::cin>>eleccion;
                    if(user.inscribirse( lista_cursos->get_curso(eleccion)) ){
                        ( lista_cursos->get_curso(eleccion)).inscribir_usuario(user.get_id());
                        lista_cursos->escribir_datos();
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
        if(ver_curso){
            std::string id;
            std::cout<<"Introduce el id de un curso y pulsa intro: ";
            std::cin>>id;
            limpiar_pantalla();
            imprimir_curso(lista_cursos.get_curso(id));
            std::cout<<"Teclea \'s\' para salir"<<std::endl;
            std::cin>>option2;
            ver_curso=false;
        }
    }
}

//MENU LISTADO DE CURSOS (Sobrecarga para el Coordinador de cursos)
void menu_lista_cursos(Lista_cursos& lista_cursos, Coordinador_cursos& user){

    std::string option2;
    bool exit=false;
    bool ver_curso=false;

    while(!exit){

        limpiar_pantalla();
        //std::cout<<"PRIVILEGIOS"<<user.get_privilegios()<<std::endl;//DEBUG
        imprimir_listado_cursos(lista_cursos.get_list());
        imprimir_menu_lista_cursos(user.get_privilegios());

        std::cin>>option2;

        switch(std::stoi(option2)){
            //INFO CURSO
            case 0:{
                ver_curso=true;
                break;
            }
            case 1:{
                //INSCRIBIRSE
                std::cout<<"[ ERROR ] El coordinador no debería inscribirse! Pulsa INTRO"<<std::endl;
                pulsa_intro();
                break;
            }
            case 2:{
                //CREAR CURSO
                user.crear_curso(lista_cursos);
                lista_cursos.escribir_datos();
                break;
            }
            case 3:{
                //BORRAR CURSO
                std::string eleccion;
                std::cout<<"Introduce el id del curso que quieras borrar y pulsa intro: ";
                std::cin>>eleccion;
                user.borrar_curso(lista_cursos, eleccion);
                //lista_cursos.escribir_datos();
                std::cout<<"[ OK ] Datos borrados."<<std::endl;
                break;
            }
            case 4:{
                //MODIFICAR CURSO
                std::string eleccion;
                std::cout<<"Introduce el id del curso que quieras modificar y pulsa intro: ";
                std::cin>>eleccion; 
                limpiar_pantalla();
                Curso aux=lista_cursos.get_curso(eleccion);
                user.modificar_curso( aux );
                lista_cursos.escribir_datos();
                std::cout<<"[ OK ] Datos modificados."<<std::endl;
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
        if(ver_curso){
            std::string id;
            std::cout<<"Introduce el id de un curso y pulsa intro: ";
            std::cin>>id;
            limpiar_pantalla();
            imprimir_curso(lista_cursos.get_curso(id));
            std::cout<<"Teclea \'s\' para salir"<<std::endl;
            std::cin>>option2;
            ver_curso=false;
        }
    }
}

//MENU LISTADO DE CURSOS (Sobrecarga para el Usuario no registrado)
void menu_lista_cursos(Lista_cursos lista_cursos){

    std::string option2;
    bool exit=false;
    bool ver_curso=false;
    while(!exit){

        limpiar_pantalla();
        imprimir_listado_cursos(lista_cursos.get_list());
        imprimir_menu_lista_cursos(0);

        std::cin>>option2;

        switch(std::stoi(option2)){
            //INFO CURSO
            case 0:{
                ver_curso=true;
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
        if(ver_curso){
            std::string id;
            std::cout<<"Introduce el id de un curso y pulsa intro: ";
            std::cin>>id;
            limpiar_pantalla();
            imprimir_curso(lista_cursos.get_curso(id));
            std::cout<<"Teclea \'s\' para salir"<<std::endl;
            std::cin>>option2;
            ver_curso=false;
        }
    }
}


bool pulsa_intro(){
    char a;
    std::cin.clear();
    std::cin.ignore(std::numeric_limits<size_t>::max());
    while(a = std::cin.get()){
        if(a == '\n'){
            a='a';
            return true;
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
    std::cout<<"    (0) - Ver curso."<<std::endl;
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

void imprimir_curso(Curso c){

    std::cout<<"("<<c.get_id()<<") - "<<c.get_name()<<std::endl<<std::endl;
    std::cout<<"Fecha "<<c.get_day()<<"/"<<c.get_month()<<"/"<<c.get_year()<<std::endl;
    std::cout<<"Duracion"<<c.get_duracion()<<std::endl;
    std::cout<<"Estudios necesarios: "<<c.get_estudio()<<std::endl;
    std::cout<<"Ponente: "<<c.get_ponente()<<std::endl;
    std::cout<<"Descripcion: "<<c.get_descripcion()<<std::endl;
    std::cout<<"Lugar: "<<c.get_lugar()<<", "<<c.get_aula()<<std::endl;
    std::cout<<"Aforo: "<<c.get_aforo()<<std::endl;
}