/* Copyright [2024] <Copyright Ryan> */
#ifndef VELHA_HPP
#define VELHA_HPP
constexpr int X = 1;
constexpr int O = 2;
#include <cmath>
int VerificaVelha(int velha[3][3]);
bool VerificaRegras(int velha[3][3]);
bool VerificaEmpate(int velha[3][3]);
bool VerificaIndefinido(int velha[3][3]);
#endif
