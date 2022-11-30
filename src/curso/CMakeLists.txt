add_library(curso curso.cc)
target_include_directories(curso PUBLIC
                          ${CMAKE_CURRENT_LIST_DIR})

target_link_libraries(curso)

