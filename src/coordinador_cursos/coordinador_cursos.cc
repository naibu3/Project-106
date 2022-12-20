/*
coordinador_cursos.cc

Clase que representa al coordinador de cursos, quien gestiona los cursos.
*/

#include "coordinador_cursos.h"
#include <map>

#define N 200

void Coordinador_cursos::crear_curso(Lista_cursos &lista){

    std::string str, name, id, ponente, estudio, duracion, descripcion, lugar, aula;;
    int year, month, day, aforo;

    std::map<int, std::string> lista_estudios = {

        {0, "No"},
        {1, "Grado en Estudios Ingleses"},
        {2, "Doble Grado en Turismo y en Traducción e Interpretación"},
        {3, "Grado en Historia del Arte"},
        {4, "Grado en Filología Hispánica"},
        {5, "Grado en Traducción e Interpretación"},
        {6, "Doble Grado en Historia y en Historia del Arte"},
        {7, "Doble Grado en Traducción e Interpretación y en Filología Hispánica"},
        {8, "Grado en Cine y Cultura"},
        {9, "Grado en Historia"},
        {10, "Doble Grado en Educación Primaria y en Estudios Ingleses"},
        {11, "Grado en Gestión Cultural"},
        {12, "Doble Grado en Enología y en Ingeniería Agroalimentaria y del Medio Rural"},
        {13, "Grado en Bioquímica"},
        {14, "Grado en Biología"},
        {15, "Grado en Química"},
        {16, "Grado en Enología"},
        {17, "Grado en Física"},
        {18, "Grado en Ciencias Ambientales"},
        {19, "Grado en Relaciones Laborales y Recursos Humanos"},
        {20, "Doble Grado en Turismo y en Traducción e Interpretación"},
        {21, "Grado en Educación Social"},
        {22, "Grado en Educación Primaria"},
        {23, "Grado en Administración y Dirección de Empresas"},
        {24, "Doble Grado en Ingeniería Civil y en Administración y Dirección de Empresas"},
        {25, "Grado en Educación Infantil"},
        {26, "Doble Grado en Educación Primaria y en Estudios Ingleses"},
        {27, "Grado en Derecho"},
        {28, "Grado en Turismo"},
        {29, "Doble Grado en Derecho y en Administración y Dirección de Empresas"},
        {30, "Grado en Veterinaria"},
        {31, "Grado en Ciencia y Tecnología de los Alimentos"},
        {32, "Grado en Enfermería"},
        {33, "Grado en Medicina"},
        {34, "Grado en Psicología"},
        {35, "Grado en Fisioterapia"},
        {36, "Doble Grado en Ingeniería Forestal y en Ingeniería Agroalimentaria y del Medio Rural"},
        {37, "Grado en Ingeniería Forestal"},
        {38, "Grado en Ingeniería en Recursos Energéticos y Mineros"},
        {39, "Grado en Ingeniería Informática"},
        {40, "Grado en Ingeniería Electrónica Industrial"},
        {41, "Grado en Ingeniería Civil"},
        {42, "Grado en Ingeniería Eléctrica"},
        {43, "Grado en Ingeniería Agroalimentaria y del Medio Rural"},
        {44, "Grado en Ingeniería Mecánica"},
        {45, "Doble Grado en Ingeniería en Recursos Energéticos y Mineros y en Ingeniería Eléctrica"},
        {46, "Doble Grado en Ingeniería Civil y en Administración y Dirección de Empresas"},
        {47, "Doble Grado en Enología y en Ingeniería Agroalimentaria y del Medio Rural"},
        {48, "Doble Grado en Ingeniería Civil y en Ingeniería en Recursos Energéticos y Mineros"}
    };

    std::getline(std::cin,name);
    std::cout<<"Inserte nombre del curso:"<<std::endl; 
    std::getline(std::cin,name);

    std::cout<<"Inserte id del curso:"<<std::endl; 
    std::getline(std::cin,id);

    year=0;
    while(year==0){
        std::cout<<"Inserte año del curso (int):"<<std::endl; 
        std::cin>>year;
        std::cin.ignore();
        if(year<2022){
            year=0;
            std::cout<<"Año invalido"<<std::endl;}
    }

    month=0;
    while(month==0){
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
        std::cin.ignore();
        if(month>12||month<1){
            month=0;
            std::cout<<"Mes invalido"<<std::endl;}
    }

    day=0;
    while(day==0){
        std::cout<<"Inserte dia del curso (int):"<<std::endl; 
        std::cin>>day;
        std::cin.ignore();
         if(day<1||day>31){
            day=0;
            std::cout<<"Dia invalido"<<std::endl;}
    }   

    std::cout<<"Inserte ponente del curso:"<<std::endl; 
    std::getline(std::cin, ponente);

    //INSERCION ESTUDIOS
    int opcion=-1;
    while(opcion==-1){

        //imprimir lista de estudios
        auto iter_estudios = lista_estudios.begin();
        while (iter_estudios != lista_estudios.end()) {
            std::cout << iter_estudios->first << " -> "
                << iter_estudios->second << "\n";
            ++iter_estudios;}

        std::cin>>opcion;
        std::cin.ignore();
        if(opcion<0||opcion>48){
            opcion=-1;}
        estudio=lista_estudios.at(opcion);
    }           

    std::cout<<"Inserte duracion del curso:"<<std::endl; 
    std::getline(std::cin, duracion);

    std::cout<<"Inserte descripcion del curso(sin saltos de linea):"<<std::endl; 
    std::getline(std::cin,descripcion);

    std::cout<<"Inserte lugar del curso:"<<std::endl; 
    std::getline(std::cin, lugar);

    std::cout<<"Inserte aula del curso:"<<std::endl; 
    std::getline(std::cin,aula);

    std::cout<<"Inserte aforo del curso (int):"<<std::endl; 
    std::cin>>aforo;

    Curso curso(id, name, year, month, day, ponente, estudio,
                duracion, descripcion, lugar, aula, aforo);

    lista.add_curso(curso);
}

