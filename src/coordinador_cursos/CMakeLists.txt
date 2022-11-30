add_library(coordinador_cursos coordinador_cursos.cc coordinador_cursos.h)
target_include_directories(coordinador_cursos PUBLIC
                          ${CMAKE_CURRENT_LIST_DIR}
                          ${PROJECT_SOURCE_DIR}/src/usuario_registrado)

target_link_libraries(coordinador_cursos usuario_registrado)