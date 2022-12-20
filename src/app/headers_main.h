#include "lista_cursos.h"
#include "curso.h"
#include "usuario_registrado.h"
#include "coordinador_cursos.h"
#include "usuario.h"
#include <map>
#include <string>
#include <iostream>
#include <fstream>

//PARA COMPATIBILIDAD AL LIMPIAR PANTALLA ENTRE WIN Y LINUS
#ifdef _WIN32
  #include<windows.h>
#endif  

bool pulsa_intro();
void limpiar_pantalla();
void imprimir_logos();

void imprimir_menu_ppal(int privilegios);
void imprimir_listado_cursos(std::list<Curso> lista);
void imprimir_menu_mis_cursos();
void imprimir_menu_lista_cursos(int privilegios);
void imprimir_menu_login();
void imprimir_curso(Curso c);

void menu_mis_cursos(Usuario_registrado &user);
void menu_lista_cursos(Lista_cursos* lista_cursos, Usuario_registrado &user);
void menu_lista_cursos(Lista_cursos &lista_cursos, Coordinador_cursos &user);
void menu_lista_cursos(Lista_cursos lista_cursos);