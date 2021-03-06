#include "deplacement.h"


int mv_normal(int code[4], PDamier damier, int tour){
    switch(damier->plateau[code[1]][code[0]]){
        case VIDE:
            printf("Erreur, case de départ vide !\n");
            return -1;
        case PION_BLANC:
            if(tour==1){
                printf("Erreur, ce n'est pas votre tour !\n");
                return -1;
            }
            if(code[3]==code[1]-1 && (code[2]==code[0]-1 || code[2]==code[0]+1) && damier->plateau[code[3]][code[2]] == VIDE){
                damier->plateau[code[1]][code[0]]=VIDE;
                damier->plateau[code[3]][code[2]]=PION_BLANC;
                return 0;
            }
            else{
               printf("Erreur, case d'arrivée non  valide !\n");
                return -1;
            }
        case PION_NOIR:
            if(tour==0){
                 printf("Erreur, ce n'est pas votre tour !\n");
                return -1;
            }
            if(code[3]==code[1]+1 && (code[2]==code[0]-1 || code[2]==code[0]+1) && damier->plateau[code[3]][code[2]] == VIDE){
                damier->plateau[code[1]][code[0]]=VIDE;
                damier->plateau[code[3]][code[2]]=PION_NOIR;
                return 0;
            }
            else{
                printf("Erreur, case d'arrivée non  valide !\n");
                return -1;
            }
        default:
            printf("Erreur inconnue !\n");
            return -1;
    }
}

void dame(PDamier plateau){
    /* 
    *	Auteur: Thomas LUCENAC
    *	Transformation d'un pion en Dame
    *	Principe:
    *	Pour toutes colonnes, si le pion noir ou blanc atteint l'opposé du damier il passe en status de dame 
    */
	for(int i=0; i<COLONNES; i++){ 
		if(plateau->plateau[9][i]==PION_NOIR){ // localisation du pion NOIR qui doit se transformer en dame
			plateau->plateau[9][i]=DAME_NOIRE; //modifie le pion en dame
            		plateau->nb_dnoir++; // rajoute une dame
           		plateau->nb_noirs--; // donc on perd un pion noir
		}
		if(plateau->plateau[0][i]==PION_BLANC){ // même situation que pour les pions NOIR mais pour les BLANC
			plateau->plateau[0][i]=DAME_BLANCHE;
            		plateau->nb_dblanc++;
            		plateau->nb_blancs--;
		}
	}
}
/*
int suite_prise_possible(PDamier plateau, int t, int position[4]){
    int x2 = position[3];
    int y2 = position[2];
    int new_position[4];
    for(int i = -1; i<=1; i++){
        for(int j = -1; j<=1; i++){
            if(t==0){
                if((plateau->plateau[x2+i][y2+j] == PION_NOIR || plateau->plateau[x2+i][y2+j] == DAME_NOIRE) && plateau->plateau[x2+(2*i)][y2+(2*j) == VIDE]){
                    return 1;
                }
            }
            if(t==1){
                if((plateau->plateau[x2+i][y2+j] == PION_BLANC || plateau->plateau[x2+i][y2+j] == DAME_BLANCHE) && plateau->plateau[x2+(2*i)][y2+(2*j) == VIDE]){
                    return 1;
            }
            else 
                return 0;
        }
    }

}
*/
int prise(PDamier plateau, int t, int position[4]){
    /* 
    *	Auteur: Thomas LUCENAC
    *	Effectuer la prise d'un pion
    *	Principe:
    *	En reprenant les coordonnées de déplacement de l'utilisateur, nous observons si il est possible de faire une prise.
    *	La fonction dépendra du tour et du mouvement que le joueur souhaite faire.
    */
    /*	x = ligne et y = colonne */
     int x1 = position[1];
     int y1 = position[0];
     int x2 = position[3];
     int y2 = position[2];
     /* Pion se trouvant entre la case de départ et celle de fin */
     int diff_x = (x2-x1)/2;
     int diff_y = (y2-y1)/2;
     if (!((position[3]==position[1]-2 && (position[2]==position[0]-2 || position[2]==position[0]+2)) || (position[3]==position[1]+2 && (position[2]==position[0]-2 || position[2]==position[0]+2)))){
        printf("cologne initiale :%d ligne ini:%d cologne finale :%d ligne finale:%d",y1,x1,y2,x2);
        /* si la case de déplacement pour une prise est différentes qu'une case se trouvant 2 unité plus loin et en diagonale alors on affiche une erreur*/
        printf("ERREUR: case d'arrivée invalide! \n"); 
        return -1;
     }
     if(plateau->plateau[x2][y2] == VIDE){	//si les coordonnées de fin sont vide alors faire la fonction prise
		if(plateau->plateau[x1+diff_x][y1+diff_y]==PION_NOIR){	//si c'est le tour des blancs alors on peut faire une prise noir
            if (t==0){
                plateau->plateau[x1+diff_x][y1+diff_y] = VIDE; // pion à prendre
                plateau->plateau[x1][y1] = VIDE; // pion avec lequel on fait une prise avec les coordonnées x1,y1
                plateau->nb_noirs--;	// on perds un pion noir
                plateau->plateau[x2][y2] = PION_BLANC; //les coordonnées de fin (x2,y2) sont remplacé par un pion  blanc
                /*if(suite_prise_possible(plateau, t, position)==1){
                    printf("Les %i peuvent continuer de jouer\n",t);
                    prise(plateau, t, position);
                    return t;
                }*/
                return 0;
            }
            else{
                printf("ERREUR: ce n'est pas votre pièce!\n");
                return -1;
            }
		}
		if(plateau->plateau[x1+diff_x][y1+diff_y]==PION_BLANC){ // tour des noirs
			if (t==1){
                plateau->plateau[x1+diff_x][y1+diff_y] = VIDE;
                plateau->plateau[x1][y1] = VIDE;
                plateau->nb_blancs--;
                plateau->plateau[x2][y2] = PION_NOIR;
                return 0;
			}
			else{
                printf("ERREUR: ce n'est pas votre pièce!\n");
                return -1;
			}
		}
        if(plateau->plateau[x1+diff_x][y1+diff_y]==DAME_NOIRE){
            if (t==0){
                plateau->plateau[x1+diff_x][y1+diff_y] = VIDE;
                plateau->plateau[x1][y1] = VIDE;
                plateau->nb_dnoir--;
                plateau->plateau[x2][y2] = PION_BLANC;
                return 0;
            }
            else{
                printf("ERREUR: ce n'est pas votre pièce!\n");
                return -1;
            }
        }
        if(plateau->plateau[x1+diff_x][y1+diff_y]==DAME_BLANCHE){
            if (t==1){
                plateau->plateau[x1+diff_x][y1+diff_y] = VIDE;
                plateau->plateau[x1][y1] = VIDE;
                plateau->nb_dblanc--;
                plateau->plateau[x2][y2] = PION_NOIR;
                return 0;
			}
			else{
                printf("ERREUR: ce n'est pas votre pièce!\n");
                return -1;
        }
        }
        else{
            printf("ERREUR: Prise invalide! \n"); // si la case n'est pas vide alors la prise est ivalide
            return -1;
        }
	}
	else{
		printf("Case d'arrivée non vide \n");
		return -1;
	}
}

