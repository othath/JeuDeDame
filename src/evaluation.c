/*#include "evaluation.h"
#include "deplacement.h"

//On suppose pour l'instant que l'ordinateur joue les noir.
//Ainsi les pions adverses sont les blancs(joueur) et que les pieces alliées sont noir.

//Attribution d'un score pour chaque case du damier

int valeurDamier[10][10];
const int dameBlanche = -300;
const int dameNoire = 250;

int * tabEval(PDamier d, int tabValeur[]){

    valeurDamier[0][1] = 80;
    valeurDamier[0][3] = 100;
    valeurDamier[0][5] = 125;
    valeurDamier[0][7] = 100;
    valeurDamier[0][9] = 75;

    valeurDamier[1][0] = 50;
    valeurDamier[1][2] = 70;
    valeurDamier[1][4] = 70;
    valeurDamier[1][6] = 70;
    valeurDamier[1][8] = 70;

    valeurDamier[2][1] = 25;
    valeurDamier[2][3] = 20;
    valeurDamier[2][5] = 20;
    valeurDamier[2][7] = 20;
    valeurDamier[2][9] = 40;

    valeurDamier[3][0] = 25;
    valeurDamier[3][2] = 10;
    valeurDamier[3][4] = 10;
    valeurDamier[3][6] = 10;
    valeurDamier[3][8] = 25;

    valeurDamier[4][1] = 25;
    valeurDamier[4][3] = 10;
    valeurDamier[4][5] = 10;
    valeurDamier[4][7] = 10;
    valeurDamier[4][9] = 25;

    valeurDamier[5][0] = 25;
    valeurDamier[5][2] = 10;
    valeurDamier[5][4] = 10;
    valeurDamier[5][6] = 10;
    valeurDamier[5][8] = 25;

    valeurDamier[6][1] = 25;
    valeurDamier[6][3] = 10;
    valeurDamier[6][5] = 10;
    valeurDamier[6][7] = 10;
    valeurDamier[6][9] = 25;

    valeurDamier[7][0] = 40;
    valeurDamier[7][2] = 20;
    valeurDamier[7][4] = 20;
    valeurDamier[7][6] = 20;
    valeurDamier[7][8] = 25;

    valeurDamier[8][1] = 70;
    valeurDamier[8][3] = 70;
    valeurDamier[8][5] = 70;
    valeurDamier[8][7] = 70;
    valeurDamier[8][9] = 50;

    valeurDamier[9][0] = 75;
    valeurDamier[9][2] = 100;
    valeurDamier[9][4] = 125;
    valeurDamier[9][6] = 100;
    valeurDamier[9][8] = 80;
    
    int n = 0;
    for(int i=0;i<10;i++)
        for(int j=0;j<10;j++){
            if(d->plateau[i][j] == PION_BLANC || d->plateau[i][j] == DAME_BLANCHE){
                tabValeur[n] = evalPositionPion(d->plateau[i][j], i , j) + evalNbDame(d->plateau[i][j]);
                n++;
            }
        }
    return tabValeur;
}

int evalNbDame(int coordonne){
            if(coordonne == DAME_BLANCHE)
                return dameBlanche;
            if(coordonne == DAME_NOIRE)
                return dameNoire;
            else
                return 0;
}

int evalPositionPion(int coordonne, int i, int j){
            if(coordonne == PION_BLANC)
                return valeurDamier[i][j];
            if(coordonne == PION_NOIR)
                return -valeurDamier[i][j];
            else
                return 0;
}*/

/*
int evalPositionDame(PDamier d){
    int somme = 0;
    for(int i=0;i<10;i++)
        for(int j=0;j<10;j++){
            if(d->plateau[i][j] == DAME_BLANCHE)
                for(int n = i-1;n<=i+1;n=+2)
                    for(int m = j-1;m<=j+1;m=+2){
                        if(d->plateau[n][m] == PION_NOIR || d->plateau[n][m] == DAME_NOIRE)
                            somme += -1000;
                    }

            if(d->plateau[i][j] == DAME_NOIRE)
                nbDameNoire++;
        }
}
*/

