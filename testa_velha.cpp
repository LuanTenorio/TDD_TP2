
/**
 * \file testa_velha.cpp
 */

#include "velha.hpp"

#define CATCH_CONFIG_MAIN
#include "catch.hpp"

TEST_CASE("Vitória", "[velha]") {
  SECTION("Vitória do jogador X coluna") {
    GameMatrix game = {{2, 0, 1}, {2, 0, 1}, {0, 2, 1}};

    REQUIRE(CheckGame(game) == VICTORY_X);
  }

  SECTION("Vitória do jogador O coluna") {
    GameMatrix game = {{2, 0, 1}, {2, 0, 1}, {2, 1, 0}};

    REQUIRE(CheckGame(game) == VICTORY_O);
  }

  SECTION("Vitória do jogador X linha") {
    GameMatrix game = {{1, 1, 1}, {0, 0, 2}, {0, 2, 2}};

    REQUIRE(CheckGame(game) == VICTORY_X);
  }

  SECTION("Vitória do jogador O linha") {
    GameMatrix game = {{2, 2, 2}, {0, 0, 1}, {0, 1, 1}};

    REQUIRE(CheckGame(game) == VICTORY_O);
  }

  SECTION("Vitória do jogador X diagonal horário") {
    GameMatrix game = {{1, 0, 0}, {0, 1, 2}, {2, 2, 1}};

    REQUIRE(CheckGame(game) == VICTORY_X);
  }

  SECTION("Vitória do jogador X diagonal anti-horário") {
    GameMatrix game = {{0, 0, 1}, {0, 1, 2}, {1, 2, 2}};

    REQUIRE(CheckGame(game) == VICTORY_X);
  }
}