int priseObligatoireDameHG(int v[], int i, int tour){
    /* renvoie le nombre de prises obligatoires pour une dame dans la diagonale haut gauche */
    
    int nb_prises_obligatoires = 0;
    if(tour == 0){
        // diagonale haut gauche (pour nous)
        while(v[i-13] != -1){
            if(v[i-13] == PION_NOIR || v[i-13] == DAME_NOIRE){
                if(v[i-26] == VIDE) nb_prises_obligatoires++;
                if(v[i-26] != VIDE) break;;
            }
            if(v[i-13] == PION_BLANC || v[i-13] == DAME_BLANCHE){
                break;
            }

            // si c'est vide
            i -= 13;
        }
    }
    if(tour == 1){
        // diagonale haut gauche (pour nous)
        while(v[i-13] != -1){
            if(v[i-13] == PION_BLANC || v[i-13] == DAME_BLANCHE){
                if(v[i-26] == VIDE) nb_prises_obligatoires++;
                if(v[i-26] != VIDE) break;
            }
            if(v[i-13] == PION_NOIR || v[i-13] == DAME_NOIRE){
                break;
            }

            // si c'est vide
            i -= 13;
        }
    }

    return nb_prises_obligatoires;
}

int priseObligatoireDameHD(int v[], int i, int tour){
    /* renvoie le nombre de prises obligatoire pour une dame dans la diagonale haut droit */
    int nb_prises_obligatoires = 0;
    if(tour == 0){
        // diagonale haut droit (pour nous)
        while(v[i-11] != -1){
            if(v[i-11] == PION_NOIR || v[i-11] == DAME_NOIRE){
                if(v[i-22] == VIDE) nb_prises_obligatoires++;
                if(v[i-22] != VIDE) break;
            }
            if(v[i-11] == PION_BLANC || v[i-11] == DAME_BLANCHE){
                break;
            }

            // si c'est vide
            i -= 11;
        }
    }
    if(tour == 1){
        // diagonale haut droit (pour nous)
        while(v[i-11] != -1){
            if(v[i-11] == PION_BLANC || v[i-11] == DAME_BLANCHE){
                if(v[i-22] == VIDE) nb_prises_obligatoires++;
                if(v[i-22] != VIDE) break;
            }
            if(v[i-11] == PION_NOIR || v[i-11] == DAME_NOIRE){
                break;
            }

            // si c'est vide
            i -= 11;
        }
    }
    return nb_prises_obligatoires;
}

int priseObligatoireDameBG(int v[], int i, int tour){
    /* renvoie le nombre de prises obligatoire dans la diagonale bas droit d'une dame */
    int nb_prises_obligatoires = 0;
    if(tour == 0){
        // diagonale haut droit (pour nous)
        while(v[i+11] != -1){
            if(v[i+11] == PION_NOIR || v[i+11] == DAME_NOIRE){
                if(v[i+22] == VIDE) nb_prises_obligatoires++;
                if(v[i+22] != VIDE) break;
            }
            if(v[i+11] == PION_BLANC || v[i+11] == DAME_BLANCHE){
                break;
            }

            // si c'est vide
            i += 11;
        }
    }
    if(tour == 1){
        // diagonale haut droit (pour nous)
        while(v[i+11] != -1){
            if(v[i+11] == PION_BLANC || v[i+11] == DAME_BLANCHE){
                if(v[i+22] == VIDE) nb_prises_obligatoires++;
                if(v[i+22] != VIDE) break;
            }
            if(v[i+11] == PION_NOIR || v[i+11] == DAME_NOIRE){
                break;
            }

            // si c'est vide
            i += 11;
        }
    }
    return nb_prises_obligatoires;
}

int priseObligatoireDameBD(int v[], int i, int tour){
    /* renvoie le nombre de prise obligatoire pour une dame dans sa diagonal bas droit */
    int nb_prises_obligatoires = 0;
    if(tour == 0){
        // diagonale haut droit (pour nous)
        while(v[i+13] != -1){
            if(v[i+13] == PION_NOIR || v[i+13] == DAME_NOIRE){
                if(v[i+26] == VIDE) nb_prises_obligatoires++;
                if(v[i+26] != VIDE) break;
            }
            if(v[i+13] == PION_BLANC || v[i+13] == DAME_BLANCHE){
                break;
            }

            // si c'est vide
            i += 13;
        }
    }
    if(tour == 1){
        // diagonale haut droit (pour nous)
        while(v[i+13] != -1){
            if(v[i+13] == PION_BLANC || v[i+13] == DAME_BLANCHE){
                if(v[i+26] == VIDE) nb_prises_obligatoires++;
                if(v[i+26] != VIDE) break;
            }
            if(v[i+13] == PION_NOIR || v[i+13] == DAME_NOIRE){
                break;
            }

            // si c'est vide
            i += 13;
        }
    }
    return nb_prises_obligatoires;
}

int priseObligatoireDame(int v[], int i, int tour){
    /* renvoie le nombre de prises obligatoires pour une dame */

    /*
     * on vérifie les 4 diagonales (hg, hd, bd, bg)
     * tant que la case en diagonale != -1 (virtuel), on continue
     * si case vide i -= 13
     * si la case n'est pas vide,
     *          si pion allié -> break
     *          si pion ennemi,
     *                  si case d'apres vide -> on a une prise possible
     *                  sinon -> break
     */

    /*
     *      i-13 |     | i-11
     *    ---------------------
     *           |  i  | 
     *    ---------------------
     *      i+11 |     | i+13
     *
     */

    int nb_prises_obligatoires = 0; // à renvoyer

    // on vérifie pour les blancs
    if(tour == 0){
        nb_prises_obligatoires += priseObligatoireDameHG(v, i, tour);
        nb_prises_obligatoires += priseObligatoireDameHD(v, i, tour);
        nb_prises_obligatoires += priseObligatoireDameBG(v, i, tour);
        nb_prises_obligatoires += priseObligatoireDameBD(v, i, tour);
    }

    // on vérifie pour les noirs
    if(tour == 1){
        nb_prises_obligatoires += priseObligatoireDameHG(v, i, tour);
        nb_prises_obligatoires += priseObligatoireDameHD(v, i, tour);
        nb_prises_obligatoires += priseObligatoireDameBG(v, i, tour);
        nb_prises_obligatoires += priseObligatoireDameBD(v, i, tour);
    }

    return nb_prises_obligatoires;
}

