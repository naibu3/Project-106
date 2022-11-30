add_library(usuario usuario.cc)
target_include_directories(usuario PUBLIC
                          ${CMAKE_CURRENT_LIST_DIR})

target_link_libraries(usuario)