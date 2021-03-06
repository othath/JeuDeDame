#include <time.h>
#include <stdlib.h>
#include "jeu.h"
#include "rafle.h"
#include "ia.h"
#include "evaluation.h"
#include "alphabeta.h"
#include <unistd.h>
int plusDePieces(int tour, PDamier d){
    /* vérifie si le joueur dont c'est le tour n'a plus de pièces
     * si plus de pièces RETURN 0
     * si encore des pièces RETURN -1
     */
    if(tour%2 == 0){ // vérification sur le joueur blanc
        if(d->nb_blancs == 0 && d->nb_dblanc == 0){
            return 0;
        }
    }else{ // vérif sur le joueur noir
        if(d->nb_noirs == 0 && d->nb_dnoir == 0){
            return 0;
        }
    }
    return -1;
}

int bloque(int tour ,PDamier d){
    /* vérifie si le joureur dont c'est le tour est bloqué (retourne 0) ou pas (retourne -1) */
    /* renvoie une copie du plateau du damier d à l'instant t + bordure virtuelle */
    int cdv[LIGNES+2][COLONNES+2];
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
    int flag=0; // Drapeau de bloquage, passe à -1 si on trouve un mouvement
    for (int i=1; i<=LIGNES; i++){
        for (int j=1; j<=COLONNES; j++){
            if (tour%2==0 && cdv[i][j]==PION_BLANC){
                for (int k=-1; k<=1; k+=2){
                    for (int l=-1; l<=1; l+=2){
                        if ((cdv[i+k][j+l]==PION_NOIR && cdv[i+2*k][j+2*l]==VIDE) || cdv[i+k][j+l]==VIDE){
                            flag=-1;
                        }
                    }
                }
            }
            else if (tour%2==1 && cdv[i][j]==PION_NOIR){
                for (int k=-1; k<=1; k+=2){
                    for (int l=-1; l<=1; l+=2){
                        if ((cdv[i+k][j+l]==PION_BLANC && cdv[i+2*k][j+2*l]==VIDE) || cdv[i+k][j+l]==VIDE){
                            flag=-1;
                        }
                    }
                }
            }
            if (tour%2==0 && cdv[i][j]==DAME_BLANCHE && testdepDame(d, i-1, j-1)==0) flag=-1;
            else if (tour%2==1 && cdv[i][j]==DAME_NOIRE && testdepDame(d, i-1, j-1)==0) flag=-1;
        }
    }
    return flag;
}

int victoire(int tour, PDamier d){
    /* fonction temporaire , -1 si pas victoire*/
    int cas[]={plusDePieces(tour,d),bloque(tour,d)};
    int flag=-1;
    for (int i=0; i<sizeof(cas)/sizeof(int); i++){
        if (cas[i]==0) flag=0;
    }
    return flag;
}

int abandon(char* input, int tour){
    /* retourne 0 si le joueur abandonne, -1 sinon */
    char abandon[] = "abandon";
    int flag = 0;
    for(int i=0;i<7;i++){
        if(input[i] != abandon[i])
            flag = -1;
    }
    if(flag == 0){
        if(tour%2 == 0){ // abandon des blancs
            printf("Le joueur blanc a abandonné !\n");
        }
        if(tour%2 == 1){ // abandon des noirs
            printf("Le joueur noir a abandonné !\n");
        }
    }
    return flag;
}

int continuerJouer(PDamier d, int tour, int nb_prises){
    /* renvoie 0 si le joueur dont c'est le tour doit continuer à jouer */
    return 0;
}