/*
int evaluation(Pion p, PDamier plateau, int t, int position[4]){
    int scoreAnalyse = 0;
    int nbPriseBlanc = 0;
    int nbPriseNoir = 0;
    while(detectionPrise(PDamier plateau, int t, int position[4]) != 0){//Tant que l'on detecte une prise possible
        if(detectionPrise(PDamier plateau, int t, int position[4]) == 1)//Test si prise noir
            nbPriseBlanc++;
        if(detectionPrise(PDamier plateau, int t, int position[4]) == 2)//Test si prise noir
            nbPriseNoir++;
    }
    int nbDameBlanc = 0;
    int nbDameNoir = 0;
    while(detectionDame(PDamier plateau) != 0){//Tant que l'on detecte si un pion est en position de devenir une dame
        if(detectionDame(PDamier plateau) == 1)//Test si dame blanche
            nbDameBlanc++;
        if(detectionDame(PDamier plateau) == 2)//Test si dame noir
            nbDameNoir++;
    }
    int nbPionCoteBlanc = 0;
    int nbPionCoteNoir = 0;
    while(detectionCote(PDamier plateau) != 0){//Tant que l'on detecte un pion en position de coté
        if(detectionCote(PDamier plateau) == 1)//Test si position pour pion blanc
            nbPionCoteBlanc++;
        if(detectionCote(PDamier plateau) == 2)//Test si position pour pion noir
            nbPionCoteNoir++;
    }
    //TODO : compteur victoire
    int victoire = 0;
    //TODO : compteur defaite
    int defaite = 0;
    //TODO : compteur egalité
    int egalite = 0;
    //Calcul du score de l'analyse
    scoreAnalyse = nbPriseNoir*PRISE*COEFF_PRISE + nbPriseBlanc*PRISE_ADVERSE*COEFF_PRISE_ADVERSE +
                    nbDameNoir*DAME*COEFF_DAME + nbDameBlanc*DAME_ADVERSE*COEFF_DAME_ADVERSE +
                    nbPionCoteNoir*POSITION_COTE*COEFF_POSITION_COTE +
                    victoire*VICTOIRE*COEFF_VICTOIRE + defaite*DEFAITE*COEFF_DEFAITE +
                    egalite*EGALITE*COEFF_EGALITE;
    return scoreAnalyse;
}

int detectionPrise(PDamier plateau, int t, int position[4]){
    int x1 = position[1];
    int y1 = position[0];
    int x2 = position[3];
    int y2 = position[2];
    int diff_x = (x2-x1)/2;
    int diff_y = (y2-y1)/2;
    if(plateau->plateau[x2][y2] == 0){
        if(plateau->plateau[x1+diff_x][y1+diff_y]==PION_NOIR)//Test si prise blanche sur noire possible, renvoi 1
            if(t==0)
                return 1; 
        if(plateau->plateau[x1+diff_x][y1+diff_y]==PION_BLANC)//Test si prise noire sur blanche possible renvoi 2
            if(t==1)
                return 2;
    }
    
}

int detectionDame(PDamier plateau){
    for(int i=0; i<COLONNES; i++){
        if(plateau->plateau[9][i]==PION_NOIR)//Test si transformation en dame noire
            return 2;
        if(plateau->plateau[0][i]==PION_BLANC)//Test si transformation en dame blanche
            return 1;
    }
}

int detectionCote(PDamier plateau){
    for(int i=0;i<LIGNES; i++){
        if(plateau->plateau[i][0]==PION_NOIR || plateau->plateau[i][9]==PION_NOIR)//Test si piece noire sur un coté
            return 2;
        if(plateau->plateau[i][0]==PION_BLANC || plateau->plateau[i][9]==PION_BLANC)//Test si piece blanche sur un coté
            return 1;
    }
}
*/

