#include "lista_cursos.h"

int main()
{
    Lista_cursos lista;
    Curso curso1("1");
    Curso curso2("2");
    
    lista.add_curso(curso1);
    lista.add_curso(curso2);

    std::cout<<curso1.get_id()<<std::endl;
    std::cout<<curso2.get_id()<<std::endl;

    lista.escribir_datos();

    lista.borrar_lista();

    lista.leer_datos();

    std::list<Curso>::iterator it;
    //for(it=(lista.get_list()).begin(); it!=(lista.get_list()).end(); it++){
    //    std::cout<<"ID: "<<(it->get_id())<<std::endl;
    //}
    return 0;
}
