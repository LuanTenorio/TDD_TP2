#ifndef VELHA_HPP_

#define VELHA_HPP_

enum Result {
  VICTORY_O = 2,
  VICTORY_X = 1,
  DRAW = 0,
  IMPOSSIBLE = -1,
  INDEFINITE = -2
};

enum Fields { FIELD_O = 2, FIELD_X = 1, Empty = 0 };

using GameMatrix = int[3][3];

Result CheckGame(int velha[3][3]);

#endif  // VELHA_HPP_
