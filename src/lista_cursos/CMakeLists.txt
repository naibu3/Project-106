add_library(lista_cursos lista_cursos.cc lista_cursos.h)
target_include_directories(lista_cursos PUBLIC
                          ${CMAKE_CURRENT_LIST_DIR}
                          ${PROJECT_SOURCE_DIR}/src/curso)

target_link_libraries(lista_cursos curso)