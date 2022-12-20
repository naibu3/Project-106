#include <lista_cursos.h>
#include "gtest/gtest.h"


TEST(Lista_cursos, AddCurso) {
    Curso c1("000", "Curso Prueba", 2003, 3, 24, "Manolo", "No", "34 dias", "descripcion",
                "edificio7", "aula2", 45);

    Lista_cursos lista;

    lista.add_curso(c1);

    EXPECT_EQ( (lista.get_list()).size(), 1 );
}


TEST(Lista_cursos, RemoveCurso) {
    Curso c1("000");
    Curso c2("001");
    Lista_cursos lista;

    lista.add_curso(c1);
    lista.add_curso(c2);

    lista.remove_curso(c1.get_id());

    EXPECT_EQ( (lista.get_list()).size(), 1 );
}

TEST(Lista_cursos, GetCurso) {
    Curso c1("000");
    Curso c2("001");
    Lista_cursos lista;

    lista.add_curso(c1);
    lista.add_curso(c1);
    lista.add_curso(c2);

    EXPECT_EQ( (lista.get_curso("000")).get_name(), "empty" );
    EXPECT_EQ( (lista.get_curso("001")).get_name(), "empty" );
}

int main(int argc, char** argv)
{
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}