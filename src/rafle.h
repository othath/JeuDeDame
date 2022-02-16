#ifndef RAFLE_H_
#define RAFLE_H_

#include <stdio.h>
#include <stdlib.h>
#include "grille.h"
#include "deplacement.h"

/*
 * Implémentation d'une liste chaînée (tête et queue fictives) pour l'algorithme de la recherche  de rafle maximale.
 * Lors de la recherche de rafle, on stocke dans la liste chaînée les coordonnées par lesquelles on est
 * déja passé.
 */

struct Cellule{
    int x;
    int y;
    struct Cellule* svt; // pointeur vers la cellule suivante
};

typedef struct Cellule cel_t;

struct Liste{
    cel_t *tete;
    cel_t *queue;
    int longueur;
};

typedef struct Liste liste_t;

cel_t *new_cel(int x, int y);
liste_t *liste_init();
void cel_print(cel_t *c);
void liste_print(liste_t *l);
void liste_insere(liste_t *l, cel_t *c);
int liste_trouve(liste_t *l, int x, int y);
int rafle(int position[2], PDamier plateau, int t, liste_t *l, int r_max);
#endif // RAFLE_H_
