/*
 * Implémentation d'une intelligence artificielle pour le jeu des dames.
 * Dans ce programme, l'IA est le joueur noir (pour l'instant).
 * De plus, on suppose que les fonctions suivantes existent :
 *      - nombreCoupsPossibles
 *              renvoie le nombre de coups possibles pour le joueur dont c'est le tour.
 *                  cette fonction existe à moitié (priseObligatoire), elle renvoie le nombre de prises
 *                  possibles pour le joueur dont c'est le tour
 *      
 *      - coupsPossibles
 *              renvoie un tableau des coups possibles : ex [[G1,F0], [D0,E1], ...] pour le joueur dont c'est le tour.
 *      - move
 *              effectue le déplacement passé en paramètre dans le damier correspondant.
 *                  cette fonction existe en partie (on peut déplacer les dames, les pions, faire des prises
 *                  avec les dames et les pions, il manque juste la rafle (pion et dames)).
 *              
 * 
 */
/*
#include "minmax_ia.h"

noeud_t *new_noeud(PDamier d){
    noeud_t *n = (noeud_t*)malloc(sizeof(noeud_t));
    n->d = d;
    n->fils = NULL;
    n->nb_fils = 0;
    n->valeur = VALEUR_NULLE;
}

int heuristique(PDamier d){*/
    /* évaluation de la situation actuelle du damier */
    /*return d->nb_noirs-d->nb_blancs;
}

void genere_arbre(noeud_t *root, PDamier d, int profondeur){*/
    /* génère l'arbre de décisions minmax */

    // à partir de la situation actuelle, on détermine le nombre de situations possibles
    /*int nb_coups_possibles = nombreCoupsPossibles(d);

    // on alloue de la mémoire pour les fils de la situation actuelle
    root->fils = (noeud_t**)malloc(nb_coups_possibles*sizeof(noeud_t*));
    root->nb_fils = nb_coups_possibles;

    // on récupère la liste des coups possibles
    int *coups_possibles = coupsPossibles(d);

    // on joue chaque situation qu'on met à chaque fois dans un fils
    PDamier save = copie_damier(d);
    for(int i=0; i<nb_coups_possibles; i++){
        move(coups_possibles[i],d);
        root->fils[i] = new_noeud(d);
        root->fils[i]->valeur = heuristique(d);

        if(profondeur <= PROFONDEUR_MAX){/*
            /* on s'arrête à une certaine profondeur (impaire) pour appliquer minmax */
            /*genere_arbre(root->fils[i],d,profondeur+1);
        }

        d = save;
    }
}

void choisir_valeur_noeud(noeud_t *n, int min){*/
    /* choisis la bonne valeur pour un noeud, en fonction de ses fils,
     * min = 0, alors on choisit la valeur maximale
     * min = 1, alors on choisit la valeur minimale
     * 
     * /!\ ici, on ne s'occupe pas de savoir si n a une valeur, on suppose que la fonction est appelée correctement /!\
     * 
     */

    /*int nb_fils = n->nb_fils;
    if(min == 0){ // valeur max
        int vmax = n->fils[0]->valeur;
        for(int i=0; i<nb_fils; i++){
            if(n->fils[i]->valeur > vmax) vmax = n->fils[i]->valeur;
        }
        n->valeur = vmax;
    }
    else{ // valeur max
        int vmin = n->fils[0]->valeur;
        for(int i=0; i<nb_fils; i++){
            if(n->fils[i]->valeur < vmin) vmin = n->fils[i]->valeur;
        }
        n->valeur = vmin;
    }

}

void evaluer_arbre(noeud_t *root, int profondeur){*/
    /* évalue chaque noeud de l'arbre en fonction de ses fils et choisit le min ou le max */

    // on détermine d'abord si on doit chercher le minimum ou le maximum
    /*int min;
    if(profondeur%2 == 0)  min = 0;
    else min = 1;

    // TODO : finir la fonction
}*/
