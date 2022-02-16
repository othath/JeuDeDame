#ifndef IA_H
#define IA_H

#include <stdlib.h>

#include "grille.h"
#include "const.h"
#include "deplacement.h"
#include "jeu.h"

#define BLANC 100
#define NOIR 200

#define PION 1000
#define DAME 2000

struct Piece{
    int couleur; // noir ou blanc
    int type; // pion ou dame
    int position[2]; // coordonnées sur le plateau
    //struct Piece* voisins[4];
};

typedef struct Piece* PPiece;

PPiece new_piece(int c, int type, int pos[]);
int aleatoire(PPiece p_b, PPiece p_n, PDamier d, int code[4], int tour);
/**
* \fn mv_aleatoire(PDamier d,int tour);
* \brief deplacement cpu aleatoire
* \param damier, pointeur de structure de damier sur lequel on va jouer
* \param tour, entier valant 0 si c'est au tour des blancs, 1 si c'est au tour des noirs
* \return 0 si le deplacement est effectue -1 sinon
*/
int mv_aleatoire(PDamier d,int tour);
/**
* \fn checkPrisePion(PDamier d,int tour);
* \brief tester si une prise possible pour un Pion
* \param damier, pointeur de structure de damier sur lequel on va jouer
* \param tour, entier valant 0 si c'est au tour des blancs, 1 si c'est au tour des noirs
* \return 0 si prise possible , -1 sinon
*/
int checkPrisePion(PDamier d,int tour);
/**
* \fn checkPriseDame(PDamier d,int tour);
* \brief tester si une prise possible pour une Dame
* \param damier, pointeur de structure de damier sur lequel on va jouer
* \param tour, entier valant 0 si c'est au tour des blancs, 1 si c'est au tour des noirs
* \return 0 si prise possible , -1 sinon
*/
int checkPriseDame(PDamier d,int tour);


/**
* \fn  prisesPourUnPion(PDamier d, int tour, int i, int j)
* \brief renvoie un tableau contenant les prises possibles pour un pion [hg, hd, bg, bd]
* \param d : référence au damier surlequel on joue
* \param tour : tour du joueur : 0 blanc, 1 noir.
* \param i : position du pion dans le damier (ligne)
* \param j : position du pion dans le damier (colonne)
* \return tableau des prises possibles, [0,0,1,0] signifie une prise possible diagonale bas gauche
*/
int* prisesPourUnPion(PDamier d, int tour, int i, int j);

/**
* \fn  prisesPourDame(PDamier d, int tour, int i, int j)
* \brief renvoie un tableau contenant les prises possibles pour un pion [hg, hd, bg, bd]
* \param d : référence au damier surlequel on joue
* \param tour : tour du joueur : 0 blanc, 1 noir.
* \param i : position du dame dans le damier (ligne)
* \param j : position du dame dans le damier (colonne)
* \return tableau des prises possibles, [0,0,1,0] signifie une prise possible diagonale bas gauche
*/
int* prisesPourDame(PDamier d, int tour, int i, int j);
#endif // Intelligence Artificielle*/
