add_library(lista_cursos lista_cursos.cc lista_cursos.h)
target_include_directories(lista_cursos PUBLIC
                          ${CMAKE_CURRENT_LIST_DIR}
                          ${PROJECT_SOURCE_DIR}/src/curso)
add_executable(lista_main lista_main.cc)
target_link_libraries(lista_main lista_cursos curso)
target_link_libraries(lista_cursos curso)