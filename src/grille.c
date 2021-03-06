#include "grille.h"
#include "deplacement.h"


PDamier new_damier(){
    /* créé un nouveau damier et initialise toute la grille à 0 */
    PDamier d = (PDamier)malloc(sizeof(struct Damier));
    d->nb_blancs = 0;
    d->nb_noirs = 0;
    d->nb_dblanc = 0;
    d->nb_dnoir = 0;
    for(int i=0; i<LIGNES; i++){
        for(int j=0; j<COLONNES; j++){
            d->plateau[i][j] = VIDE;
        }
    }
    return d;
}

void init_damier(PDamier d){
    /* initialise le damier en placant les pions noirs et les pions blancs au bon endroit */
    d->nb_noirs=20;
    d->nb_blancs=20;
    for (int i=0; i<10; i+=2){
        /* remplissage des pions noirs */
        d->plateau[0][i+1]=PION_NOIR;
        d->plateau[2][i+1]=PION_NOIR;
        d->plateau[1][i]=PION_NOIR;
        d->plateau[3][i]=PION_NOIR;
        /* remplissage des pions blancs */
        d->plateau[7][i]=PION_BLANC;
        d->plateau[9][i]=PION_BLANC;
        d->plateau[6][i+1]=PION_BLANC;
        d->plateau[8][i+1]=PION_BLANC;
    }
}
void afficher_damier(PDamier d){
    /* affiche le damier */

    printf("\n");
    printf("\t%s    0  1  2  3  4  5  6  7  8  9    %s", GRISM,reset);
    printf("\t%s • %i  ♛ %i %s\n",BGFG,d->nb_noirs,d->nb_dnoir,reset);
    for(int i=0; i<LIGNES; i++){
        for(int j=0; j<COLONNES; j++){
            if(j==0) printf("\t%s %c %s", GRISM,(char)(65+i),reset);
            if(i%2 == 0){
                if(j%2==1) printf("%s",BRBLKB);
                else printf("%s",WHTHB);
            }
            else{
                if(j%2==0) printf("%s",BRBLKB);
                else printf("%s",WHTHB);
            }
            if(d->plateau[i][j] == PION_BLANC){
                printf(" • ");
            }
            else if(d->plateau[i][j] == PION_NOIR){
                printf("%s • %s",PN,reset);
            }
            else if(d->plateau[i][j] == DAME_BLANCHE){
                printf(" ♛ ");
            }
            else if(d->plateau[i][j] == DAME_NOIRE){
                printf("%s ♛ %s",PN,reset);
            }
            else if(d->plateau[i][j] == VIDE){
                printf("   ");
            }
            printf("%s",reset);
            if(j==9) printf("%s %c %s", GRISM,(char)(65+i), reset);

        }
        printf("\n");
    }
    printf("\t%s    0  1  2  3  4  5  6  7  8  9    %s", GRISM,reset);
    printf("\t%s • %i  ♛ %i %s\n",GRISM,d->nb_blancs,d->nb_dblanc,reset);


}

void update_damier(PDamier d){
    /* actualise et affiche la grille */
    dame(d);
    afficher_damier(d);
}

PDamier copieDamier(PDamier d){
    /* renvoie la copie exacte du damier à l'instant t*/
    PDamier d2 = new_damier();
    d2->nb_blancs = d->nb_blancs;
    d2->nb_noirs = d->nb_noirs;
    d2->nb_dblanc = d->nb_dblanc;
    d2->nb_dnoir = d->nb_dnoir;
    for(int i=0;i<LIGNES;i++){
        for(int j=0;j<COLONNES;j++){
            d2->plateau[i][j] = d->plateau[i][j];
        }
    }
    return d2;
}
int compareDamier(PDamier d,PDamier l){
     int count=0;//counter have to be 100 si les deux plateaux sont egaux
     for(int i=0;i<LIGNES;i++){
          for(int j=0;j<COLONNES;j++){
               if(d->plateau[i][j] == l->plateau[i][j]) count++;             
          }
   }
   if(count==LIGNES*COLONNES) return 0;
   return -1;
}
int comparePosPion(PDamier d,PDamier l){
      int count=0;
      int nbPion=d->nb_blancs+d->nb_noirs;
     for(int i=0;i<LIGNES;i++){
          for(int j=0;j<COLONNES;j++){
               if((d->plateau[i][j]==PION_NOIR && l->plateau[i][j]==PION_NOIR) || (l->plateau[i][j]==PION_BLANC && d->plateau[i][j]== PION_BLANC)) count++;             
              // printf("COUNTER:%d--%d\t%d\n",count,d->plateau[i][j],l->plateau[i][j]);
             }
   }
   if(count==nbPion) return 0;
   return -1;
}
PListeDamier init_listeDamier(){
   PListeDamier ld=(PListeDamier)malloc(sizeof(struct ListeDamier));
  //for(int i=0;i<MAX_DAMIER;i++) init_damier(ld->damiers+i);
   //new_damier(ld->damiers[0]);
   ld->n=0;
 return ld;
}
PListeDamier inserer(PDamier d,PListeDamier ld){ //inserer en fin de liste
      ld->damiers[ld->n]=copieDamier(d);
      ld->n++;
      return ld;
}
