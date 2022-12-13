add_library(usuario_registrado usuario_registrado.cc usuario_registrado.h)
target_include_directories(usuario_registrado PUBLIC
                          ${CMAKE_CURRENT_LIST_DIR}
                          ${PROJECT_SOURCE_DIR}/src/usuario
                          ${PROJECT_SOURCE_DIR}/src/lista_cursos
                          ${PROJECT_SOURCE_DIR}/src/curso)

target_link_libraries(usuario_registrado usuario lista_cursos curso)

