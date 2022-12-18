/*
coordinador_cursos.cc

Clase que representa al coordinador de cursos, quien gestiona los cursos.
*/

#include "coordinador_cursos.h"

#define N 200

void crear_curso(Lista_cursos &lista){

    std::string name;
    std::cout<<"Inserte nombre del curso:"<<std::endl; 
    getline(cin,name);
    std::string id;
    std::cout<<"Inserte id del curso:"<<std::endl; 
    getline(cin,id);
    int year=0;
    while(year=0){
        std::cout<<"Inserte año del curso (int):"<<std::endl; 
        std::cin>>year;
        if(year<2022){
            year=0;
            std::cout<<"Año invalido"std::endl;}
    }
    int month=0;
    while(month=0){
        std::cout<<"Inserte el mes del curso en formato numerico:"<<std::endl;
        std::cout<<"1 = Enero"<<std::endl;
        std::cout<<"2 = Febrero"<<std::endl;
        std::cout<<"3 = Marzo"<<std::endl;
        std::cout<<"4 = Abril"<<std::endl;
        std::cout<<"5 = Mayo"<<std::endl;
        std::cout<<"6 = Junio"<<std::endl;
        std::cout<<"7 = Julio"<<std::endl;
        std::cout<<"8 = Agosto"<<std::endl;
        std::cout<<"9 = Septiembre"<<std::endl;
        std::cout<<"10 = Octubre"<<std::endl;
        std::cout<<"11 = Noviembre"<<std::endl;
        std::cout<<"12 = Diciembre"<<std::endl;
        std::cin>>month;
        if(month>12||month<1){
            month=0;
            std::cout<<"Mes invalido"std::endl;}
    }
    int day=0;
    while(day=0){
        std::cout<<"Inserte dia del curso (int):"<<std::endl; 
        std::cin>>day;
         if(day<1||day>31){
            day=0;
            std::cout<<"Dia invalido"std::endl;}
    }   
    std::string ponente;
    std::cout<<"Inserte ponente del curso:"<<std::endl; 
    getline(cin, ponente);
    std::string estudio;
    int opcion=0;
    std::cout<<"Introduzca el grado requerido para el curso:"<<std::endl; //Menú para elegir entre los grados que ofrece la UCO
    std::cout<<"1 = Grado en Estudios Ingleses"<<std::endl;
    std::cout<<"2 = Doble Grado en Turismo y en Traducción e Interpretación"<<std::endl;
    std::cout<<"3 = Grado en Historia del Arte"<<std::endl;
    std::cout<<"4 = Grado en Filología Hispánica"<<std::endl;
    std::cout<<"5 = Grado en Traducción e Interpretación"<<std::endl;
    std::cout<<"6 = Doble Grado en Historia y en Historia del Arte"<<std::endl;
    std::cout<<"7 = Doble Grado en Traducción e Interpretación y en Filología Hispánica"<<std::endl;
    std::cout<<"8 = Grado en Cine y Cultura"<<std::endl;
    std::cout<<"9 = Grado en Historia"<<std::endl;
    std::cout<<"10 = Doble Grado en Educación Primaria y en Estudios Ingleses"<<std::endl;
    std::cout<<"11 = Grado en Gestión Cultural
    std::cout<<"12 = Doble Grado en Enología y en Ingeniería Agroalimentaria y del Medio Rural"<<std::endl;
    std::cout<<"13 = Grado en Bioquímica"<<std::endl;
    std::cout<<"14 = Grado en Biología"<<std::endl;
    std::cout<<"15 = Grado en Química"<<std::endl;
    std::cout<<"16 = Grado en Enología"<<std::endl;
    std::cout<<"17 = Grado en Física"<<std::endl;
    std::cout<<"18 = Grado en Ciencias Ambientales"<<std::endl;
    std::cout<<"19 = Grado en Relaciones Laborales y Recursos Humanos"<<std::endl;
    std::cout<<"20 = Doble Grado en Turismo y en Traducción e Interpretación"<<std::endl;
    std::cout<<"21 = Grado en Educación Social"<<std::endl;
    std::cout<<"22 = Grado en Educación Primaria"<<std::endl;
    std::cout<<"23 = Grado en Administración y Dirección de Empresas"<<std::endl;
    std::cout<<"24 = Doble Grado en Ingeniería Civil y en Administración y Dirección de Empresas"<<std::endl;
    std::cout<<"25 = Grado en Educación Infantil"<<std::endl;
    std::cout<<"26 = Doble Grado en Educación Primaria y en Estudios Ingleses"<<std::endl;
    std::cout<<"27 = Grado en Derecho"<<std::endl;
    std::cout<<"28 = Grado en Turismo"<<std::endl;
    std::cout<<"29 = Doble Grado en Derecho y en Administración y Dirección de Empresas"<<std::endl;
    std::cout<<"30 = Grado en Veterinaria"<<std::endl;
    std::cout<<"31 = Grado en Ciencia y Tecnología de los Alimentos"<<std::endl;
    std::cout<<"32 = Grado en Enfermería"<<std::endl;
    std::cout<<"33 = Grado en Medicina"<<std::endl;
    std::cout<<"34 = Grado en Psicología"<<std::endl;
    std::cout<<"35 = Grado en Fisioterapia"<<std::endl;
    std::cout<<"36 = Doble Grado en Ingeniería Forestal y en Ingeniería Agroalimentaria y del Medio Rural"<<std::endl;
    std::cout<<"37 = Grado en Ingeniería Forestal"<<std::endl;
    std::cout<<"38 = Grado en Ingeniería en Recursos Energéticos y Mineros"<<std::endl;
    std::cout<<"39 = Grado en Ingeniería Informática"<<std::endl;
    std::cout<<"40 = Grado en Ingeniería Electrónica Industrial"<<std::endl;
    std::cout<<"41 = Grado en Ingeniería Civil"<<std::endl;
    std::cout<<"42 = Grado en Ingeniería Eléctrica"<<std::endl;
    std::cout<<"43 = Grado en Ingeniería Agroalimentaria y del Medio Rural"<<std::endl;
    std::cout<<"44 = Grado en Ingeniería Mecánica"<<std::endl;
    std::cout<<"45 = Doble Grado en Ingeniería en Recursos Energéticos y Mineros y en Ingeniería Eléctrica"<<std::endl;
    std::cout<<"46 = Doble Grado en Ingeniería Civil y en Administración y Dirección de Empresas"<<std::endl;
    std::cout<<"47 = Doble Grado en Enología y en Ingeniería Agroalimentaria y del Medio Rural"<<std::endl;
    std::cout<<"48 = Doble Grado en Ingeniería Civil y en Ingeniería en Recursos Energéticos y Mineros"<<std::endl;
    std::cin>>opcion;
    if(opcion<1||opcion>48){
        opcion=0;}
    switch(opcion){
        case 1:
            estudio="Grado en Estudios Ingleses";
            break;
        case 2:
            estudio="Doble Grado en Turismo y en Traducción e Interpretación";
            break;
        case 3:
            estudio="Grado en Historia del Arte";
            break;
        case 4:
            estudio="Grado en Filología Hispánica";
            break;
        case 5:
            estudio="Grado en Traducción e Interpretación";
            break;
        case 6:
            estudio="Doble Grado en Historia y en Historia del Arte";
            break;
        case 7:
            estudio="Doble Grado en Traducción e Interpretación y en Filología Hispánica";
            break;
        case 8:
            estudio="Grado en Cine y Cultura";
            break;
        case 9:
             estudio="Grado en Historia";
            break;
        case 10:
            estudio="Doble Grado en Educación Primaria y en Estudios Ingleses";
            break;
        case 11:
            estudio="Grado en Gestión Cultural";
            break;
        case 12:
            estudio="Doble Grado en Enología y en Ingeniería Agroalimentaria y del Medio Rural";
            break;
        case 13:
            estudio="Grado en Bioquímica";
            break;
        case 14:
            estudio="Grado en Biología";
            break;
        case 15:
            estudio="Grado en Química";
            break;
        case 16:
            estudio=" ";
            break;
        case 17:
            estudio=" ";
            break;
         case 18:
            estudio=" ";
            break;
        case 19:
            estudio=" ";
            break;
        case 20:
            estudio=" ";
            break;
        case 21:
            estudio=" ";
            break;
        case 22:
            estudio=" ";
            break;
         case 23:
            estudio=" ";
            break;
        case 24:
            estudio=" ";
            break;
        case 25:
            estudio=" ";
            break;
        case 26:
            estudio=" ";
            break;
        case 27:
            estudio=" ";
            break;
         case 28:
            estudio=" ";
            break;
        case 29:
            estudio=" ";
            break;
        case 30:
            estudio=" ";
            break;
        case 31:
            estudio=" ";
            break;
        case 32:
            estudio=" ";
            break;
         case 33:
            estudio=" ";
            break;
        case 34:
            estudio=" ";
            break;
        case 35:
            estudio=" ";
            break;
        case 36:
            estudio=" ";
            break;
        case 37:
            estudio=" ";
            break;
         case 38:
            estudio=" ";
            break;
        case 39:
            estudio=" ";
            break;
        case 40:
            estudio=" ";
            break;
        case 41:
            estudio=" ";
            break;
        case 42:
            estudio=" ";
            break;
         
    
            
    
            
    std::cin>>name;
            
    std::string duracion;
            
    std::cout<<"Inserte duracion del curso:"; std::cin>>name;
            
    std::string descripcion;
            
    std::cout<<"Inserte descripcion de
        l curso(sin saltos de linea):"; std::cin>>name;
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