int priseObligatoirePion(int v[],int i, int tour){
    /* renvoie le nombre de prises obligatoires pour un pion */

    /*
     *      i-13 |     | i-11
     *    ---------------------
     *           |  i  | 
     *    ---------------------
     *      i+11 |     | i+13
     *
     */

    int nb_prises_possibles = 0;
    // on regarde d'abord les 4 coins dans le cas ou on joue les blancs
    if(tour == 0){
        if(v[i+13] == PION_NOIR || v[i+13] == DAME_NOIRE){
            // on doit vérifier si les voisins de PION_NOIR ou DAME_NOIR sont vide
            if(v[i+26] == VIDE) nb_prises_possibles++;
        }
        if(v[i+11] == PION_NOIR || v[i+11] == DAME_NOIRE){
            // on doit vérifier si les voisins de PION_NOIR ou DAME_NOIR sont vide
            if(v[i+22] == VIDE) nb_prises_possibles++;
        }
        if(v[i-11] == PION_NOIR || v[i-11] == DAME_NOIRE){
            // on doit vérifier si les voisins de PION_NOIR ou DAME_NOIR sont vide
            if(v[i-22] == VIDE) nb_prises_possibles++;
        }
        if(v[i-13] == PION_NOIR || v[i-13] == DAME_NOIRE){
            // on doit vérifier si les voisins de PION_NOIR ou DAME_NOIR sont vide
            if(v[i-26] == VIDE) nb_prises_possibles++;
        }
    }

    // pareil pour le cas ou on joue les noirs
    if(tour == 1){
        if(v[i+13] == PION_BLANC || v[i+13] == DAME_BLANCHE){
            // on doit vérifier si les voisins de PION_NOIR ou DAME_NOIR sont vide
            if(v[i+26] == VIDE) nb_prises_possibles++;
        }
        if(v[i+11] == PION_BLANC || v[i+11] == DAME_BLANCHE){
            // on doit vérifier si les voisins de PION_NOIR ou DAME_NOIR sont vide
            if(v[i+22] == VIDE) nb_prises_possibles++;
        }
        if(v[i-11] == PION_BLANC || v[i-11] == DAME_BLANCHE){
            // on doit vérifier si les voisins de PION_NOIR ou DAME_NOIR sont vide
            if(v[i-22] == VIDE) nb_prises_possibles++;
        }
        if(v[i-13] == PION_BLANC || v[i-13] == DAME_BLANCHE){
            // on doit vérifier si les voisins de PION_NOIR ou DAME_NOIR sont vide
            if(v[i-26] == VIDE) nb_prises_possibles++;
        }
    }
    return nb_prises_possibles;
}

int priseObligatoire(PDamier d, int tour){
    /* renvoie le nombre de prises obligatoires pour le joueur tour */

    // tableau avec bordures virtuelles initialisées à -1
    int cdv[LIGNES+2][COLONNES+2]; // cdv = copie damier virtuel
    for(int i=0;i<LIGNES+2;i++){
        for(int j=0;j<COLONNES+2;j++){
            if(i == 0) cdv[i][j] = -1;
            else if(j == 0) cdv[i][j] = -1;
            else if(i == LIGNES+1) cdv[i][j] = -1;
            else if(j == COLONNES+1) cdv[i][j] = -1;
            else{
                cdv[i][j] = d->plateau[i-1][j-1];
            }
        }
    }

    // on crée un tableau 1D à partir du tableau virtuel 2D
    int v[144]; // 12*12
    int k = 0;
    for(int i=0; i<LIGNES+2; i++){
        for(int j=0; j<COLONNES+2; j++){
            v[k] = cdv[i][j];
            k++;
        }
    }

    int nb_prises_obligatoires = 0; // à renvoyer

    for(int i=0; i<144; i++){
        if(tour == 0){ // tour des blancs
            if(v[i] == PION_BLANC){
                nb_prises_obligatoires += priseObligatoirePion(v, i, tour);
                
            }
            if(v[i] == DAME_BLANCHE){
                nb_prises_obligatoires += priseObligatoireDame(v, i, tour);
                
            }
        }
        if(tour == 1){ // tour des noirs
            if(v[i] == PION_NOIR){
                nb_prises_obligatoires += priseObligatoirePion(v, i, tour);
                
            }
            if(v[i] == DAME_NOIRE){
                nb_prises_obligatoires += priseObligatoireDame(v, i, tour);
                
            }
        }
    }

    return nb_prises_obligatoires;
}