int jeu(PDamier d){
    int tour = 0;
    PListeDamier ld=init_listeDamier();
    afficher_damier(d);
    inserer(d,ld);//inserer le plateau initiale pour savoir si la 1 position s'est repete meme si c'est un cas improbable
    while(victoire(tour, d) == -1 && egalite(d,ld)==-1){
    //while(1){
        //TODO : vérifier prise (automatique)
        /*
        for (int i=0; i<LIGNES; i++){
            for (int j=0; j<COLONNES; j++){
                int Case[2]={i,j};
                int* n=malloc(sizeof(int));
                *n=0;
                liste* l_rafle=malloc(100*sizeof(liste));
                if (rafle(d,tour%2,Case,l_rafle,n)!=0) printf("prise possible en (%i, %i)\n",i,j);
            }
        }
        */

       /* char input[MAX_INPUT];
        printf("Tour : %i\n", tour%2);
        printf("prises possibles : %i\n", priseObligatoire(d,tour%2));
        //printf("Syntaxe des coups : CASE_DE_DEPART CASE_ARRIVEE (ex : A1 B9)\n");
*/
            mv_aleatoire(d,tour%2);//juste pour le test
            update_damier(d);
            tour++;
           

       /*
        printf("Coup à jouer : ");
        fgets(input,MAX_INPUT,stdin);
        if(abandon(input,tour) == 0){ // abandon du joueur
            return 0;
        }
        while(checkInput(input) == -1){ // tant que input pas OK
            printf("Coup à jouer : ");
            fgets(input,MAX_INPUT,stdin);
        }

        while(choisir_deplacement(d,envoyerInput(input),tour%2) == -1){
            printf("Coup à jouer : ");
            fgets(input,MAX_INPUT,stdin);
            while(checkInput(input) == -1){ // tant que input pas OK
                printf("Coup à jouer : ");
                fgets(input,MAX_INPUT,stdin);
            }
        }
       // int *p;
        //int tabValeur[20];
        //p = tabEval(d, tabValeur);
        //printf("La valeur optimal est : %i\n",minimax(0,0,1,p,MIN,MAX));
        update_damier(d);
        tour++;
    }*/
}

    if(egalite(d,ld)==0){
       printf("egalite");// a ameliorer juste pour le test
    }
    else{
    if(tour%2 == 0){
        printf("Les noirs ont gagné !\n");
    }
    else{
        printf("Les blancs ont gagné !\n");
    }
}
    return 0;
}

int egalite(PDamier courant,PListeDamier ld){
  int counter_regle1=0;
  int counter_regle2=0;
  int counter_regle3=0;
// comparer le nb de pieces du damier courant avec le dernier damier stocke dans la liste
  if(ld->n>0){
     if(courant->nb_blancs+courant->nb_noirs+courant->nb_dblanc+courant->nb_dnoir == ld->damiers[ld->n-1]->nb_blancs +ld->damiers[ld->n-1]->nb_noirs+
          ld->damiers[ld->n-1]->nb_dblanc+ld->damiers[ld->n-1]->nb_dnoir) {
         // parcourir notre PlisteDamier et verifier si position du courant egale a un de la liste si oui incrementer counter si counter==3 return 1 donc egalite
         for(int i=ld->n-1;i>=0;i--){
             if(compareDamier(courant,ld->damiers[i])==0) counter_regle1++;
            //pas de deplacement des pions
             if(comparePosPion(courant,ld->damiers[i])==0) counter_regle2++;
            //tester si on a les pieces qui engendrent l'egalite pendant 16 coup
             else if(checkPiece(ld->damiers[i])==0) counter_regle3++;
           }
    }
      //ajout damier courant a la liste
      else inserer(courant,ld);
}


  // if position repeated 3 time, then return 0;
  if(counter_regle1==3) return 0;
 //si 25 coups sans aucun depPion ou prise(les prises sont gerees dans la condition qui compte le nb des pieces );
  if(counter_regle2==25) return 0;
  //si 16 coups avec meme pieces des regles d'egalite
  if(counter_regle3==16)  return 0;
  return -1;
}
int checkPiece(PDamier d){
     /*int nb_pblanc=0,nb_pnoir=0;
     int nb_dblanc=0,nb_dnoir=0;
     for(int i=0;i<LIGNES;i++){
         for(int j=0;j<COLONNES;j++){
                   if(d->plateau[i][j]==PION_BLANC) nb_pblanc++;
                   else if(d->plateau[i][j]==PION_NOIR) nb_pnoir++;
                   else if(d->plateau[i][j]==DAME_BLANCHE) nb_dblanc++;
                   else if(d->plateau[i][j]==DAME_NOIRE) nb_dnoir++;
            }
            }*/
     if((d->nb_noirs+d->nb_blancs==2) && (d->nb_dblanc+d->nb_dnoir==1))return 0; //cas 2 pions vs dame
     else if((d->nb_dnoir+d->nb_dblanc==5) && (d->nb_noirs+d->nb_blancs==1)) return 0;//cas 3 dames 2dames et un pion
     else if(d->nb_dblanc+d->nb_dnoir==3) return 0;// 3dames
     return -1;
 }




