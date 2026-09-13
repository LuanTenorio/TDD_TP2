#include <iostream>
/**
 * \file  velha.cpp
 */

#include "velha.hpp"

/**
 * @brief verifica situacao do jogo da velha
 * @author Programador
 * @param  velha descreve o parametro
 *
 *  Descrever o que a funcao faz
 */

int VerificaVelha(int velha[3][3]) {
  int playerCol, playerRow;
  for (int i = 0; i < 3; ++i) {
    int collumn = i;
    playerCol = velha[0][collumn];

    if (playerCol != 0 && velha[1][collumn] == playerCol &&
        velha[2][collumn] == playerCol)
      return playerCol;

    int row = i;
    playerRow = velha[row][0];

    if (playerRow != 0 && velha[row][1] == playerRow &&
        velha[row][2] == playerRow)
      return playerRow;
  }

  return 0;
}
