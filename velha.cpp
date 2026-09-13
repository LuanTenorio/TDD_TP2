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
  for (int collumn = 0; collumn < 3; ++collumn) {
    int player = velha[0][collumn];

    if (player != 0 && velha[1][collumn] == player &&
        velha[2][collumn] == player)
      return player;
  }

  for (int i = 0; i < 3; i++) {
    if (velha[i][0] == 1 && velha[i][1] == 1 && velha[i][2] == 1) return 1;
    if (velha[i][0] == 2 && velha[i][1] == 2 && velha[i][2] == 2) return 2;
  }

  return 0;
}