int *trouverCoup(PDamier jeu,int tour){ //return -1 si pas de coup possible SINON return le dep du premiere piece qu'on peut deplacer
     int nbPion=0,nbPionMax;
     int color;
     int dame;
     int *dep;
     if(tour%2==0) {
                    nbPionMax=jeu->nb_blancs+jeu->nb_dblanc;//nbPion dans le plateau
                    color=PION_BLANC;
                    dame=DAME_BLANCHE;
       }
     else{
                         nbPionMax=jeu->nb_noirs+jeu->nb_dnoir;
                         color=PION_NOIR;
                         dame=DAME_NOIRE;
      }
    int j;
        srand(time(NULL));
       while(nbPion<nbPionMax){
         
  for(int i=0;i<10;i++){
  //   for(j=0;j<10;j++){
       j = rand() % 10;
          if(jeu->plateau[i][j] == color)
         {  
             dep=testDep(jeu,i,j,tour);
            if(dep!=NULL){ //des qu on trouve un dep possible on le renvoie
                  //  printf("lignes:%d cologne:%d\n",i,j);
                return dep;
              }
        }            
            
         else if(jeu->plateau[i][j]==dame) {
                    dep=testdepDame(jeu,i,j);                    
                    if(dep !=NULL){                  
                     return dep;
              }
           }
                   }
//}

          nbPion++;
         }

   return NULL;
}

/*
void finJeu(PDamier jeu,int tour){
    if(plusDePieces(tour,jeu)==0) printf("FIN DE PARTIE ,PLUS DE PIECES :(\n");
    //TODO : implementer trouver un coup
    if(trouverCoup(jeu,tour)==-1) {
       printf("FIN DE PARTIE :(\n");
       if(tour%2!=0) printf("Aucun deplacement possible pour les noirs\n");
       else if (tour%2==0) printf("aucun deplacement possible pour les blancs\n");
 }
}
*/

int jeu_blanc(PDamier d, SOCKET chausette){
    int tour = 0;
    PListeDamier ld=init_listeDamier();
    afficher_damier(d);
    inserer(d,ld);//inserer le plateau initiale pour savoir si la 1 position s'est repete meme si c'est un cas improbable
    while(victoire(tour, d) == -1 && egalite(d,ld)==-1){
    //while(1){
        //TODO : vérifier prise (automatique)
        /*
        for (int i=0; i<LIGNES; i++){
            for (int j=0; j<COLONNES; j++){
                int Case[2]={i,j};
                int* n=malloc(sizeof(int));
                *n=0;
                liste* l_rafle=malloc(100*sizeof(liste));
                if (rafle(d,tour%2,Case,l_rafle,n)!=0) printf("prise possible en (%i, %i)\n",i,j);
            }
        }
        */

        char input[MAX_INPUT];
        printf("Tour : %i\n", tour%2);
        printf("prises possibles : %i\n", priseObligatoire(d,tour%2));
        printf("Syntaxe des coups : CASE_DE_DEPART CASE_ARRIVEE (ex : A1 B9)\n");
        /*
        mv_aleatoire(d,tour%2);//juste pour le test
            update_damier(d);
            tour++;
        sleep(3);
        */

        printf("Coup à jouer : ");
        fgets(input,MAX_INPUT,stdin);

        if(abandon(input,tour) == 0){ // abandon du joueur
            tcp_envoyer_court(chausette, (short)-1);
            return 0;
        }
        while(checkInput(input) == -1){ // tant que input pas OK
            printf("Coup à jouer : ");
            fgets(input,MAX_INPUT,stdin);
        }

        while(choisir_deplacement(d,envoyerInput(input),tour%2) == -1){
            printf("Coup à jouer : ");
            fgets(input,MAX_INPUT,stdin);
            while(checkInput(input) == -1){ // tant que input pas OK
                printf("Coup à jouer : ");
                fgets(input,MAX_INPUT,stdin);
            }
        }
        printf("envoi de l'entête...");
        tcp_envoyer_court(chausette, (short)2);
        printf(" envoyé, envoi du message...");
        char message[5];
        encode_normal(envoyerInput(input),message);
        tcp_ecrire(chausette, message);
        printf(" message '%s' envoyé\n",message);
        // int *p;
        //int tabValeur[20];
        //p = tabEval(d, tabValeur);
        //printf("La valeur optimal est : %i\n",minimax(0,0,1,p,MIN,MAX));
        update_damier(d);
        tour++;
        printf("En attente de l'en-tête adverse...\n");
        short taille=tcp_lire_court(chausette);
        printf("entête reçue, longeur: %i \n En attente du contenu...",taille);
        if (taille==-1) return -1;
        char* instruction=malloc(sizeof(char)*taille*2+2);
        tcp_lire(chausette, instruction, (taille*2));
        printf("contenu reçu: %s\n",instruction);
        if (taille==2){
            int code[4];
            decode_normal(instruction,code);
            if (choisir_deplacement(d, code, tour%2)==-1) return -1;
        }
        else{
            int rafle[taille][4];
            decode_rafle(instruction,rafle);
            for (int i=0; i<(sizeof(rafle)/sizeof(rafle[0])); i++){
                if (choisir_deplacement(d, rafle[i], tour%2)==-1) return -1;
            }
        }
        update_damier(d);
        tour++;
    }

    if(egalite(d,ld)==0){
       printf("egalite");// a ameliorer juste pour le test
    }
    else{
        if(tour%2 == 0){
            printf("Les noirs ont gagné !\n");
        }
        else{
            printf("Les blancs ont gagné !\n");
        }
    }
    return 0;
}