int nombrePrisesPourUnPion(PDamier d, int tour, int i, int j){
    /* renvoie le nombre de prise pour un pion situé en i (ligne) et j (colonne) */

    // création d'un tableau virtuel avec des bordures initialisées à -1
    int cdv[LIGNES+2][COLONNES+2]; // cdv = copie damier virtuel
    for(int i=0;i<LIGNES+2;i++){
        for(int j=0;j<COLONNES+2;j++){
            if(i == 0) cdv[i][j] = -1;
            else if(j == 0) cdv[i][j] = -1;
            else if(i == LIGNES+1) cdv[i][j] = -1;
            else if(j == COLONNES+1) cdv[i][j] = -1;
            else{
                cdv[i][j] = d->plateau[i-1][j-1];
            }
        }
    }
    
    // on compte
    int nb_prises = 0;

    /* on compte, en faisant attention aux index,
     * si dans le damier, on est à la position i,
     * alors on est à la position i+1 dans le damier virtuel,
     * pareil pour j,
     * j(damier) ==> j+1(damier virtuel)
     */

    if(tour == 0){ // tour du joueur blanc
        if(cdv[i+1-1][j+1-1] == PION_NOIR || cdv[i+1-1][j+1-1] == DAME_NOIRE){ // diagonale haut gauche
            if(cdv[i+1-2][j+1-2] == VIDE) nb_prises++;
        }
        if(cdv[i+1-1][j+1+1] == PION_NOIR || cdv[i+1-1][j+1+1] == DAME_NOIRE){ // diagonale haut droite
            if(cdv[i+1-2][j+1+2] == VIDE) nb_prises++;
        }
        if(cdv[i+1+1][j+1-1] == PION_NOIR || cdv[i+1+1][j+1-1] == DAME_NOIRE){ // diagonale bas gauche
            if(cdv[i+1+2][j+1-2] == VIDE) nb_prises++;
        }
        if(cdv[i+1+1][j+1+1] == PION_NOIR || cdv[i+1+1][j+1+1] == DAME_NOIRE){ // diagonale bas droite
            if(cdv[i+1+2][j+1+2] == VIDE) nb_prises++;
        }
    }
    else{ // tour du joueur noir
        if(cdv[i+1-1][j+1-1] == PION_BLANC || cdv[i+1-1][j+1-1] == DAME_BLANCHE){ // diagonale haut gauche
            if(cdv[i+1-2][j+1-2] == VIDE) nb_prises++;
        }
        if(cdv[i+1-1][j+1+1] == PION_BLANC || cdv[i+1-1][j+1+1] == DAME_BLANCHE){ // diagonale haut droite
            if(cdv[i+1-2][j+1+2] == VIDE) nb_prises++;
        }
        if(cdv[i+1+1][j+1-1] == PION_BLANC || cdv[i+1+1][j+1-1] == DAME_BLANCHE){ // diagonale bas gauche
            if(cdv[i+1+2][j+1-2] == VIDE) nb_prises++;
        }
        if(cdv[i+1+1][j+1+1] == PION_BLANC || cdv[i+1+1][j+1+1] == DAME_BLANCHE){ // diagonale bas droite
            if(cdv[i+1+2][j+1+2] == VIDE) nb_prises++;
        }
    }
    return nb_prises;
}

/*int* prisesPourUnPion(PDamier d, int tour, int i, int j){
    /* renvoie un tableau qui détermine quelles prises un pion peut faire */

    // création d'un tableau virtuel avec des bordures initialisées à -1
 /*   int cdv[LIGNES+2][COLONNES+2]; // cdv = copie damier virtuel
    for(int i=0;i<LIGNES+2;i++){
        for(int j=0;j<COLONNES+2;j++){
            if(i == 0) cdv[i][j] = -1;
            else if(j == 0) cdv[i][j] = -1;
            else if(i == LIGNES+1) cdv[i][j] = -1;
            else if(j == COLONNES+1) cdv[i][j] = -1;
            else{
                cdv[i][j] = d->plateau[i-1][j-1];
            }
        }
    }

    /* on compte, en faisant attention aux index,
     * si dans le damier, on est à la position i,
     * alors on est à la position i+1 dans le damier virtuel,
     * pareil pour j,
     * j(damier) ==> j+1(damier virtuel)
     */
/*
    int *prises = (int*)malloc(4*sizeof(int));

    if(tour == 0){ // tour du joueur blanc
        if(cdv[i+1-1][j+1-1] == PION_NOIR || cdv[i+1-1][j+1-1] == DAME_NOIRE){ // diagonale haut gauche
            if(cdv[i+1-2][j+1-2] == VIDE) *prises = 1;
       // printf("HG tour:%d Prises1:%d\n",tour,*prises);
         }
        if(cdv[i+1-1][j+1+1] == PION_NOIR || cdv[i+1-1][j+1+1] == DAME_NOIRE){ // diagonale haut droite
            if(cdv[i+1-2][j+1+2] == VIDE) *(prises+1) = 1;
     //printf("HD tour:%d Prises1:%d\n",tour,*(prises+1));
        }
        if(cdv[i+1][j-1] == PION_NOIR || cdv[i+1+1][j+1-1] == DAME_NOIRE){ // diagonale bas gauche
            if(cdv[i+2][j-2] == VIDE) *(prises+2) = 1;
       //                 printf("BG tour:%d Prises1:%d\n",tour,*(prises+2));
        }
        if(cdv[i+1][j+1] == PION_NOIR || cdv[i+1+1][j+1+1] == DAME_NOIRE){ // diagonale bas droite
                     
            if(cdv[i+2][j+2] == VIDE){ *(prises+3) = 1;
            printf("BD tour:%d [%d][%d]:%d Prises3:%d\n",tour,i+1+1,j+1+1,cdv[i+1][j+1],*(prises+3));
}
        }
    }
    else{ // tour du joueur noir
        if(cdv[i+1-1][j+1-1] == PION_BLANC || cdv[i+1-1][j+1-1] == DAME_BLANCHE){ // diagonale haut gauche
            if(cdv[i+1-2][j+1-2] == VIDE) *prises = 1;
               printf("HG tour:%d Prises1:%d\n",tour,*(prises));
        }
        if(cdv[i+1-1][j+1+1] == PION_BLANC || cdv[i+1-1][j+1+1] == DAME_BLANCHE){ // diagonale haut droite
            if(cdv[i+1-2][j+1+2] == VIDE) *(prises+1) = 1;
               printf("HD tour:%d Prises1:%d\n",tour,*(prises+1));
        }
        if(cdv[i+1+1][j+1-1] == PION_BLANC || cdv[i+1+1][j+1-1] == DAME_BLANCHE){ // diagonale bas gauche
            if(cdv[i+1+2][j+1-2] == VIDE) *(prises+2) = 1;
              printf("BG tour:%d Prises1:%d\n",tour,*(prises+2));
        }
        if(cdv[i+1+1][j+1+1] == PION_BLANC || cdv[i+1+1][j+1+1] == DAME_BLANCHE){ // diagonale bas droite
            if(cdv[i+1+2][j+1+2] == VIDE) *(prises+3) = 1;
        }
    }
    return prises;
}*/

