/**
* \file deplacement.h
* \brief Bibliothèque gérant les déplacements dans le dammier
* \author maxime.kuhn1@uha.fr, othmane.tahri@uha.fr, albi.grainca@uha.fr, matheo.marcout@uha.fr, thomas.lucenac@uha.fr
* \version 1
*
*/

#ifndef DEPLACEMENT
#define DEPLACEMENT

#include <stdlib.h>
#include <stdio.h>
#include <math.h>

#include "grille.h"

#define RED "\x1B[31m"

/**
* \fn mv_normal(int code[4],PDamier damier, int tour)
* \brief déplace un pion de manière légale
* \param code, tableau de quatre (4) entiers de la forme: [colone de départ, ligne de départ, colone d'arrivée, ligne d'arrivée]
* \param damier, pointeur de structure de damier sur lequel on va jouer
* \param tour, entier valant 0 si c'est au tour des blancs, 1 si c'est au tour des noirs
* \return 0 si le mouvement est légal (damier est donc modifié en conséquance), -1 sinon
*/
int mv_normal(int code[4],PDamier damier, int tour);

/**
* \fn dame(PDamier plateau);
* \brief changement d'un pion en dame
* \param plateau, pointeur de structure de damier sur lequel on va jouer
*/

void dame(PDamier plateau);

/**
* \fn prise(PDamier plateau, int t, int position[4])
* \brief fait un prise avec des pions normaux
* \param position, tableau de quatre (4) entiers de la forme: [colone de départ, ligne de départ, colone d'arrivée, ligne d'arrivée]
* \param plateau, pointeur de structure de damier sur lequel on va jouer
* \param t, entier valant 0 si c'est au tour des blancs, 1 si c'est au tour des noirs
* \return 0 si la prise est possible (damier est donc modifié en conséquance), -1 sinon
*/

int prise(PDamier plateau, int t, int position[4]);

/**
* \fn priseObligatoireDameHG(int v[], int i, int tour)
* \brief renvoie le nombre de prises possibles pour une dame dans sa diagonale haut gauche
* \param v : tableau virtuel 1D avec des bordures virtuelles représentant le damier (2D)
* \param i : position de la dame dans le tableau virtuel
* \param tour : 0 si tour du joueur blanc, 1 si tour du joueur noir
* \return nombre de prises possibles pour une dame dans sa diagonale haut gauche
*/
int priseObligatoireDameHG(int v[], int i, int tour);

/**
* \fn priseObligatoireDameHD(int v[], int i, int tour)
* \brief renvoie le nombre de prises possibles pour une dame dans sa diagonale haut droit
* \param v : tableau virtuel 1D avec des bordures virtuelles représentant le damier (2D)
* \param i : position de la dame dans le tableau virtuel
* \param tour : 0 si tour du joueur blanc, 1 si tour du joueur noir
* \return nombre de prises possibles pour une dame dans sa diagonale haut droit
*/
int priseObligatoireDameHD(int v[], int i, int tour);

/**
* \fn priseObligatoireDameBG(int v[], int i, int tour)
* \brief renvoie le nombre de prises possibles pour une dame dans sa diagonale bas gauche
* \param v : tableau virtuel 1D avec des bordures virtuelles représentant le damier (2D)
* \param i : position de la dame dans le tableau virtuel
* \param tour : 0 si tour du joueur blanc, 1 si tour du joueur noir
* \return nombre de prises possibles pour une dame dans sa diagonale bas gauche
*/
int priseObligatoireDameBG(int v[], int i, int tour);

/**
* \fn priseObligatoireDameBD(int v[], int i, int tour)
* \brief renvoie le nombre de prises possibles pour une dame dans sa diagonale bas droit
* \param v : tableau virtuel 1D avec des bordures virtuelles représentant le damier (2D)
* \param i : position de la dame dans le tableau virtuel
* \param tour : 0 si tour du joueur blanc, 1 si tour du joueur noir
* \return nombre de prises possibles pour une dame dans sa diagonale bas droit
*/
int priseObligatoireDameBD(int v[], int i, int tour);

/**
* \fn  priseObligatoireDame(int v[], int i, int tour)
* \brief compte le nombre de prises obligatoire pour toutes les dames en fonction du tour
* \param v : tableau virtuel 1D avec des bordures virtuelles représentant le damier (2D)
* \param i : position de la dame dans le tableau virtuel
* \param tour : 0 si tour du joueur blanc, 1 si tour du joueur noir
* \return nombre de prises obligatoires (ou possibles) pour toutes les dames dont c'est le tour
*/
int priseObligatoireDame(int v[], int i, int tour);