int jeu_noir(PDamier d, SOCKET chausette){
    int tour = 0;
    PListeDamier ld=init_listeDamier();
    afficher_damier(d);
    inserer(d,ld);//inserer le plateau initiale pour savoir si la 1 position s'est repete meme si c'est un cas improbable
    while(victoire(tour, d) == -1 && egalite(d,ld)==-1){
        printf("En attente de l'en-tête adverse...\n");
        short taille=tcp_lire_court(chausette);
        printf("entête reçue, longeur: %i \n En attente du contenu...",taille);
        if (taille==-1) return -1;
        char* instruction=malloc(sizeof(char)*taille*2+2);
        tcp_lire(chausette, instruction, (taille*2));
        printf("contenu reçu: %s\n",instruction);
        if (taille==2){
            int code[4];
            decode_normal(instruction,code);
            if (choisir_deplacement(d, code, tour%2)==-1) return -1;
        }
        else{
            int rafle[taille][4];
            decode_rafle(instruction,rafle);
            for (int i=0; i<(sizeof(rafle)/sizeof(rafle[0])); i++){
                if (choisir_deplacement(d, rafle[i], tour%2)==-1) return -1;
            }
        }
        update_damier(d);
        tour++;
    //while(1){
        //TODO : vérifier prise (automatique)
        /*
        for (int i=0; i<LIGNES; i++){
            for (int j=0; j<COLONNES; j++){
                int Case[2]={i,j};
                int* n=malloc(sizeof(int));
                *n=0;
                liste* l_rafle=malloc(100*sizeof(liste));
                if (rafle(d,tour%2,Case,l_rafle,n)!=0) printf("prise possible en (%i, %i)\n",i,j);
            }
        }
        */

        char input[MAX_INPUT];
        printf("Tour : %i\n", tour%2);
        printf("prises possibles : %i\n", priseObligatoire(d,tour%2));
        printf("Syntaxe des coups : CASE_DE_DEPART CASE_ARRIVEE (ex : A1 B9)\n");
        /*
        mv_aleatoire(d,tour%2);//juste pour le test
            update_damier(d);
            tour++;
        sleep(3);
        */

        printf("Coup à jouer : ");
        fgets(input,MAX_INPUT,stdin);

        if(abandon(input,tour) == 0){ // abandon du joueur
            tcp_envoyer_court(chausette, (short)-1);
            return 0;
        }
        while(checkInput(input) == -1){ // tant que input pas OK
            printf("Coup à jouer : ");
            fgets(input,MAX_INPUT,stdin);
        }

        while(choisir_deplacement(d,envoyerInput(input),tour%2) == -1){
            printf("Coup à jouer : ");
            fgets(input,MAX_INPUT,stdin);
            while(checkInput(input) == -1){ // tant que input pas OK
                printf("Coup à jouer : ");
                fgets(input,MAX_INPUT,stdin);
            }
        }
        printf("envoi de l'entête...");
        tcp_envoyer_court(chausette, (short)2);
        printf(" envoyé, envoi du message...");
        char message[5];
        encode_normal(envoyerInput(input),message);
        tcp_ecrire(chausette, message);
        printf(" message '%s' envoyé\n",message);
        // int *p;
        //int tabValeur[20];
        //p = tabEval(d, tabValeur);
        //printf("La valeur optimal est : %i\n",minimax(0,0,1,p,MIN,MAX));
        update_damier(d);
        tour++;
    }

    if(egalite(d,ld)==0){
       printf("egalite");// a ameliorer juste pour le test
    }
    else{
        if(tour%2 == 0){
            printf("Les noirs ont gagné !\n");
        }
        else{
            printf("Les blancs ont gagné !\n");
        }
    }
    return 0;
}
