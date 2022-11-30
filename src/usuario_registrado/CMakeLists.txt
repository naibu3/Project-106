add_library(curso curso.cc)
target_include_directories(curso PUBLIC
                          "${CMAKE_CURRENT_LIST_DIR}")
# ${CMAKE_CURRENT_LIST_DIR} dir. de este CMakeLisis.txt

target_link_libraries(curso)

