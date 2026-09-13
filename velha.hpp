#ifndef VELHA_HPP_

#define VELHA_HPP_

enum Result {
  VICTORY_O = 2,
  VICTORY_X = 1,
  DRAW = 0,
  IMPOSSIBLE = -1,
  INDEFINITE = -2
};

int VerificaVelha(int velha[3][3]);

#endif  // VELHA_HPP_
