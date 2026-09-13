#include "velha.hpp"

#include <cstdlib>

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

Result checkWin(GameMatrix game) {
  Result result = checkCollumn(game);
  if (result == Result::VICTORY_O || result == Result::VICTORY_X) return result;

  result = checkRow(game);
  if (result == Result::VICTORY_O || result == Result::VICTORY_X) return result;

  result = checkDiagonal(game);
  if (result == Result::VICTORY_O || result == Result::VICTORY_X) return result;

  return Result::INDEFINITE;
}

Result checkDraw(GameMatrix game) {
  for (int i = 0; i < 3; i++)
    for (int j = 0; j < 3; j++)
      if (game[i][j] == Fields::Empty) return Result::INDEFINITE;

  return Result::DRAW;
}

Result CheckGame(GameMatrix game) {
  int lenX = 0, lenO = 0, lenEmpty = 0;

  for (int i = 0; i < 3; i++) {
    for (int j = 0; j < 3; j++) {
      if (game[i][j] == Fields::FIELD_O)
        lenO++;
      else if (game[i][j] == Fields::FIELD_X)
        lenX++;
      else if (game[i][j] == Fields::Empty)
        lenEmpty++;
    }
  }

  if (abs(lenX - lenO) >= 2) return Result::IMPOSSIBLE;

  if (Result result = checkWin(game);
      result == Result::VICTORY_O || result == Result::VICTORY_X)
    return result;

  if (checkDraw(game) == Result::DRAW) return Result::DRAW;

  return Result::INDEFINITE;
}