int prise_dame(PDamier plateau, int t, int position[4]){
    /* 
    *	Auteur: Thomas LUCENAC
    *	Effectuer la prise de n'importe quelle pièce par une dame
    *	Principe:
    * 	Effectue la prise par une dame d'un quelconque pion, à n'importe quelle distance de la dame
    */
	int y1 = position[0];							//position initial x1
	int x1 = position[1];							//position initial y1
	int y2 = position[2];							//position final x2
	int x2 = position[3];							//position final y2
	int diff_x = x2 - x1;							//x2 position de fin en x (A-J), x1 position inital en x (A-J)
	int diff_y = y2 - y1;							//y2 position de fin en y (0-9), y1 position inital en y (0-9)
	int hg=fmin(position[1],position[0]); // nombre de cases en haut à gauche de la dame
    int hd=fmin(position[1],COLONNES-1-position[0]); // nombre de cases en haut à droite de la dame
    int bg=fmin(LIGNES-1-position[1],position[0]); // nombre de cases en bas à gauche de la dame
    int bd=fmin(LIGNES-1-position[1],COLONNES-1-position[0]); // nombre de cases en bas à droite de la dame
    int flag=-1;
    for (int i=0; i<=hg; i++){
        if (position[1]-i==position[3] && position[0]-i==position[2]){
            flag=0;
        }
    }
    for (int i=0; i<=hd; i++){
        if (position[1]-i==position[3] && position[0]+i==position[2]){
            flag=0;
        }
    }
    for (int i=0; i<=bg; i++){
        if (position[1]+i==position[3] && position[0]-i==position[2]){
            flag=0;
        }
    }
    for (int i=0; i<=bd; i++){
        if (position[1]+i==position[3] && position[0]+i==position[2]){
           flag=0;
        }
    }
    if (flag==-1){
        //printf("ERREUR: déplacement invalide!\n");
        return -1;
    }
	if(t==1 && plateau->plateau[x1][y1] == DAME_NOIRE){				//pour le tour des noirs
		if(diff_x < 0 && diff_y < 0){						//haut-gauche
				for(int i = 0; i<=abs(diff_x); i++){			//pour tout i ce trouvant entre les coordonnées du point de base(x1,y1) et les coordonnées finales(x2,y2) 
					if(plateau->plateau[x1-i][y1-i] == DAME_BLANCHE || plateau->plateau[x1-i][y1-i] == PION_BLANC){	//si il y a un pion blanc entre la position de base et la position finale
                        			if(plateau->plateau[x1-i][y1-i] == DAME_BLANCHE) plateau->nb_dblanc--;
                        			if(plateau->plateau[x1-i][y1-i] == PION_BLANC) plateau->nb_blancs--;
						plateau->plateau[x1-i][y1-i]=VIDE;	//supprimer le pion
					}
				}
				plateau->plateau[x2][y2]=DAME_NOIRE;	//position finale remplacer par la dame
				plateau->plateau[x1][y1]=VIDE;	//position initial vide du au déplacement de la dame
				return 0;
				/* on refait la même chose pour toutes les diagonales et si c'est au tour des noirs*/
		}
		if(diff_x > 0 && diff_y < 0){						//haut-droite
				for(int i = 0; i<=abs(diff_x); i++){
					if(plateau->plateau[x1+i][y1-i] == DAME_BLANCHE || plateau->plateau[x1+i][y1-i] == PION_BLANC){
                        			if(plateau->plateau[x1+i][y1-i] == DAME_BLANCHE) plateau->nb_dblanc--;
                        			if(plateau->plateau[x1+i][y1-i] == PION_BLANC) plateau->nb_blancs--;
						plateau->plateau[x1+i][y1-i]=VIDE;
					}
				}
				plateau->plateau[x2][y2]=DAME_NOIRE;
				plateau->plateau[x1][y1]=VIDE;
				return 0;
		}
		if(diff_x < 0 && diff_y > 0){							//bas gauche
				for(int i = 0; i<=abs(diff_x); i++){
					if(plateau->plateau[x1-i][y1+i] == DAME_BLANCHE || plateau->plateau[x1-i][y1+i] == PION_BLANC){
						if(plateau->plateau[x1-i][y1+i] == DAME_BLANCHE) plateau->nb_dblanc--;
                        			if(plateau->plateau[x1-i][y1+i] == PION_BLANC) plateau->nb_blancs--;
                        			plateau->plateau[x1-i][y1+i]=VIDE;
					}
				}
				plateau->plateau[x2][y2]=DAME_NOIRE;
				plateau->plateau[x1][y1]=VIDE;
				return 0;
		}
		if(diff_x > 0 && diff_y > 0){						//bas droit
				for(int i = 0; i<=abs(diff_x); i++){
					if(plateau->plateau[x1+i][y1+i] == DAME_BLANCHE || plateau->plateau[x1+i][y1+i] == PION_BLANC){
						if(plateau->plateau[x1+i][y1+i] == DAME_BLANCHE) plateau->nb_dblanc--;
                  				if(plateau->plateau[x1+i][y1+i] == PION_BLANC) plateau->nb_blancs--;
                 			       plateau->plateau[x1+i][y1+i]=VIDE;
					}
				}
				plateau->plateau[x2][y2]=DAME_NOIRE;
				plateau->plateau[x1][y1]=VIDE;
				return 0;
		}
		return -1;
	}
	if(t==0 && plateau->plateau[x1][y1] == DAME_BLANCHE){
		if(diff_x < 0 && diff_y < 0){						//haut-gauche
				for(int i = 0; i<=abs(diff_x); i++){
					if(plateau->plateau[x1-i][y1-i] == DAME_NOIRE || plateau->plateau[x1-i][y1-i] == PION_NOIR){
						if(plateau->plateau[x1-i][y1-i] == DAME_NOIRE) plateau->nb_dnoir--;
                     				if(plateau->plateau[x1-i][y1-i] == PION_NOIR) plateau->nb_noirs--;
                 				plateau->plateau[x1-i][y1-i]=VIDE;
					}
				}
				plateau->plateau[x2][y2]=DAME_BLANCHE;
				plateau->plateau[x1][y1]=VIDE;
				return 0;
		}
		if(diff_x > 0 && diff_y < 0){						//haut-droite
				for(int i = 0; i<=abs(diff_x); i++){
					if(plateau->plateau[x1+i][y1-i] == DAME_NOIRE || plateau->plateau[x1+i][y1-i] == PION_NOIR){
                        if(plateau->plateau[x1+i][y1-i] == DAME_NOIRE) plateau->nb_dnoir--;
                        if(plateau->plateau[x1+i][y1-i] == PION_NOIR) plateau->nb_noirs--;
						plateau->plateau[x1+i][y1-i]=VIDE;
					}
				}
				plateau->plateau[x2][y2]=DAME_BLANCHE;
				plateau->plateau[x1][y1]=VIDE;
				return 0;
		}
		if(diff_x < 0 && diff_y > 0){							//bas gauche
				for(int i = 0; i<=abs(diff_x); i++){
					if(plateau->plateau[x1-i][y1+i] == DAME_NOIRE || plateau->plateau[x1-i][y1+i] == PION_NOIR){
						if(plateau->plateau[x1-i][y1+i] == DAME_NOIRE) plateau->nb_dnoir--;
                        if(plateau->plateau[x1-i][y1+i] == PION_NOIR) plateau->nb_noirs--;
                        plateau->plateau[x1-i][y1+i]=VIDE;
					}
				}
				plateau->plateau[x2][y2]=DAME_BLANCHE;
				plateau->plateau[x1][y1]=VIDE;
				return 0;
		}
		if(diff_x > 0 && diff_y > 0){						//bas droit
				for(int i = 0; i<=abs(diff_x); i++){
					if(plateau->plateau[x1+i][y1+i] == DAME_NOIRE || plateau->plateau[x1+i][y1+i] == PION_NOIR){
						if(plateau->plateau[x1+i][y1+i] == DAME_NOIRE) plateau->nb_dnoir--;
                        if(plateau->plateau[x1+i][y1+i] == PION_NOIR) plateau->nb_noirs--;
                        plateau->plateau[x1+i][y1+i]=VIDE;
					}
				}
				plateau->plateau[x2][y2]=DAME_BLANCHE;
				plateau->plateau[x1][y1]=VIDE;
				return 0;
		}
		return -1;
	}
	return -1;
}
int *testDep(PDamier jeu,int ligne,int cologne,int tour){ 
//return null si aucun deplacement possible  ,sinon return un deplacement aleatoire possible pour utiliser danns fct aleatoire d'ordinateur 
     int* dep = (int*)malloc(4*sizeof(int));//tableau de deplacement
   //tour des NOIRs
     if(tour%2!=0 && ligne<LIGNES-1 && cologne< COLONNES-1) {     
        if(cologne==0 && jeu->plateau[ligne+1][cologne+1]==VIDE){ 
            *(dep) =cologne;           
            *(dep+1) =ligne;
            *(dep+2) =cologne+1;
            *(dep+3) =ligne+1;
            return dep;
          }
        if (cologne-1>=0 && cologne<COLONNES-1){  
                if(jeu->plateau[ligne+1][cologne+1]==VIDE && jeu->plateau[ligne+1][cologne-1]==VIDE){
                     int choix[]={cologne+1,cologne-1};
                     int c = rand() % 2;
                      *(dep) =cologne;           
                      *(dep+1) =ligne;
                      *(dep+2) =choix[c];
                      *(dep+3) =ligne+1;
                return dep;
               }
              if(jeu->plateau[ligne+1][cologne+1]==VIDE){
                *(dep) =cologne;           
                *(dep+1) =ligne;
                *(dep+2) =cologne+1;
                *(dep+3) =ligne+1;
                return dep;
               }
            if(jeu->plateau[ligne+1][cologne-1]==VIDE){
                *(dep) =cologne;           
                *(dep+1) =ligne;
                *(dep+2) =cologne-1;
                *(dep+3) =ligne+1;
                return dep;
             }
          }
        if (cologne==COLONNES-1  && (jeu->plateau[ligne+1][cologne-1]==VIDE)){
            *(dep) =cologne;           
            *(dep+1) =ligne;
            *(dep+2) =cologne-1;
            *(dep+3) =ligne+1;
            return dep;
         }
     }
   //tour des blancs
     if(tour%2==0 && ligne>0 && cologne< COLONNES-1) {     
        if(cologne==0 && jeu->plateau[ligne-1][cologne+1]==VIDE){
            *(dep) =cologne;           
            *(dep+1) =ligne;
            *(dep+2) =cologne+1;
            *(dep+3) =ligne-1;
            return dep;
          }
        if (cologne-1>=0 && cologne<COLONNES-1){  
               if(jeu->plateau[ligne-1][cologne+1]==VIDE && jeu->plateau[ligne-1][cologne-1]==VIDE){
                     int choix[]={cologne-1,cologne+1};
                     int c = rand() % 2;
                      *(dep) =cologne;           
                      *(dep+1) =ligne;
                      *(dep+2) =choix[c];
                      *(dep+3) =ligne-1;
                return dep;
               }
              if(jeu->plateau[ligne-1][cologne+1]==VIDE){
                *(dep) =cologne;           
                *(dep+1) =ligne;
                *(dep+2) =cologne+1;
                *(dep+3) =ligne-1;
                return dep;
               }
              if(jeu->plateau[ligne-1][cologne-1]==VIDE){
                *(dep) =cologne;           
                *(dep+1) =ligne;
                *(dep+2) =cologne-1;
                *(dep+3) =ligne-1;
                return dep;
              }
        }
       if (cologne==COLONNES-1  && (jeu->plateau[ligne-1][cologne-1]==VIDE)){
            *(dep) =cologne;           
            *(dep+1) =ligne;
            *(dep+2) =cologne-1;
            *(dep+3) =ligne-1;
            return dep;
       }
    }
   return NULL;
}
int* testdepDame(PDamier jeu,int ligne,int cologne){ //return NULL si pas de mouvement possible
     int* dep = (int*)malloc(4*sizeof(int));//tableau de deplacement
   //test haut gauche
        if(ligne>2 && cologne>2){
            if(jeu->plateau[ligne-2][cologne-2]==VIDE && jeu->plateau[ligne-1][cologne-1]==VIDE){
               int choix[]={cologne-1,cologne-2};
                     int c = rand() % 2;
                    if(c==1){
                *(dep)=cologne;
                *(dep+1)=ligne;
                *(dep+2)=choix[c];
                *(dep+3)=ligne-2;
                return dep;
                }
                else{   
                *(dep)=cologne;
                *(dep+1)=ligne;
                *(dep+2)=choix[c];
                *(dep+3)=ligne-1;
                return dep;
                }
            }
}           
            if(ligne>1 && cologne>1 ){
             if(jeu->plateau[ligne-2][cologne-2]==VIDE && jeu->plateau[ligne-1][cologne-1]!=VIDE) {
                *(dep) =cologne;           
                *(dep+1) =ligne;
                *(dep+2) =cologne-2;
                *(dep+3) =ligne-2;
                return dep;
                }   
            if(ligne>0 && cologne>0 ){
             if(jeu->plateau[ligne-1][cologne-1]==VIDE && jeu->plateau[ligne-2][cologne-2]!=VIDE) {
                *(dep) =cologne;           
                *(dep+1) =ligne;
                *(dep+2) =cologne-1;
                *(dep+3) =ligne-1;
                return dep;
                }   
}
   //test haut droite
                if(ligne>2 && cologne<COLONNES-2 && jeu->plateau[ligne-1][cologne+1]==VIDE && jeu->plateau[ligne-2][cologne+2]==VIDE){
               int choix[]={cologne+1,cologne+2};
                     int c = rand() % 2;
                    if(c==1){
                *(dep)=cologne;
                *(dep+1)=ligne;
                *(dep+2)=choix[c];
                *(dep+3)=ligne-2;
                return dep;
                }
                else{   
                *(dep)=cologne;
                *(dep+1)=ligne;
                *(dep+2)=choix[c];
                *(dep+3)=ligne-1;
                return dep;
                }
            }
}    
              if(ligne>0 && cologne <COLONNES-1 && jeu->plateau[ligne-1][cologne+1]==VIDE && jeu->plateau[ligne-2][cologne+2]!=VIDE) {
                *(dep) =cologne;           
                *(dep+1) =ligne;
                *(dep+2) =cologne+1;
                *(dep+3) =ligne-1;
                return dep;
            } 
             if (ligne>1 && cologne <COLONNES-1 && jeu->plateau[ligne-2][cologne+2]==VIDE && jeu->plateau[ligne-1][cologne+1]!=VIDE) {
                  *(dep) =cologne;           
                *(dep+1) =ligne;
                *(dep+2) =cologne+2;
                *(dep+3) =ligne-2;
                return dep;
            }
   //test bas gauche
            if(ligne<LIGNES-1 && cologne>1 && jeu->plateau[ligne+1][cologne-1]==VIDE && jeu->plateau[ligne+2][cologne-2]==VIDE){
                int choix[]={cologne-1,cologne-2};
                int c = rand() % 2;
                if(c==1){
                *(dep)=cologne;
                *(dep+1)=ligne;
                *(dep+2)=choix[c];
                *(dep+3)=ligne+2;
                return dep;
                }
                else{   
                *(dep)=cologne;
                *(dep+1)=ligne;
                *(dep+2)=choix[c];
                *(dep+3)=ligne+1;
                return dep;
                }
            }
             if(ligne<LIGNES-1 && cologne>1 && jeu->plateau[ligne+1][cologne-1]==VIDE && jeu->plateau[ligne+2][cologne-2]!=VIDE){
                *(dep) =cologne;           
                *(dep+1) =ligne;
                *(dep+2) =cologne-1;
                *(dep+3) =ligne+1;
                return dep;
                } 
             if(ligne<LIGNES-2 && cologne>2 && jeu->plateau[ligne+2][cologne-2]==VIDE && jeu->plateau[ligne+1][cologne-1]!=VIDE) {
                    *(dep) =cologne;           
                *(dep+1) =ligne;
                *(dep+2) =cologne-2;
                *(dep+3) =ligne+2;
                return dep;             
                }

  // test bas droite
              if(ligne<LIGNES-1 && cologne<COLONNES-1 && jeu->plateau[ligne+1][cologne+1]==VIDE && jeu->plateau[ligne+2][cologne+2]==VIDE){
                int choix[]={cologne+1,cologne+2};
                int c = rand() % 2;
                if(c==1){
                *(dep)=cologne;
                *(dep+1)=ligne;
                *(dep+2)=choix[c];
                *(dep+3)=ligne+2;
                return dep;
                }
                else{   
                *(dep)=cologne;
                *(dep+1)=ligne;
                *(dep+2)=choix[c];
                *(dep+3)=ligne+1;
                return dep;
                }
            }
             if(ligne<LIGNES-1 && cologne<COLONNES-1 && jeu->plateau[ligne+1][cologne+1]==VIDE && jeu->plateau[ligne+2][cologne+2]!=VIDE) {
                *(dep) =cologne;           
                *(dep+1) =ligne;
                *(dep+2) =cologne+1;
                *(dep+3) =ligne+1;
                return dep;
            }
             if(ligne<LIGNES-2 && cologne<COLONNES-2 && jeu->plateau[ligne+2][cologne+2]==VIDE && jeu->plateau[ligne+1][cologne+1]!=VIDE) {
                *(dep) =cologne;           
                *(dep+1) =ligne;
                *(dep+2) =cologne+2;
                *(dep+3) =ligne+2;
                return dep;
             }
    return NULL;
}

