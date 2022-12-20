#include <curso.h>
#include "gtest/gtest.h"

TEST(Curso, ConstructorDefaultParameters) {
    Curso c1("000");

    EXPECT_EQ("000", c1.get_id());
    EXPECT_EQ("empty", c1.get_name());
    EXPECT_EQ("empty", c1.get_estudio());
    EXPECT_EQ(0, c1.get_month());
    EXPECT_EQ(0, c1.get_year());
    EXPECT_EQ(0, c1.get_day());
    EXPECT_EQ("empty", c1.get_ponente());
    EXPECT_EQ("empty", c1.get_duracion());
    EXPECT_EQ("empty", c1.get_descripcion());
    EXPECT_EQ("empty", c1.get_lugar());
    EXPECT_EQ("empty", c1.get_aula());
    EXPECT_EQ(0, c1.get_aforo());
}

TEST(Curso, ConstructorParameters) {
    Curso c1("000", "Curso Prueba", 2003, 3, 24, "Manolo", "No", "34 dias", "descripcion",
                "edificio7", "aula2", 45);

    EXPECT_EQ("000", c1.get_id());
    EXPECT_EQ("Curso Prueba", c1.get_name());
    EXPECT_EQ("No", c1.get_estudio());
    EXPECT_EQ(3, c1.get_month());
    EXPECT_EQ(2003, c1.get_year());
    EXPECT_EQ(24, c1.get_day());
    EXPECT_EQ("Manolo", c1.get_ponente());
    EXPECT_EQ("34 dias", c1.get_duracion());
    EXPECT_EQ("descripcion", c1.get_descripcion());
    EXPECT_EQ("edificio7", c1.get_lugar());
    EXPECT_EQ("aula2", c1.get_aula());
    EXPECT_EQ(45, c1.get_aforo());
}

TEST(Curso, Inscribirse) {
    Curso c1("000");

    EXPECT_TRUE(c1.inscribir_usuario("1"));
}

TEST(Curso, Desinscribirse) {
    Curso c1("000");

    EXPECT_TRUE(c1.inscribir_usuario("1"));
}

int main(int argc, char** argv)
{
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}