add_library(usuario_registrado usuario_registrado.cc usuario_registrado.h)
target_include_directories(usuario_registrado PUBLIC
                          ${CMAKE_CURRENT_LIST_DIR}
                          ${PROJECT_SOURCE_DIR}/src/usuario)

target_link_libraries(usuario_registrado usuario)