/**
* \fn  priseObligatoirePion(int v[], int i, int tour)
* \brief compte le nombre de prises obligatoire pour tous les pions en fonction du tour
* \param v : tableau virtuel 1D avec des bordures virtuelles représentant le damier (2D)
* \param i : position de la dame dans le tableau virtuel
* \param tour : 0 si tour du joueur blanc, 1 si tour du joueur noir
* \return nombre de prises obligatoires (ou possibles) pour tous les pions dont c'est le tour
*/
int priseObligatoirePion(int v[], int pos, int tour);

/**
* \fn  priseObligatoire(PDamier d, int tour)
* \brief renvoie le nombre de prises obligatoires (possibles) pour le joueur dont c'est le tour
* \param d : référence au damier sur lequel on joue
* \param tour : 0 si tour du joueur blanc, 1 si tour du joueur noir
* \return nombre de prises possibles pour le joueur dont c'est le tour (pions + dames)
*/
int priseObligatoire(PDamier d, int tour);

/**
* \fn  prisesPourUnPion(PDamier d, int tour, int i, int j)
* \brief renvoie un tableau contenant les prises possibles pour un pion [hg, hd, bg, bd]
* \param d : référence au damier surlequel on joue
* \param tour : tour du joueur : 0 blanc, 1 noir.
* \param i : position du pion dans le damier (ligne)
* \param j : position du pion dans le damier (colonne)
* \return tableau des prises possibles, [0,0,1,0] signifie une prise possible diagonale bas gauche
*/
//int* prisesPourUnPion(PDamier d, int tour, int i, int j);

/**
* \fn    testDep(PDamier jeu,int ligne,int cologne,int tour);
* \brief test si un deplacement de Pion est possible et renvoie aelatoirement un deplacement possible
* \param d : référence au damier sur lequel on joue
* \param ligne : ligne de pion
* \param cologne : cologne de pion
* \param tour : 0 si tour du joueur blanc, 1 si tour du joueur noir
* \return un tableau d'entier contenant ligne et cologne initial/finial,NULL sinon
*/
int* testDep(PDamier jeu,int ligne,int cologne,int tour);
/**
* \fn    testDepDame(PDamier jeu,int ligne,int cologne);
* \brief test si un deplacement de dame est possible
* \param d : référence au damier sur lequel on joue
* \param ligne : ligne de dame
* \param cologne : cologne de dame
* \return un tableau d'entier contenant ligne et cologne initial/finial,NULL sinon
*/
int *testdepDame(PDamier jeu,int ligne,int cologne);

/**
* \fn depDame(int code[4],PDamier damier, int tour)
* \brief déplace ue dame de manière légale
* \param code, tableau de quatre (4) entiers de la forme: [colone de départ, ligne de départ, colone d'arrivée, ligne d'arrivée]
* \param damier, pointeur de structure de damier sur lequel on va jouer
* \param tour, entier valant 0 si c'est au tour des blancs, 1 si c'est au tour des noirs
* \return 0 si le mouvement est légal (damier est donc modifié en conséquance), -1 sinon
*/
int depDame(int code[4], PDamier damier, int tour);

/**
* \fn choisir_deplacement(PDamier damier, int code[], int tour)
* \brief choisit la bonne fonction de déplacement
* \param damier, pointeur de structure de damier sur lequel on va jouer
* \param position, tableau de quatre (4) entiers de la forme: [colone de départ, ligne de départ, colone d'arrivée, ligne d'arrivée]
* \param tour, entier valant 0 si c'est au tour des blancs, 1 si c'est au tour des noirs
* \return 0 si le mouvement est légal (damier est donc modifié en conséquance), -1 sinon
*/
int choisir_deplacement(PDamier damier, int code[4], int tour);

/**
* \fn deplacementOuPrise(PDamier damier, int position[4], int tour)
* \brief fait un prise avec des pions normaux
* \param position, tableau de quatre (4) entiers de la forme: [colone de départ, ligne de départ, colone d'arrivée, ligne d'arrivée]
* \param plateau, pointeur de structure de damier sur lequel on va jouer
* \param tour, entier valant 0 si c'est au tour des blancs, 1 si c'est au tour des noirs
* \return -1 si aucun mouvement n'est possible, utilise la fonction prise_dame si le return est à 1, utilise la fonction depDame si le return est à 0
*/
int deplacementOuPrise(PDamier damier, int position[4], int tour);

/**
* \fn prise_dame(PDamier plateau, int t, int position[4])
* \brief fait un prise avec des pions normaux
* \param position, tableau de quatre (4) entiers de la forme: [colone de départ, ligne de départ, colone d'arrivée, ligne d'arrivée]
* \param plateau, pointeur de structure de damier sur lequel on va jouer
* \param t, entier valant 0 si c'est au tour des blancs, 1 si c'est au tour des noirs
* \return renvoie 0 si la prise c'est bien éffectué, -1 sinon
*/
int prise_dame(PDamier plateau, int t, int position[4]);

#endif // DEPLACEMENT
