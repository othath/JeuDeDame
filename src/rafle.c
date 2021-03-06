#include "rafle.h"

cel_t *new_cel(int x, int y){
	/* constructeur de cellule */
	cel_t *c = (cel_t*)malloc(sizeof(cel_t));
	c->x = x;
	c->y = y;
	c->svt = NULL;
	return c;
}

liste_t *liste_init(){
	/* constructeur d'une liste avec tête et queue et fictives */
	liste_t *l = (liste_t*)malloc(sizeof(liste_t));
	l->tete = new_cel(-1,-1);
	l->queue = new_cel(-1,-1);
	l->tete->svt = l->queue;
	l->longueur = 0;
	return l;
}

void cel_print(cel_t *c){
	/* affiche le contenu d'une cellule */
	printf("<Adresse> %p\n",c);
	printf("x = %i\ny = %i\n",c->x,c->y);
	printf("\n");
}

void liste_print(liste_t *l){
	/* affiche une liste chaînée */
	cel_t *cel;
	for(cel=l->tete; cel!=l->queue; cel=cel->svt){
			cel_print(cel);
	}
}

void liste_insere(liste_t *l, cel_t *c){
	/* insertion de la cellule cel_t juste après la tête.
	 * On insère à cette position pour optimiser la recherche,
	 * dans rafle, on regarde surtout si les cases autout n'ont pas déja été visitées,
	 * donc  c'est plus intéréssant d'insérer au début de liste pour éviter de devoir la parcourir entièrement chaque fois.
	 */
	c->svt = l->tete->svt;
	l->tete->svt = c;
	l->longueur++;
}

int liste_trouve(liste_t *l, int x, int y){
	/* renvoie 0 si on trouve le couple (x,y) dans une cellule de la liste, -1 sinon. */
	int trouve = -1;
	cel_t *cel;
	for(cel=l->tete; cel!=l->queue; cel=cel->svt){
		if(cel->x == x && cel->y == y){ // on a trouvé
			trouve = 0;
		}
	}
	return trouve;
}

int bordure(PDamier plateau, int position[2]){
	int x1 = position[0];
	int y1 = position[1];
	if((x1 < 0 || x1 > 9) && (y1 < 0 || y1 > 9)){
		return -1;
	}
	return 0;
}


int rafle(int position[2], PDamier plateau, int t, liste_t *l, int r_max){
    int y1 = position[0];
    int x1 = position[1];
    liste_insere(l,new_cel(x1,y1));
    int rafle_max = r_max;
	if(t==0){
		for(int i=-1; i<=1; i+=2){
				for(int j=-1; i<=1; i+=2){
						if((plateau->plateau[x1+i][y1+j] == PION_NOIR && plateau->plateau[x1+(i*2)][y1+(j*2)] == VIDE && bordure(plateau, position) == 0) || (plateau->plateau[x1+i][y1+j] == DAME_NOIRE && plateau->plateau[x1+(i*2)][y1+(j*2)] == VIDE && bordure(plateau, position) == 0)) {
							position[0] = y1+2*j;
							position[1] = x1+2*i;
							rafle_max = rafle(position, plateau, 0, l, rafle_max+1);
						}
						return rafle_max;
				}
		}
	}
	if(t==1){
		for(int i=-1; i<=1; i+=2){
				for(int j=-1; i<=1; i+=2){
					if ((plateau->plateau[x1+i][y1+j] == PION_BLANC && plateau->plateau[x1+(i*2)][y1+(j*2)] == VIDE && bordure(plateau, position) == 0) || (plateau->plateau[x1+i][y1+j] == DAME_BLANCHE && plateau->plateau[x1+(i*2)][y1+(j*2)] == VIDE && bordure(plateau, position) == 0)) {
						position[0] = y1+2*j;
						position [1] = x1+2*i;
						rafle_max = rafle(position, plateau, 1, l, rafle_max+1);
					}
					return rafle_max;
				}
		}
	}
	else
		printf("wtf? il est où le tour\n");
	return rafle_max;
}
