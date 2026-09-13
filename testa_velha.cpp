
/**
 * \file testa_velha.cpp
 */

#include "velha.hpp"

#define CATCH_CONFIG_MAIN
#include "catch.hpp"

TEST_CASE("Vitória", "[velha]") {
  SECTION("Vitória do jogador X") {
    int game[3][3] = {{2, 0, 1}, {2, 0, 1}, {0, 2, 1}};

    REQUIRE(VerificaVelha(game) == VICTORY_X);
  }

  SECTION("Vitória do jogador O") {
    int game[3][3] = {{2, 0, 1}, {2, 0, 1}, {2, 1, 0}};

    REQUIRE(VerificaVelha(game) == VICTORY_O);
  }
}
