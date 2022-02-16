/**
* \file minxmax_ia.h
* \brief Implémentation de l'IA à l'aide de l'algorithme minmax.
* \author maxime.kuhn1@uha.fr
* \version 1
*
*/

#ifndef MINMAX_IA_
#define MINMAX_IA_

#define PROFONDEUR_MAX 5
#define VALEUR_NULLE 123456

#include <stdlib.h>

#include "grille.h"

/* structure(s) */

struct Noeud{
    /*! damier de jeu */
    PDamier d;
    /*! noeuds fils du noeud */
    struct Noeud** fils;
    /*! nombre de fils du noeud */
    int nb_fils;
    /*! valeur obtenue grâce à l'évaluation de la situation */
    int valeur; // valeur de l'évaluation heuristique
};

typedef struct Noeud noeud_t;

/* signatures des fonctions */

/**
* \fn heuristique()
* \brief Evaluation de la situation actuelle du damier
* \param d : référence au damier surlequel on joue
* \return int, evaluation de la situation.
*/
int heuristique(PDamier d);

/**
* \fn genere_arbre()
* \brief Génère l'arbre pour la décision minmax
* \param root : référence à la racine de l'arbre ( = un noeud)
* \param d : référence au damier surlequel on joue
* \return void, on modifie diretement la racine de l'arbre
*/
void genere_arbre(noeud_t *root, PDamier d, int profondeur);

/**
* \fn choisir_valeur_noeud
* \brief Choisis la valeur de chaque noeud en fonction de la valeur de ses noeuds fils (minimal ou maximal)
* \param n : référence à un noeud
* \param min : entier qui détermine si on doit choisir le min (ou le max)
* \return référence sur un nouveau damier
*/
void choisir_valeur_noeud(noeud_t *n, int min);

#endif // IA minmax