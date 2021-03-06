#include "alphabeta.h"

//Algorithme type alpha-beta avec comme parametre un tableau d'entier.

int minimax(int profondeur, int indexFeuille, int ordinateur, int valeur[], int alpha, int beta){
    if(profondeur == 3)
        return valeur[indexFeuille];
    if(ordinateur == 1){
        int best = MIN;
        for(int i = 0; i < 2; i++){
            int val = minimax(profondeur+1, indexFeuille*2+i,0,valeur,alpha,beta);
            best = max(best, val);
            alpha = max(alpha, best);
            if(beta <= alpha)
                break;
        }
        return best;
    }
    else{
        int best = MAX;

        for(int i = 0;i < 2; i++){
            int val = minimax(profondeur+1, indexFeuille*2+i,1,valeur,alpha,beta);
            best = min(best, val);
            beta = min(beta, best);
            if(beta<=alpha)
                break;
        }
        return best;
    }
}

int max(int num1, int num2){
    if(num1 > num2)
        return num1;
    else
        return num2;
}

int min(int num1, int num2){
    if(num1 < num2)
        return num1;
    else
        return num2;
}