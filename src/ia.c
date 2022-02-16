#include "ia.h"
#include "deplacement_ia.h"

PPiece new_piece(int c, int type, int pos[]){
    PPiece p = (PPiece)malloc(sizeof(struct Piece));
    p->couleur = c;
    p->type = type;
    p->position[0] = pos[0];
    p->position[1] = pos[1];
    return p;
}

int aleatoire(PPiece p_b, PPiece p_n, PDamier d, int code[4], int tour){
	
	int nbPion=0;
	int nbPionMax;
	
	if(tour%2==0) { 
		nbPionMax=d->nb_blancs+d->nb_dblanc;//nbPion dans le plateau color=PION_BLANC; 
		} 
		else if(tour%2!=0){ 
		nbPionMax=d->nb_noirs+d->nb_dnoir; 
		//color=PION_NOIR; 
		}
	
	while(nbPion<nbPionMax){
	
		int i = rand() % nbPionMax/2;
		int x1 = (2*i);
		int y1 = (2*i)+1;
		code[0] = p_b->position[x1];
		code[1] = p_b->position[y1];
		//definir code[2] et code [3]
		switch(d->plateau[code[1]][code[0]]){
		case PION_BLANC:
			if (d->plateau[code[0]-1][code[1]-1]==VIDE){
				code[2]=code[0]-1;
				code[3]=code[1]-1;
				}
			if (d->plateau[code[0]+1][code[1]-1]==VIDE){
				code[2]=code[0]+1;
				code[3]=code[1]-1;
				}
			if (d->plateau[code[0]-2][code[1]-2]==VIDE){
				code[2]=code[0]-2;
				code[3]=code[1]-2;
				}
			if (d->plateau[code[0]+2][code[1]-2]==VIDE){
				code[2]=code[0]+2;
				code[3]=code[1]-2;
				}
		case PION_NOIR:
			if (d->plateau[code[0]+1][code[1]+1]==VIDE){
				code[2]=code[0]+1;
				code[3]=code[1]+1;
				}
			if (d->plateau[code[0]-1][code[1]+1]==VIDE){
				code[2]=code[0]-1;
				code[3]=code[1]+1;
				}
			if (d->plateau[code[0]+2][code[1]+2]==VIDE){
				code[2]=code[0]+2;
				code[3]=code[1]+2;
				}
			if (d->plateau[code[0]-2][code[1]+2]==VIDE){
				code[2]=code[0]-2;
				code[3]=code[1]+2;
				}
		}

	if (mv_normal(code, d, tour) == 0){
		return 0;
		exit(0);//Deplacement simple
	}
	if (prise(d, tour, code) == 0){
		return 0;
		exit(0);//Prise simple (obligatoire)
	}
	else{
		nbPion++; //Rien donc on réitère l'opération
		return -1;}
	}
return 0;
}
int mv_aleatoire(PDamier d,int tour){
    int* dep;
    dep=trouverCoup(d,tour);
     if(checkPrisePion(d,tour)==0) return 0;
    if(checkPriseDame(d,tour)==0) return 0;
	/* mouvement aléatoire */
    else if(dep!=NULL){ //on a trouve un coup 
        if(d->plateau[*(dep+1)][*dep]==PION_BLANC || d->plateau[*(dep+1)][*dep]==PION_NOIR){
       	if(mv_normal(dep, d, tour)==0) return 0; //Dep des pions
        }
        else{
        if(depDame(dep,d,tour)==0) return 0;
    }
}
   tour++;
 	return -1; 
}
int checkPrisePion(PDamier d,int tour){ // parcours tous les pions et check s'il a une prise possible'
    int *check;
    int* pos;
    for(int i=0;i<10;i++){
        for(int j=0;j<10;j++){
            check=prisesPourUnPion(d,tour,i,j);
            if(check[0] ==1){//hg
             *pos=j;
             *(pos+1)=i;
              *(pos+2)=j-2;
                *(pos+3)=i-2;
            prise(d,tour,pos);
            return 0;
            }  
               
            if(check[1] ==1){//hd
             *pos=j;
             *(pos+1)=i;
              *(pos+2)=j+2;
                *(pos+3)=i-2;
             prise(d,tour,pos);
            return 0;
            }  
    
            if(check[2] ==1){//bg
             *pos=j;
             *(pos+1)=i;
              *(pos+2)=j-2;
                *(pos+3)=i+2;
            prise(d,tour,pos);
            return 0;
            }   

            if(check[3] ==1){//bd
             *pos=j;
             *(pos+1)=i;
              *(pos+2)=j+2;
             prise(d,tour,pos);
            return 0;
            }   
    }
}
return -1;
}
int checkPriseDame(PDamier d,int tour){
  int *check;
    int* pos;
    for(int i=0;i<10;i++){
        for(int j=0;j<10;j++){
            check=prisesPourDame(d,tour,i,j);
            if(check[0] ==1){//hg
             *pos=j;
             *(pos+1)=i;
              *(pos+2)=j-2;
                *(pos+3)=i-2;
            prise_dame(d,tour,pos);
            return 0;
            }  
               
            if(check[1] ==1){//hd
             *pos=j;
             *(pos+1)=i;
              *(pos+2)=j+2;
                *(pos+3)=i-2;
             prise_dame(d,tour,pos);
            return 0;
            }  
    
            if(check[2] ==1){//bg
             *pos=j;
             *(pos+1)=i;
              *(pos+2)=j-2;
                *(pos+3)=i+2;
            prise_dame(d,tour,pos);
            return 0;
            }   

            if(check[3] ==1){//bd
             *pos=j;
             *(pos+1)=i;
              *(pos+2)=j+2;
                *(pos+3)=i+2;
             prise_dame(d,tour,pos);
            return 0;
            }   
    }
}
return -1;
}
  
