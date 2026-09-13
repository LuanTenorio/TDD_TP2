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
    player = game[row][0];

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

bool checkIfResultIsWin(Result result) {
  return result == Result::VICTORY_O || result == Result::VICTORY_X;
}

Result checkDiagonal(GameMatrix game) {
  Result result = checkLeftDiagonal(game);
  if (checkIfResultIsWin(result)) return result;

  return checkRightDiagonal(game);
}

Result checkWin(GameMatrix game) {
  Result result = checkCollumn(game);
  if (checkIfResultIsWin(result)) return result;

  result = checkRow(game);
  if (checkIfResultIsWin(result)) return result;

  result = checkDiagonal(game);
  if (checkIfResultIsWin(result)) return result;

  return Result::INDEFINITE;
}

bool checkDraw(GameMatrix game) {
  for (int i = 0; i < 3; i++)
    for (int j = 0; j < 3; j++)
      if (game[i][j] == Fields::Empty) return false;

  return true;
}

bool checkImpossible(GameMatrix game) {
  int len[3] = {0, 0, 0};  // Empty, X, O

  for (int i = 0; i < 3; i++)
    for (int j = 0; j < 3; j++) len[game[i][j]]++;

  return abs(len[Fields::FIELD_X] - len[Fields::FIELD_O]) >= 2;
}

bool checkTwoWinners(GameMatrix game, Result firstWinner) {
  GameMatrix gameX = {};
  GameMatrix gameO = {};

  for (int i = 0; i < 3; i++)
    for (int j = 0; j < 3; j++)
      if (game[i][j] == Fields::FIELD_X)
        gameX[i][j] = Fields::FIELD_X;
      else if (game[i][j] == Fields::FIELD_O)
        gameO[i][j] = Fields::FIELD_O;

  return (firstWinner == Result::VICTORY_X &&
          checkWin(gameO) == Result::VICTORY_O) ||
         (firstWinner == Result::VICTORY_O &&
          checkWin(gameX) == Result::VICTORY_X);
}

Result CheckGame(GameMatrix game) {
  if (checkImpossible(game)) return Result::IMPOSSIBLE;

  Result result = checkWin(game);
  if (checkIfResultIsWin(result))
    return checkTwoWinners(game, result) ? Result::IMPOSSIBLE : result;

  if (checkDraw(game)) return Result::DRAW;

  return Result::INDEFINITE;
}
