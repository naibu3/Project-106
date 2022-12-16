/*
coordinador_cursos.cc

Clase que representa al coordinador de cursos, quien gestiona los cursos.
*/

#include "coordinador_cursos.h"

void crear_curso(Lista_cursos &lista){

    std::string name;
    std::cout<<"Inserte nombre del curso:"; std::cin>>name;
    std::string id;
    std::cout<<"Inserte id del curso:"; std::cin>>name;
    int year;
    std::cout<<"Inserte año del curso (int):"; std::cin>>name;
    std::string month;
    std::cout<<"Inserte mes del curso:"; std::cin>>name;
    int day;
    std::cout<<"Inserte dia del curso (int):"; std::cin>>name;
    std::string ponente;
    std::cout<<"Inserte ponente del curso:"; std::cin>>name;
    std::string estudio;
    std::cout<<"Inserte estudios requeridos del curso:"; std::cin>>name;
    std::string duracion;
    std::cout<<"Inserte duracion del curso:"; std::cin>>name;
    std::string descripcion;
    std::cout<<"Inserte descripcion del curso:"; std::cin>>name;
    std::string lugar;
    std::cout<<"Inserte lugar del curso:"; std::cin>>name;
    std::string aula;
    std::cout<<"Inserte aula del curso:"; std::cin>>name;
    int aforo;
    std::cout<<"Inserte aforo del curso (int):"; std::cin>>name;

    Curso curso(id, name, year, month, day, ponente, estudio,
                duracion, descripcion, lugar, aula, aforo);

    lista.add_curso(curso);
}

void borrar_curso(Lista_cursos &lista, Curso curso){

    lista.remove_curso(curso.get_id());    
    curso.~Curso();

}


//bool modificar_curso();