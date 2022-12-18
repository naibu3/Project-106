/*
lista_cursos.cc

Clase que implementa un listado con todos los cursos de extension y metodos
para su manejo.
*/

#include "lista_cursos.h"
#include "curso.h"


bool Lista_cursos::add_curso(Curso curso){

    std::string id_curso =curso.get_id();

    std::list<Curso>::iterator it;
    for(it = lista_cursos_.begin(); it != lista_cursos_.end(); it++){
        if(it->get_id()==id_curso){
            return false;       //el curso ya se encuentra en la lista
        }
    }
    lista_cursos_.push_back(curso);
    return true;
}

Curso Lista_cursos::get_curso(std::string id){

    std::list<Curso>::iterator it;
    for(it = lista_cursos_.begin(); it != lista_cursos_.end(); it++){
        if(it->get_id()==id){
            
            return (*it);
        }
    }
}

bool Lista_cursos::remove_curso(std::string id){

    std::list<Curso>::iterator it;
    for(it = lista_cursos_.begin(); it != lista_cursos_.end(); it++){
        if(it->get_id()==id){
            lista_cursos_.erase(it);
            return true;
        }
    }
    return false;               //el curso no esta en la lista
}

bool Lista_cursos::remove_curso(Curso curso){return remove_curso(curso.get_id());}

/*------------------------------------------------------------*/

bool Lista_cursos::escribir_datos(){

    std::fstream file;
    file.open("lista_cursos.txt");

    if(file.is_open()){

        std::list<Curso>::iterator it;
        for(it = lista_cursos_.begin(); it != lista_cursos_.end(); it++){

            file <<it->get_id()<<"\n";
            file <<it->get_name()<<"\n";
            file << it->get_year()<<"\n";
            file << it->get_month()<<"\n";
            file << it->get_day()<<"\n";
            file << it->get_ponente()<<"\n";
            file << it->get_estudio()<<"\n";
            file << it->get_descripcion()<<"\n";
            file << it->get_lugar()<<"\n";
            file << it->get_aula()<<"\n";
            file << it->get_aforo()<<"\n";
            
            //Guardar usuarios
            std::list<std::string>::iterator user;
            for( user = (it->get_lista_inscritos()).begin(); user != (it->get_lista_inscritos()).end(); user++){
                file<<(*user)<<std::endl;
            }
            file << "\n";
        }

        file.close();
        return true;
    }
    else return false;

}

//cada vez que se inicie el programa hay que leer los datos del fichero
bool Lista_cursos::leer_datos(){

    lista_cursos_.clear();
    
    std::ifstream file;
    file.open("lista_cursos.txt");
    
    if(file.is_open()){
        std::string linea;
        while(!file.eof()){

            std::getline(file, linea); std::string id=linea;
            std::getline(file, linea); std::string name=linea;
            std::getline(file, linea); int year=std::stoi(linea);
            std::getline(file, linea); int month=std::stoi(linea);
            std::getline(file, linea); int day=std::stoi(linea);
            std::getline(file, linea); std::string ponente=linea;
            std::getline(file, linea); std::string estudio=linea;
            std::getline(file, linea); std::string duracion=linea;
            std::getline(file, linea); std::string descripcion=linea;
            std::getline(file, linea); std::string lugar=linea;
            std::getline(file, linea); std::string aula=linea;
            std::getline(file, linea); int aforo=std::stoi(linea);

            Curso curso(id, name, year, month, day, ponente, estudio, duracion,
                        descripcion, lugar, aula, aforo);

            while(std::getline(file, linea)){
                
                if(linea==""){
                    break;
                }
                curso.inscribir_usuario(linea);
            }

            add_curso(curso);
        }
        file.close();
        return true;
    }
    else return false;

}
