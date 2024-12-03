// Copyright [2024] <Copyright Ryan>
/**
 * \file testa_velha.cpp
 */

#include "velha.hpp"

#define CATCH_CONFIG_MAIN
#include "catch.hpp"

TEST_CASE("Testa Empate", "[single-file]") {
    int teste1[3][3]= {{2, 0, 1}, {2, 0, 1}, {0, 0, 0}};
    REQUIRE(VerificaVelha(teste1)== 0);
}
TEST_CASE("Testa -1", "[single-file]") {
    int teste2[3][3]={{1, 1, 1}, {1, 1, 1}, {1, 1, 1}};
    REQUIRE(VerificaVelha(teste2)== -2);
}
TEST_CASE("Teste Vencedor O", "[single-file]") {
    int teste3[3][3]={{2, 1, 0}, {2, 0, 1}, {2, 0, 0}};
    REQUIRE(VerificaVelha(teste3)== 2);
}
TEST_CASE("Teste Vencedor X 1", "[single-file]") {
    int teste4[3][3]={{2, 0, 1}, {2, 0, 1}, {0, 0, 1}};
    REQUIRE(VerificaVelha(teste4)== 1);
}
TEST_CASE("Teste Vencedor X 2", "[single-file]") {
    int teste5[3][3]={{2, 0, 1}, {2, 1, 0}, {1, 0, 0}};
    REQUIRE(VerificaVelha(teste5)== 1);
}
TEST_CASE("Teste Empate 1", "[single-file]") {
    int teste6[3][3]={{1, 0, 0}, {0, 2, 0}, {0, 0, 0}};
    REQUIRE(VerificaVelha(teste6)== 0);
}