void Coordinador_cursos::borrar_curso(Lista_cursos &lista, std::string id){

    
    lista.remove_curso(id);
    lista.get_curso(id).~Curso();
}

void Coordinador_cursos::modificar_curso(Curso &curso){
    
    std::string name, id, ponente, estudio, duracion, descripcion, lugar, aula;;
    int year, month, day, aforo;
    

    int opcion;
    while(true){
        std::cout<<"Seleccione un campo que quiera modificar"<<std::endl;
        std::cout<<"0 = Salir"<<std::endl;
        std::cout<<"1 = Nombre del curso"<<std::endl;
        std::cout<<"2 = Año de inicio"<<std::endl;
        std::cout<<"3 = Mes de inicio"<<std::endl;
        std::cout<<"4 = Día de inicio"<<std::endl;
        std::cout<<"5 = Ponente"<<std::endl;
        std::cout<<"6 = Estudios requeridos"<<std::endl;
        std::cout<<"7 = Duración del curso"<<std::endl;
        std::cout<<"8 = Descripción del curso"<<std::endl;
        std::cout<<"9 = Lugar del curso"<<std::endl;
        std::cout<<"10 = Aula"<<std::endl;
        std::cout<<"11 = Aforo"<<std::endl;
        std::cout<<std::endl<<"Inserte una opcion y pulse intro: "<<std::endl;
        std::cin>>opcion;


        switch(opcion){
            //SALIR
            case 0:{
                char c;
                std::cout<<"¿Quieres seguir modificando el curso?[S/N]"<<std::endl;
                std::cin.clear();
                std::cin.ignore(std::numeric_limits<size_t>::max());
                while(c = std::cin.get()){
                    if(c == 'n' || c=='N') return;
                    else if (c == 'n' || c=='N') break;
                }
            }
            //NOMBRE
            case 1:{
                std::cout<<"Inserte nombre del curso:"<<std::endl; 
                std::getline(std::cin,name);
                curso.set_name(name);
                break;
            } 
            //YEAR
            case 2:{
                year=0;
                while(year==0){
                    std::cout<<"Inserte año del curso (int):"<<std::endl; 
                    std::cin>>year;
                    std::cin.ignore();
                    if(year<2022){
                        year=0;
                    std::cout<<"Año invalido"<<std::endl;}
                }
                curso.set_year(year);
                break;
            }
            //MES
            case 3:{
                month=0;
                while(month==0){
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
                    std::cin.ignore();
                    if(month>12||month<1){
                        month=0;
                    std::cout<<"Mes invalido"<<std::endl;}
                }
                curso.set_month(month);
                break;
            }
            //DAY
            case 4:{
                while(day==0){
                    std::cout<<"Inserte dia del curso (int):"<<std::endl; 
                    std::cin>>day;
                    std::cin.ignore();
                    if(day<1||day>31){
                        day=0;
                        std::cout<<"Dia invalido"<<std::endl;
                    }
                }
                curso.set_day(day);
                break;
            }
            //PONENTE
            case 5:{
                std::cout<<"Inserte ponente del curso:"<<std::endl; 
                std::getline(std::cin, ponente);
                curso.set_ponente(ponente);
                break;
            }
            //ESTUDIO
            case 6:{
                std::map<int, std::string> lista_estudios = {

                    {0, "No"}, {1, "Grado en Estudios Ingleses"},
                    {2, "Doble Grado en Turismo y en Traducción e Interpretación"},
                    {3, "Grado en Historia del Arte"},
                    {4, "Grado en Filología Hispánica"},
                    {5, "Grado en Traducción e Interpretación"},
                    {6, "Doble Grado en Historia y en Historia del Arte"},
                    {7, "Doble Grado en Traducción e Interpretación y en Filología Hispánica"},
                    {8, "Grado en Cine y Cultura"},
                    {9, "Grado en Historia"},
                    {10, "Doble Grado en Educación Primaria y en Estudios Ingleses"},
                    {11, "Grado en Gestión Cultural"},
                    {12, "Doble Grado en Enología y en Ingeniería Agroalimentaria y del Medio Rural"},
                    {13, "Grado en Bioquímica"},
                    {14, "Grado en Biología"},
                    {15, "Grado en Química"},
                    {16, "Grado en Enología"},
                    {17, "Grado en Física"},
                    {18, "Grado en Ciencias Ambientales"},
                    {19, "Grado en Relaciones Laborales y Recursos Humanos"},
                    {20, "Doble Grado en Turismo y en Traducción e Interpretación"},
                    {21, "Grado en Educación Social"},
                    {22, "Grado en Educación Primaria"},
                    {23, "Grado en Administración y Dirección de Empresas"},
                    {24, "Doble Grado en Ingeniería Civil y en Administración y Dirección de Empresas"},
                    {25, "Grado en Educación Infantil"},
                    {26, "Doble Grado en Educación Primaria y en Estudios Ingleses"},
                    {27, "Grado en Derecho"},
                    {28, "Grado en Turismo"},
                    {29, "Doble Grado en Derecho y en Administración y Dirección de Empresas"},
                    {30, "Grado en Veterinaria"},
                    {31, "Grado en Ciencia y Tecnología de los Alimentos"},
                    {32, "Grado en Enfermería"},
                    {33, "Grado en Medicina"},
                    {34, "Grado en Psicología"},
                    {35, "Grado en Fisioterapia"},
                    {36, "Doble Grado en Ingeniería Forestal y en Ingeniería Agroalimentaria y del Medio Rural"},
                    {37, "Grado en Ingeniería Forestal"},
                    {38, "Grado en Ingeniería en Recursos Energéticos y Mineros"},
                    {39, "Grado en Ingeniería Informática"},
                    {40, "Grado en Ingeniería Electrónica Industrial"},
                    {41, "Grado en Ingeniería Civil"},
                    {42, "Grado en Ingeniería Eléctrica"},
                    {43, "Grado en Ingeniería Agroalimentaria y del Medio Rural"},
                    {44, "Grado en Ingeniería Mecánica"},
                    {45, "Doble Grado en Ingeniería en Recursos Energéticos y Mineros y en Ingeniería Eléctrica"},
                    {46, "Doble Grado en Ingeniería Civil y en Administración y Dirección de Empresas"},
                    {47, "Doble Grado en Enología y en Ingeniería Agroalimentaria y del Medio Rural"},
                    {48, "Doble Grado en Ingeniería Civil y en Ingeniería en Recursos Energéticos y Mineros"}
                };

                int opcion=-1;
                while(opcion==-1){
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
                    std::cout<<"11 = Grado en Gestión Cultural"<<std::endl;
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
                    std::cin.ignore();
                    if(opcion<0||opcion>48){
                        opcion=-1;
                    }
                }

                curso.set_estudio(lista_estudios.at(opcion));
                break;
            }     
            //DURACION
            case 7:{
                std::cout<<"Inserte duracion del curso:"<<std::endl; 
                std::getline(std::cin, duracion);
                curso.set_duracion(duracion);
                break;
            }
            //DESCRIPCION
            case 8:{
                std::cout<<"Inserte descripcion del curso(sin saltos de linea):"<<std::endl; 
                std::getline(std::cin,descripcion);
                curso.set_descripcion(descripcion);
                break;
            }
            //LUGAR
            case 9:{
                std::cout<<"Inserte lugar del curso:"<<std::endl; 
                std::getline(std::cin, lugar);
                curso.set_lugar(lugar);
                break;
            }
            //AULA
            case 10:{
                std::cout<<"Inserte aula del curso:"<<std::endl; 
                std::getline(std::cin,aula);
                curso.set_aula(aula);
                break;
            }
            //AFORO
            case 11:{
                std::cout<<"Inserte aforo del curso (int):"<<std::endl; 
                std::cin>>aforo;
                curso.set_aforo(aforo);
                break;
            }
            default:{
                opcion=0;
            }
        }
    }
}