int depDame(int code[4], PDamier damier, int tour){ 
    //printf("%s--> fonction depDame %s\n", RED,reset);
    if ((tour==0 && damier->plateau[code[1]][code[0]]==DAME_NOIRE) || (tour==1 && damier->plateau[code[1]][code[0]]==DAME_BLANCHE)){
        //printf("ERREUR: Ce n'est pas votre pièce!\n");
        return -1;
    }
    int hg=fmin(code[1],code[0]); // nombre de cases en haut à gauche de la dame
    int hd=fmin(code[1],COLONNES-1-code[0]); // nombre de cases en haut à droite de la dame
    int bg=fmin(LIGNES-1-code[1],code[0]); // nombre de cases en bas à gauche de la dame
    int bd=fmin(LIGNES-1-code[1],COLONNES-1-code[0]); // nombre de cases en bas à droite de la dame
    for (int i=0; i<=hg; i++){
        if (code[1]-i==code[3] && code[0]-i==code[2]){
            if(damier->plateau[code[3]][code[2]]==VIDE){
                if (damier->plateau[code[1]][code[0]]==DAME_BLANCHE){
                    damier->plateau[code[1]][code[0]]=VIDE;
                    damier->plateau[code[3]][code[2]]=DAME_BLANCHE;
                    //printf("Déplacement de la dame blanche en haut à gauche \n");
                    return 0;
                }
                else{
                    damier->plateau[code[1]][code[0]]=VIDE;
                    damier->plateau[code[3]][code[2]]=DAME_NOIRE;
                    //printf("Déplacement de la dame noire en haut à gauche \n");
                    return 0;
                }
            }
            else{
                //printf("ERREUR: Case d'arrivée non nule! \n");
                return -1;
            }
        }
    }
    for (int i=0; i<=hd; i++){
        if (code[1]-i==code[3] && code[0]+i==code[2]){
            if(damier->plateau[code[3]][code[2]]==VIDE){
                if (damier->plateau[code[1]][code[0]]==DAME_BLANCHE){
                    damier->plateau[code[1]][code[0]]=VIDE;
                    damier->plateau[code[3]][code[2]]=DAME_BLANCHE;
                    //printf("Déplacement de la dame blanche en haut à droite \n");
                    return 0;
                }
                else{
                    damier->plateau[code[1]][code[0]]=VIDE;
                    damier->plateau[code[3]][code[2]]=DAME_NOIRE;
                    //printf("Déplacement de la dame noire en haut à droite \n");
                    return 0;
                }
            }
            else{
                //printf("ERREUR: Case d'arrivée non nule! \n");
                return -1;
            }
        }
    }
    for (int i=0; i<=bg; i++){
        if (code[1]+i==code[3] && code[0]-i==code[2]){
            if(damier->plateau[code[3]][code[2]]==VIDE){
                if (damier->plateau[code[1]][code[0]]==DAME_BLANCHE){
                    damier->plateau[code[1]][code[0]]=VIDE;
                    damier->plateau[code[3]][code[2]]=DAME_BLANCHE;
                    //printf("Déplacement de la dame blanche en bas à gauche \n");
                    return 0;
                }
                else{
                    damier->plateau[code[1]][code[0]]=VIDE;
                    damier->plateau[code[3]][code[2]]=DAME_NOIRE;
                    //printf("Déplacement de la dame noire en bas à gauche \n");
                    return 0;
                }
            }
            else{
                //printf("ERREUR: Case d'arrivée non nule! \n");
                return -1;
            }
        }
    }
    for (int i=0; i<=bd; i++){
        if (code[1]+i==code[3] && code[0]+i==code[2]){
            if(damier->plateau[code[3]][code[2]]==VIDE){
                if (damier->plateau[code[1]][code[0]]==DAME_BLANCHE){
                    damier->plateau[code[1]][code[0]]=VIDE;
                    damier->plateau[code[3]][code[2]]=DAME_BLANCHE;
                    //printf("Déplacement de la dame blanche en bas à droite \n");
                    return 0;
                }
                else{
                    damier->plateau[code[1]][code[0]]=VIDE;
                    damier->plateau[code[3]][code[2]]=DAME_NOIRE;
                    //printf("Déplacement de la dame noire en bas à droite \n");
                    return 0;
                }
            }
            else{
                //printf("ERREUR: Case d'arrivée non nule! \n");
                return -1;
            }
        }
    }
    //printf("ERREUR: case d'arrivée non valide!\n");
    return -1;
}

