/**
* \file ihm.h
* \brief Création de l'interface graphique
* \author albi.grainca@uha.fr, jerry.chan@uha.fr
* \version 1
*
*/
#ifndef IHM_H_
#define IHM_H_

#include <gtk/gtk.h>

#include "../src/grille.h"
#include "../src/const.h"
#include "../src/input.h"
#include "../src/deplacement.h"

/* Hauteur et largeur de la fenêtre */
#define HAUTEUR 510
#define LARGEUR 480
/* Hauteur et largeur des carreaux du damier */
#define RHauteur 40
#define RLargeur 40
/* Hauteur et largeur des dames */
#define Dhauteur 20
#define Dlargeur 20
/* Diamètre des pions */
#define DIAMETRE 10

/* Constructeur */

/* Différent dessins */
/**
* \fn fermerFenetre()
* \brief constructeur qui arrêter la boucle d'événement principal 
* \param widget : paramètre qui utilise un pointeur pour faire appel au widget
*/
void fermerFenetre(GtkWidget *widget, gpointer data);
void clear(cairo_t *cr);

/* Différent dessins */
/**
* \fn dessinBordure(cairo_t *cr)
* \brief constructeur qui crée les borudures autour du damier
* \param cr : paramètre qui utilise un pointeur du cr
*/
void dessinBordure(cairo_t *cr);

/**
* \fn dessinContour(cairo_t *cr)
* \brief constructeur qui crée les contours du damier
* \param cr : paramètre qui utilise un pointeur ce
*/
void dessinContour(cairo_t *cr);

/**
* \fn dessinDamier(cairo_t *cr)
* \brief constructeur qui crée le damier avec ces différentes cases
* \param cr : paramètre qui utilise un pointeur ce
*/
void dessinDamier(cairo_t *cr);

/**
* \fn dessinPieces(cairo_t *cr)
* \brief constructeur qui crée les Pions et les Dames
* \param cr : paramètre qui utilise un pointeur cr
*/
void dessinPieces(cairo_t *cr);

/**
* \fn dessinTour(cairo_t *cr)
* \brief constructeur qui crée l'affichage du nombre de pions blanc
* \param cr : paramètre qui utilise un pointeur cr
*/
void dessinTour(cairo_t *cr);

/**
* \fn draw_cb(GtkWidget *widget, cairo_t *cr, gpointer data)
* \brief constructeur fait appel à tout les dessins qui ont été créé
* \param widget : paramètre qui reprend la widget *cr : reprend le cr
* \param cr : reprend le cr
* \return return FALSE;
*/
gboolean draw_cb(GtkWidget *widget, cairo_t *cr, gpointer data);

/* Zone de texte */
/**
* \fn activationEntree(GtkEntry *entry, gpointer data)
* \brief constructeur recupère le texte entré dans la zone de texte pour quand on appuie sur la touche entré le texte s'envoi
* \param entry : pointeur qui reprend le texte ecrit
*/
void activationEntree(GtkEntry *entry, gpointer data);

#endif