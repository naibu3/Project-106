/*
lista_cursos.cc

Clase que implementa un listado con todos los cursos de extension y metodos
para su manejo.
*/

#include "lista_cursos.h"
#include "curso.h"
#include <filesystem>

bool IsNumber(std::string text);

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

void Lista_cursos::borrar_lista(){
    lista_cursos_.clear();
}

/*------------------------------------------------------------*/

bool Lista_cursos::escribir_datos(){

    std::ofstream file;
    file.open("lista_cursos.txt", std::fstream::out);

    if(file.is_open()){

        std::list<Curso>::iterator it;
        for(it = lista_cursos_.begin(); it != lista_cursos_.end(); it++){

            file <<(it->get_id())<<std::endl;
            file <<(it->get_name())<<std::endl;
            file <<(it->get_year())<<std::endl;
            file <<(it->get_month())<<std::endl;
            file <<(it->get_day())<<std::endl;
            file <<(it->get_ponente())<<std::endl;
            file <<(it->get_estudio())<<std::endl;
            file <<(it->get_duracion())<<std::endl;
            file <<(it->get_descripcion())<<std::endl;
            file <<(it->get_lugar())<<std::endl;
            file <<(it->get_aula())<<std::endl;
            file <<(it->get_aforo())<<std::endl;

            //Guardar usuarios
            /*std::list<std::string>::iterator user;
            if( !(it->get_lista_inscritos()).empty() ){
                for( user = (it->get_lista_inscritos()).begin(); user != (it->get_lista_inscritos()).end(); user++){
                    file<<(*user)<<" ";
                }
            }*/
            file << std::endl;
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
    std::string linea;
    std::string token;
    std::string id, name, year, month, day, ponente, estudio, duracion, descripcion, lugar, aula, aforo;

    file.open("lista_cursos.txt", std::fstream::in);
    
    if(file.is_open()){
        while(!file.eof()){

            std::getline(file, linea); id=linea;
            if(linea==""){break;}
            std::cout<<"ID -> "<<linea<<std::endl;
            std::getline(file, linea); name=linea;
            if(linea==""){break;}
            std::cout<<"NAME -> "<<linea<<std::endl;
            std::getline(file, linea); year=linea;
            if(linea==""){break;}
            std::cout<<"YEAR -> "<<linea<<std::endl;
            std::getline(file, linea); month=linea;
            if(linea==""){break;}
            std::cout<<"MES -> "<<linea<<std::endl;
            std::getline(file, linea); day=linea;
            if(linea==""){break;}
            std::cout<<"DIA -> "<<linea<<std::endl;
            std::getline(file, linea); ponente=linea;
            if(linea==""){break;}
            std::cout<<"PONENTE -> "<<linea<<std::endl;
            std::getline(file, linea); estudio=linea;
            if(linea==""){break;}
            std::cout<<"ESTUDIOS -> "<<linea<<std::endl;
            std::getline(file, linea); duracion=linea;
            if(linea==""){break;}
            std::cout<<"DURACION -> "<<linea<<std::endl;
            std::getline(file, linea); descripcion=linea;
            if(linea==""){break;}
            std::cout<<"DESCRIPCION -> "<<linea<<std::endl;
            std::getline(file, linea); lugar=linea;
            if(linea==""){break;}
            std::cout<<"LUGAR -> "<<linea<<std::endl;
            std::getline(file, linea); aula=linea;
            if(linea==""){break;}
            std::cout<<"AULA -> "<<linea<<std::endl;
            std::getline(file, linea); aforo=linea;
            if(linea==""){break;}
            std::cout<<"AFORO -> "<<linea<<std::endl;

            Curso curso(id, name, std::stoi(year), std::stoi(month), std::stoi(day),
                            ponente, estudio, duracion,
                            descripcion, lugar, aula, std::stoi(aforo));

            getline(file, linea);
            add_curso(curso);
        }
        file.close();
        return true;
    }
    else return false;

}