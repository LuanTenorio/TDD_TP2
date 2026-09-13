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

Result checkLeftDiagonal(GameMatrix game) {
  int player = game[0][0];

  if (player == Fields::Empty) return Result::INDEFINITE;

  for (int i = 0; i < 2; i++)
    if (game[i][i] != game[i + 1][i + 1]) return Result::INDEFINITE;

  return static_cast<Result>(player);
}

Result checkRightDiagonal(GameMatrix game) {
  int player = game[0][2];

  if (player == Fields::Empty) return Result::INDEFINITE;

  for (int i = 0; i < 2; i++)
    if (game[i][2 - i] != game[i + 1][2 - (i + 1)]) return Result::INDEFINITE;

  return static_cast<Result>(player);
}

Result checkDiagonal(GameMatrix game) {
  Result result = checkLeftDiagonal(game);
  if (result == Result::VICTORY_O || result == Result::VICTORY_X) return result;

  return checkRightDiagonal(game);
}

int CheckGame(GameMatrix game) {
  Result result = checkCollumn(game);
  if (result == Result::VICTORY_O || result == Result::VICTORY_X) return result;

  result = checkRow(game);
  if (result == Result::VICTORY_O || result == Result::VICTORY_X) return result;

  result = checkDiagonal(game);
  if (result == Result::VICTORY_O || result == Result::VICTORY_X) return result;

  return -3;
}
