add_library(gestor_cursos gestor_cursos.cc gestor_cursos.h)
target_include_directories(gestor_cursos PUBLIC
                          ${CMAKE_CURRENT_LIST_DIR})
add_executable(gestor_cursos_main gestor_cursos_main.cc)
target_link_libraries(gestor_cursos)