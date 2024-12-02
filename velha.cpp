/* Copyright [2024] <Copyright Ryan>
 * \file  velha.cpp
 */
#include "velha.hpp"
/**
 * @brief verifica situacao do jogo da velha  
 * @author Ryan Reis
 * @param  velha - verifica se X venceu, ou se é impossível pelas regras;
 */ 

bool VerificaRegras(int velha[3][3]) {
    int primeiro = velha[0][0];
    if (primeiro != 1 && primeiro != 2) {
        return false;
    }
    for (int i=0; i <= 2; i++) {
        for (int j=0; j <= 2; j++) {
            if (velha[i][j] != primeiro && velha[i][j] != 0) { return false; }
        }
    }

    return true;
}

int VerificaVelha(int velha[3][3])
{   /* Verifica as regras */
    if (VerificaRegras(velha) == true) { return -2; }
    for (int j=0; j <= 2; j++) {
        /* Verifica se a determinada linha j foi toda marcada por X*/
        if (velha[j][0] == 1 && velha[j][1] == 1 && velha[j][2] == 1) {
            return 1;
        }
    }
    for (int i=0; i <= 2; i++) {
        /* Verifica a determinada coluna i foi toda marcada por X*/
        if (velha[0][i] == 1 && velha[1][i] == 1 && velha[2][i] == 1) {
            return 1;
        }
    }
    /*Verifica a diagonal principal*/
    if (velha[0][0] == 1 && velha[1][1] == 1 && velha[2][2] == 1) { return 1; }
    /*Verifica diagonal secundária*/
    if (velha[0][2] == 1 && velha[1][1] == 1 && velha[2][0] == 1) { return 1; }

    return 0;
}
