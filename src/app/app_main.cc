#include "headers_main.h"
#include <typeinfo>

//<==MAIN()============================================================================>
int main()
{

    //VARIABLES
    bool exit=false;
    bool error=false;
    std::string option;
    int noption;
    Lista_cursos lista_cursos_extension;

    std::string id_user;
    int privilegios_user;

    std::string linea;

    std::string username;
    std::string email;
    std::string estudios;

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
            case 1:
                privilegios_user=std::stoi(option);
                exit=true;
                break;
            
            case 2:
                privilegios_user=std::stoi(option);
                exit=true;
                break;
            
            case 3:
                std::cout<<std::endl<<"Aun no disponible, pulse intro."<<std::endl;
                pulsa_intro();
                break;
            
            case 9:
                limpiar_pantalla();
                return 0;
                break;
            
            default:
                privilegios_user=0;
                #define NOTLOGGED
                exit=true;
                error=true;
            
        }
    }
    if(privilegios_user>0){
        std::cout<<"Introduce tu id \n(igual que el de la UCO o 'admin' para coordinador): "; 
        std::cin>>id_user; 
        std::cout<<std::endl;
    }

    //CARGA DE USUARIOS
    if(privilegios_user==1){
        
        std::ifstream fichero_usuarios;
        fichero_usuarios.open("lista_usuarios.txt");
    
        if(fichero_usuarios.is_open()){

            while(true){
                
                if(fichero_usuarios.eof()){
                    
                    std::cout<<"[ ERROR ] No existe el usuario!"<<std::endl;
                    return 1;
                }

                std::getline(fichero_usuarios, linea);
                if(linea == id_user){
                    std::getline(fichero_usuarios, linea); username=linea;
                    std::getline(fichero_usuarios, linea); email=linea;
                    std::getline(fichero_usuarios, linea); estudios=linea;
                    std::getline(fichero_usuarios, linea);
                    break;
                }
                else{
                    
                    std::getline(fichero_usuarios, linea); 
                    std::getline(fichero_usuarios, linea);
                    std::getline(fichero_usuarios, linea); 
                    std::getline(fichero_usuarios, linea);
                }
            }
        }
    }
    else if(privilegios_user==2){
        
        std::ifstream fichero_admin;
        fichero_admin.open("lista_admins.txt");
    
        if(fichero_admin.is_open()){

            while(!fichero_admin.eof()){
                
                if(fichero_admin.eof()){
                    
                    std::cout<<"[ ERROR ] No existe el usuario!"<<std::endl;
                    return 1;
                }

                std::getline(fichero_admin, linea);
                if(linea == id_user){
                    std::getline(fichero_admin, linea); username=linea;
                    std::getline(fichero_admin, linea); email=linea;
                    std::getline(fichero_admin, linea); estudios=linea;
                    std::getline(fichero_admin, linea);
                    break;
                }
                else{
                    
                    std::getline(fichero_admin, linea);
                    std::getline(fichero_admin, linea);
                    std::getline(fichero_admin, linea);
                    std::getline(fichero_admin, linea);
                }
            }
        }
    }
    
    Coordinador_cursos coordinador(username, email, estudios);
    
    Usuario_registrado usuario(username, email, estudios);
    
    //Carga de la lista de cursos
    lista_cursos_extension.leer_datos();
    
    //<=BUCLE MENU PPAL=================================================================>
    error=false;
    while(true){

        limpiar_pantalla();
        
        //DEBUG
        if(privilegios_user==1) std::cout<<" User: "<< usuario.get_username()<<std::endl;
        if(privilegios_user==2) std::cout<<" User: "<<coordinador.get_id()<<" -> "<< coordinador.get_username()<<std::endl;
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
            case 1:
                //MOSTRAR LISTA CURSOS______________________________________________________________________
                if(privilegios_user==0) menu_lista_cursos(lista_cursos_extension);
                else if(privilegios_user==1) menu_lista_cursos(&lista_cursos_extension, usuario);
                else if(privilegios_user==2) menu_lista_cursos(lista_cursos_extension, coordinador);
                break;
            
            case 2:
                //VER MIS CURSOS______________________________________________________________________
                if(privilegios_user==1){
                    menu_mis_cursos(usuario);
                }
                else if(privilegios_user==2){
                    menu_mis_cursos(coordinador);
                }
                else{
                    std::cout<<"[ ERROR ] Debes estar inscrito para ver tus cursos!"<<std::endl;
                    std::cout<<"Pulsa INTRO"<<std::endl;
                }
                break;
            
            case 9:
                //SALIR_____________________________________________________________________________________
                limpiar_pantalla();
                return 0;
            

            default:
                //LA OPCION NO EXISTE O ES INVALIDA___________________________________________________________
                error=true;
            
        }
    }

    //ESTO NO DBERIA EJECUTARSE
    return 1;
}

