# GTest include code for fetch content over the internet 
include(FetchContent)

FetchContent_Declare(
  googletest
  GIT_REPOSITORY https://github.com/google/googletest.git
  GIT_TAG        release-1.11.0
)
FetchContent_MakeAvailable(googletest)
add_library(GTest::GTest INTERFACE IMPORTED)
target_link_libraries(GTest::GTest INTERFACE gtest_main)
# End GTest include code 

# Testing curso library
add_executable(curso_test curso_test.cc)
target_link_libraries(curso_test
 PRIVATE GTest::GTest curso)
add_test(curso_gtests curso_test)

# Testing lista_cursos library
add_executable(lista_cursos_test lista_cursos_test.cc)
target_link_libraries(lista_cursos_test
 PRIVATE GTest::GTest lista_cursos)
add_test(lista_cursos_gtests lista_cursos_test)
