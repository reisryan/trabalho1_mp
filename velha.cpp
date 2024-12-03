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
            if (velha[i][j] != primeiro && velha[i][j] != 0) {
                return false;
            }
        }
    }

    return true;
}

bool VerificaEmpate(int velha[3][3]) {
    int quantX = 0;
    int quantO = 0;

    for (int i=0; i <= 2; i++) {
        for (int j=0; j <= 2; j++) {
            if (velha[i][j] == 1) {
                quantX += 1;
            }
            if (velha[i][j] == 2) {
                quantO += 1;
            }
        }
    }
    if ((quantX == quantO) && (quantX > 0) && (quantX <= 2)) {
        return true;
    }
    return false;
}

bool VerificaIndefinido(int velha[3][3]) {
    int quantX = 0;
    int quantO = 0;
    // Conta os elementos no tabuleiro
    for (int i = 0; i <= 2; i++) {
        for (int j = 0; j <= 2; j++) {
            if (velha[i][j] == 1) {
                quantX += 1;
            } else if (velha[i][j] == 2) {
                quantO += 1;
            }
        }
    }
    if ((quantX > 3 || quantO > 3) && (VerificaRegras(velha) == false)) {
        return true;
    }
    if (((quantX == 0 || quantO == 0) || (quantX < 3 && quantO < 3 && quantX != quantO)) && (quantO != 9 && quantX != 9)) {
        return true;
    }

    return false;
}

int VerificaVelha(int velha[3][3]) {
    /* Verifica se o estado do tabuleiro é indefinido */
    if (VerificaIndefinido(velha)) {
        return -1;
    }
    /* Verifica a existência de empates */
    if (VerificaEmpate(velha)) {
        return 0;
    }
    /* Verifica as regras */
    if (VerificaRegras(velha)) {
        return -2;
    }
    /* Verifica se há vitória em linhas j */
    for (int j = 0; j <= 2; j++) {
        if ((velha[j][0] == velha[j][1] && velha[j][1] == velha[j][2]) &&
        (velha[j][0] == 1 || velha[j][0] == 2)) {
            return velha[j][0];
        }
    }
    /* Verifica se há vitória em colunas i */
    for (int i = 0; i <= 2; i++) {
        if ((velha[0][i] == velha[1][i] && velha[1][i] == velha[2][i]) &&
        (velha[0][i] == 1 || velha[0][i] == 2)) {
            return velha[0][i];
        }
    }
    /* Verifica vitória na diagonal principal */
    if ((velha[0][0] == velha[1][1] && velha[1][1] == velha[2][2]) &&
    (velha[0][0] == 1 || velha[0][0] == 2)) {
        return velha[0][0];
    }
    /* Verifica vitória na diagonal secundária */
    if ((velha[0][2] == velha[1][1] && velha[1][1] == velha[2][0]) &&
    (velha[1][1] == 1 || velha[1][1] == 2)) {
        return velha[1][1];
    }

    /* Caso nenhuma das condições anteriores seja satisfeita */
    return -3;
}
