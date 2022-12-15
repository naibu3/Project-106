add_executable(app_main app_main.cc)
target_include_directories(app_main PUBLIC
                            ${CMAKE_CURRENT_LIST_DIR}
                            ${PROJECT_SOURCE_DIR}/src/lista_cursos
                            ${PROJECT_SOURCE_DIR}/src/usuario_registrado
                            ${PROJECT_SOURCE_DIR}/src/usuario
                            ${PROJECT_SOURCE_DIR}/src/curso)
target_link_libraries(app_main lista_cursos usuario_registrado curso)
