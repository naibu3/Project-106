add_library(curso curso.cc curso.h)
target_include_directories(curso PUBLIC
                          ${CMAKE_CURRENT_LIST_DIR}
                          ${PROJECT_SOURCE_DIR}/src/usuario)

target_link_libraries(curso usuario)

