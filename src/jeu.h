/**
* \file jeu.h
* \brief Gère les fonctions usuelles du jeu
* \author maxime.kuhn1@uha.fr, othmane.tahri@uha.fr, matheo.marcourt@uha.fr
* \version 1
*
*/
#ifndef JEU_H_
#define JEU_H_

#include <stdlib.h>
#include <stdio.h>

#include "grille.h"
#include "deplacement.h"
#include "input.h"
#include "reseau.h"

#define MAX_INPUT 100

/**
* \fn plusDePieces(int tour, PDamier d)
* \brief vérifie si un joueur n'a plus de pièces
* \param tour : 0 si c'est au tour du joueur blanc, 1 si c'est au tour du joueur noir
* \param d : damier dans le
quel on joue
* \return 0 si le joueur dont c'est le tour n'a plus pièces, 1 sinon.
*/
int plusDePieces(int tour, PDamier d);

/**
* \fn victoire()
* \brief détermine si la partie est terminée avec une victoire
* \return -1 si la partie continue, 0 si elle est terminée
*/
int victoire();
int jeu(PDamier d);
void finJeu(PDamier jeu,int couleur, int tour);
int *trouverCoup(PDamier jeu,int couleur);
int bloque(int tour,PDamier d);

/**
* \fn abandon(char *input, int tour)
* \brief Abandon du joueur dont c'est le tour
* \param input : chaîne de caractères
* \param tour : 0 si c'est au tour du joueur blanc, 1 si c'est au tour du joueur noir
* \return référence sur un nouveau damier
*/
int abandon(char* input, int tour);
int egalite(PDamier courant,PListeDamier ld);
int checkPiece(PDamier d);

/**
* \fn jeu_blanc(PDamier d, SOCKET chausette)
* \brief jeu en ligne PVP côté blanc
* \param d, pointeur de damier sur lequel on va jouer
* \param chausette, SOCKET (entier) de connexion
* \return 0 si le jeu c'est fini sans problème, -1 sinon
*/
int jeu_blanc(PDamier d, SOCKET chausette);

/**
* \fn jeu_noir(PDamier d, SOCKET chausette)
* \brief jeu en ligne PVP côté noir
* \param d, pointeur de damier sur lequel on va jouer
* \param chausette, SOCKET (entier) de connexion
* \return 0 si le jeu c'est fini sans problème, -1 sinon
*/
int jeu_noir(PDamier d, SOCKET chausette);
//PListeDamier -->PILE linked list Last in first Out pour optimiser un peu le code de verification

#endif