int deplacementOuPrise(PDamier plateau, int position[4], int tour){
    /* 
    *	Auteur: Thomas LUCENAC
    *	Choisir si on fait un déplacement ou une prise
    *	Principe:
    * 	On va vérifier le nombre de pion entre la position inital et la position final
    */
	int y1 = position[0];							//position initial x1
	int x1 = position[1];							//position initial y1
	int y2 = position[2];							//position final x2
	int x2 = position[3];							//position final y2
	int diff_x = x2 - x1;							//x2 position de fin en x (A-J), x1 position inital en x (A-J)
   	int diff_y = y2 - y1;							//y2 position de fin en y (0-9), y1 position inital en y (0-9)
    	int e = -1; 								// nbr de pions adverses initialisé à -1 car nous nous comptons nous même aussi
	if(plateau->plateau[x2][y2] == VIDE){					//si la position final est vide
		if(diff_x < 0 && diff_y < 0){						//haut-gauche
			for(int i = 0; i<=abs(diff_x); i++){
				if(plateau->plateau[x1-i][y1-i] != VIDE){		//si il y a un pion entre la case de départ et celle finale incrémenter le nombre d'ennemie
					e++;
				}
                if(tour == 0 && plateau->plateau[x1-1-i][y1-1-i] == DAME_BLANCHE){	//si après le pion localisé en premier on trouve un autre pion, alors on bloque le mouvement
                    return -1;
                }
                if(tour == 1 && plateau->plateau[x1-1-i][y1-1-i] == DAME_NOIRE){
                    return -1;
                }
			}
		}
		if(diff_x > 0 && diff_y < 0){						//haut-droit
			for(int i = 0; i<=abs(diff_x); i++){
				if(plateau->plateau[x1+i][y1-i] != VIDE){
					e++;
				}
                if(tour == 0 && plateau->plateau[x1+1+i][y1-1-i] == DAME_BLANCHE){
                    return -1;
                }
                if(tour == 1 && plateau->plateau[x1+1+i][y1-1-i] == DAME_NOIRE){
                    return -1;
                }
			}
		}
		if(diff_x < 0 && diff_y > 0){							//bas gauche
			for(int i = 0; i<=abs(diff_x); i++){
				if(plateau->plateau[x1-1-i][y1+1+i] != VIDE){
					e++;
				}
                if(tour == 0 && plateau->plateau[x1-1-i][y1+1+i] == DAME_BLANCHE){
                    return -1;
                }
                if(tour == 1 && plateau->plateau[x1-1-i][y1+1+i] == DAME_NOIRE){
                    return -1;
                }
			}
		}
		if(diff_x > 0 && diff_y > 0){						//bas droit
			for(int i = 0; i<=abs(diff_x); i++){
				if(plateau->plateau[x1+i][y1+i] != VIDE){
					e++;
				}
                if(tour == 0 && plateau->plateau[x1+1+i][y1+1+i] == DAME_BLANCHE){
                    return -1;
                }
                if(tour == 1 && plateau->plateau[x1+1+i][y1+1+i] == DAME_NOIRE){
                    return -1;
                }
			}
		}
	}
	else{
		printf("case d'arrivée non vide\n");
		return -1;
	}
	if(e > 1){	//si le nombre de pion et supérieur à 0 alors on bloque le mouvement
		printf("trop de pions\n");
		return -1;
	}
	if(e == 1){	//si le nombre de pion et de 1 alors on peut faire une prise de pion grâce à une dame
		return prise_dame(plateau, tour, position);
	}
	if( e == 0){	//si il n'y a pas de pion on peut faire un déplacement
        return depDame(position, plateau, tour);
	}
    return -1;
}



int choisir_deplacement(PDamier damier, int code[4], int tour){
    int dep=abs(code[3]-code[1]); // Nombre de cases de déplacement
    switch (dep){
        case 1:
            if(damier->plateau[code[1]][code[0]] == PION_NOIR || damier->plateau[code[1]][code[0]] == PION_BLANC || damier->plateau[code[1]][code[0]] == 0){
                return mv_normal(code, damier, tour);
            }
            else{ // dame
                return depDame(code, damier, tour);
            }
        case 2:
            if (damier->plateau[code[1]][code[0]] == DAME_BLANCHE || damier->plateau[code[1]][code[0]] == DAME_NOIRE){
                return deplacementOuPrise(damier,code,tour);
            }
            else{
                return prise(damier, tour, code);
            }
        default:
        if (damier->plateau[code[1]][code[0]] == DAME_BLANCHE || damier->plateau[code[1]][code[0]] == DAME_NOIRE){
            return deplacementOuPrise(damier,code,tour);
        }
        else{
            return mv_normal(code, damier, tour);
        }
    }
}
