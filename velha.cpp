#include "velha.hpp"

Result checkCollumn(GameMatrix game) {
  int player;
  for (int collumn = 0; collumn < 3; ++collumn) {
    player = game[0][collumn];

    if (player != 0 && game[1][collumn] == player && game[2][collumn] == player)
      return static_cast<Result>(player);
  }

  return Result::INDEFINITE;
}

Result checkRow(GameMatrix game) {
  int player;
  for (int row = 0; row < 3; ++row) {
    player = game[0][row];

    if (player != 0 && game[row][1] == player && game[row][2] == player)
      return static_cast<Result>(player);
  }

  return Result::INDEFINITE;
}

Result checkDiagonal(GameMatrix game) {
  if ((game[0][0] == Fields::FIELD_X && game[1][1] == Fields::FIELD_X &&
       game[2][2] == Fields::FIELD_X) ||
      (game[0][2] == Fields::FIELD_X && game[1][1] == Fields::FIELD_X &&
       game[2][0] == Fields::FIELD_X)) {
    return Result::VICTORY_X;
  }

  return Result::INDEFINITE;
}

int CheckGame(GameMatrix game) {
  Result result = checkCollumn(game);
  if (result == Result::VICTORY_O || result == Result::VICTORY_X) return result;

  result = checkRow(game);
  if (result == Result::VICTORY_O || result == Result::VICTORY_X) return result;

  result = checkDiagonal(game);
  if (result == Result::VICTORY_X) return result;

  return 0;
}
