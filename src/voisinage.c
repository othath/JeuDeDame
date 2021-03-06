#include "voisinage.h"

//Il faut déclarer une fonction pour les pions que l'ordinateur aura au debut d'une partie donc PION_ORDINATEUR==PION_BLANC ou PION_ORDINATEUR==PION_NOIR. Pareil pour les dame


//On part du principe que les pions ordinaterus seront blancs donc de valeur 1


void voisinage(int i, int j, PPion p, PDamier d){
	int e=0;
	//Parcours des cases voisines
	for (i=i-1 ;i<=1; i+=2){
		for (j=j-1; j<=1; j+=2){
			if (d->plateau[i][j]==1){//Test si pion blanc
				p->voisins[e]= newPion(1,1,i,j,d); 
				e++;
				}
			if (d->plateau[i][j]==10){//Test si dame blanche
				p->voisins[e]= newPion(1,10,i,j,d); 
				e++;
				}
			if (d->plateau[i][j]==2) {//Test si pion noir
				p->voisins[e]= newPion(2,1,i,j,d); 
				e++;
			}
			if (d->plateau[i][j]==20){//Test si dame noire
				p->voisins[e]= newPion(2,10,i,j,d); 
				e++;
			}
			else { 
				p->voisins[e]=0;//Donne la case vide.
				e++;
			}
		}
	}
}

//Constructeur de pion
PPion newPion(int c,int t,int i, int j, PDamier d){
	PPion p = (PPion)malloc(sizeof(struct Pion));
	p->couleur = c;
	printf("Init couleur du pion : %i", p->couleur);
	p->type = t;
	printf("Init type du pion : %i", p->type);
	p->position[0] = i;
	printf("Init position du pion : %c", p->position[0]);
	p->position[1] = j;
	printf("Init position 2 du pion : %c", p->position[1]);
	voisinage(i,j,p,d);//execution de voisinage qui va initialiser les voisins.
	return p;
}