#ifndef VOISINAGE_H_
#define VOISINAGE_H_

#include <stdlib.h>
#include <stdio.h>
#include "grille.h"


// structure pion

struct Pion{
	int couleur; //1 blanc 2 noir
	int type; //1 si dame 10 si pion
	char position[2]; //coordonnées de la pièce
	struct Pion* voisins[4]; //tableau regroupant tout les pions voisins
	};
typedef struct Pion* PPion;


PPion newPion(int c,int t,int i, int j, PDamier d);

void voisinage(int i, int j, PPion p, PDamier d);

#endif