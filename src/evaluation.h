/*#ifndef EVALUATION_H_
#define EVALUATION_H_

#include "deplacement.h"


//Definition des valeurs pour chaque situation.

#define DEFAITE -4
#define EGALITE -3
#define PRISE_ADVERSE -2
#define DAME_ADVERSE -1
#define POSITION_COTE 1
#define DAME 2
#define PRISE 3
#define VICTOIRE 4

//Definition des coefficients pour chaque situation

#define COEFF_DEFAITE 
#define COEFF_EGALITE
#define COEFF_PRISE_ADVERSE
#define COEFF_DAME_ADVERSE 
#define COEFF_POSITION_COTE
#define COEFF_DAME
#define COEFF_PRISE
#define COEFF_VICTOIRE

int * tabEval(PDamier d, int tabValeur[]);
int evalNbDame(int coordonne);
int evalPositionPion(int coordonne, int i, int j);*/

/*
int evaluation(Pion p, PDamier plateau, int t, int position[4]);
int detectionPrise(PDamier plateau, int t, int position[4]);
int detectionDame(PDamier plateau);
int detectionCote(PDamier plateau);
*/

//#endif