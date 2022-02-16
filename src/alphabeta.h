#ifndef ALPHABETA_H_
#define ALPHABETA_H_

#define MAX 1000
#define MIN -1000

int minimax(int profondeur, int indexFueille, int ordinateur, int valeur[], int alpha, int beta);
int max(int num1, int num2);
int min(int num1, int num2);

#endif