int *prisesPourDame(PDamier d,int tour,int i ,int j){ 
    int cdv[LIGNES][COLONNES]; // cdv = copie damier virtuel
    for(int i=0;i<LIGNES;i++){
        for(int j=0;j<COLONNES;j++){
                cdv[i][j] = d->plateau[i][j];
        }
    }
    int *prises = (int*)malloc(4*sizeof(int));
    for(int i=0;i<4;i++) *(prises+i) = 0;
    if(tour == 0){ // tour du joueur blanc
        if(cdv[i][j]==DAME_BLANCHE){
         if(i>1 && j>1){
        if(cdv[i-1][j-1] == PION_NOIR || cdv[i-1][j-1] == DAME_NOIRE){ // diagonale haut gauche
            if(cdv[i-2][j-2] == VIDE) *prises = 1;
         }
}   
     if(i>1 && j<COLONNES-2){
        if(cdv[i-1][j+1] == PION_NOIR || cdv[i-1][j+1] == DAME_NOIRE){ // diagonale haut droite
            if(cdv[i-2][j+2] == VIDE) *(prises+1) = 1;
        }
}   
        if(i<LIGNES-2 && j>1){
        if(cdv[i+1][j-1] == PION_NOIR || cdv[i+1][j-1] == DAME_NOIRE){ // diagonale bas gauche
            if(cdv[i+2][j-2] == VIDE){ *(prises+2) = 1;
        }}
}
        if(i<LIGNES-2 && j<COLONNES-2){
        if(cdv[i+1][j+1] == PION_NOIR || cdv[i+1][j+1] == DAME_NOIRE){ // diagonale bas droite       
            if(cdv[i+2][j+2] == VIDE){ *(prises+3) = 1;
}}
        }

    }}
    else{ // tour du joueur noir
          if(cdv[i][j]==DAME_NOIRE){
         if(i>1 && j>1 ){
        if(cdv[i-1][j-1] == PION_BLANC || cdv[i-1][j-1] == DAME_BLANCHE){ // diagonale haut gauche
            if(cdv[i-2][j-2] == VIDE) *prises = 1;
        }
}
    if(i>1 && j<COLONNES-2){
        if(cdv[i-1][j+1] == PION_BLANC || cdv[i-1][j+1] == DAME_BLANCHE){ // diagonale haut droite
            if(cdv[i-2][j+2] == VIDE) *(prises+1) = 1;
        }}

        if(i<LIGNES-2 && j>1 ){
        if(cdv[i+1][j-1] == PION_BLANC || cdv[i+1][j-1] == DAME_BLANCHE){ // diagonale bas gauche
            if(cdv[i+2][j-2] == VIDE) *(prises+2) = 1;
        }}
        if(i<LIGNES-2 && j<COLONNES-2){
        if(cdv[i+1][j+1] == PION_BLANC || cdv[i+1][j+1] == DAME_BLANCHE){ // diagonale bas droite
            if(cdv[i+2][j+2] == VIDE) *(prises+3) = 1;
        }
}
}
    }


    return prises;
}
int* prisesPourUnPion(PDamier d, int tour, int i, int j){
    
    int cdv[LIGNES][COLONNES]; // cdv = copie damier virtuel
    for(int k=0;k<LIGNES;k++){
        for(int l=0;l<COLONNES;l++){
        
                cdv[k][l] = d->plateau[k][l];
            
        }
    }
    int *prises = (int*)malloc(4*sizeof(int));
   // for(int i=0;i<4;i++) *(prises+i) = 0;
    if(tour == 0){ // tour du joueur blanc
        if(cdv[i][j]==PION_BLANC){
         if(i>1 && j>1){
        if(cdv[i-1][j-1] == PION_NOIR || cdv[i-1][j-1] == DAME_NOIRE){ // diagonale haut gauche
            if(cdv[i-2][j-2] == VIDE) *prises = 1;
         }
}   
     if(i>1 && j<COLONNES-2){
        if(cdv[i-1][j+1] == PION_NOIR || cdv[i-1][j+1] == DAME_NOIRE){ // diagonale haut droite
            if(cdv[i-2][j+2] == VIDE) *(prises+1) = 1;
        }
}   
        if(i<LIGNES-2 && j>1){
        if(cdv[i+1][j-1] == PION_NOIR || cdv[i+1][j-1] == DAME_NOIRE){ // diagonale bas gauche
            if(cdv[i+2][j-2] == VIDE){ *(prises+2) = 1;
        }}
}
        if(i<LIGNES-2 && j<COLONNES-2){
        if(cdv[i+1][j+1] == PION_NOIR || cdv[i+1][j+1] == DAME_NOIRE){ // diagonale bas droite       
            if(cdv[i+2][j+2] == VIDE){ *(prises+3) = 1;
}}
        }

    }}
    else{ // tour du joueur noir
          if(cdv[i][j]==PION_NOIR){
         if(i>1 && j>1 ){
        if(cdv[i-1][j-1] == PION_BLANC || cdv[i-1][j-1] == DAME_BLANCHE){ // diagonale haut gauche
            if(cdv[i-2][j-2] == VIDE) *prises = 1;
        }
}
    if(i>1 && j<COLONNES-2){
        if(cdv[i-1][j+1] == PION_BLANC || cdv[i-1][j+1] == DAME_BLANCHE){ // diagonale haut droite
            if(cdv[i-2][j+2] == VIDE) *(prises+1) = 1;
        }}

        if(i<LIGNES-2 && j>1 ){
        if(cdv[i+1][j-1] == PION_BLANC || cdv[i+1][j-1] == DAME_BLANCHE){ // diagonale bas gauche
            if(cdv[i+2][j-2] == VIDE) *(prises+2) = 1;
        }}
        if(i<LIGNES-2 && j<COLONNES-2){
        if(cdv[i+1][j+1] == PION_BLANC || cdv[i+1][j+1] == DAME_BLANCHE){ // diagonale bas droite
            if(cdv[i+2][j+2] == VIDE) *(prises+3) = 1;
        }
}
}
    }


    return prises;
}
