/**
* \file grille.h
* \brief Damier avec opérations usuelles (initialisation, affichage, copie, actualisation,...)
* \author maxime.kuhn1@uha.fr, othmane.tahri@uha.fr, albi.grainca@uha.fr
* \version 1
*
*/

#ifndef GRILLE_H_
#define GRILLE_H_

/* bibliotheques existantes */
#include <stdlib.h>
#include <stdio.h>

#include "const.h"

/* structure(s) */
/**
* \struct Damier grille.c grille.h
* \brief structure de damier pour jouer aux dames */
struct Damier{
    /*! nombre de pions blancs */
    int nb_blancs;
    /*! nombre de pions noirs */
    int nb_noirs;
    /*! nombre de dames blanches */
    int nb_dblanc;
    /*! nombre de dames noires */
    int nb_dnoir;
    /*! plateau de jeu (dimensions : 10x10) */
    int plateau[LIGNES][COLONNES];
};

typedef struct Damier* PDamier;

struct ListeDamier{
    PDamier damiers[MAX_DAMIER];
    int n;  
};

typedef struct ListeDamier* PListeDamier;

/* entêtes */

/**
* \fn new_damier()
* \brief constructeur de damier
* \param -
* \return référence sur un nouveau damier
*/
PDamier new_damier();

/**
* \fn init_damier(PDamier d)
* \brief initialisation du damier d
* \param d : référence sur un damier
* \return void
*/
void init_damier(PDamier d);

/**
* \fn affiche_damier(PDamier d)
* \brief affichage du damier d
* \param d : référence sur un damier
* \return référence sur un nouveau damier
*/
void afficher_damier(PDamier d);

/**
* \fn update_damier(PDamier d)
* \brief actualise le damier
* \param d : référence sur un damier
* \return void
*/
void update_damier(PDamier d);

PListeDamier init_listeDamier();
PListeDamier inserer(PDamier,PListeDamier);

/**
* \fn copieDamier(PDamier d)
* \brief copie et renvoie le damier copié
* \param d : damier à copier
* \return nouveau damier obtenu en copiant d
*/
PDamier copieDamier(PDamier d);
int compareDamier(PDamier,PDamier);
int comparePosPion(PDamier,PDamier);


#endif
