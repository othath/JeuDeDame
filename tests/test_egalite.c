#include<stdlib.h>
#include "../src/jeu.h"
#include "../src/grille.h"
#include "../src/input.h"

int main(){
         PDamier d=new_damier();
         init_damier(d);
         /* lancement du jeu */
         int tour = 0;
         PListeDamier ld=init_listeDamier();
         afficher_damier(d);
         inserer(d,ld);//inserer le plateau initiale pour savoir si la 1 position s'est repete meme si c'est un cas improbable
         while(egalite(d,ld)==-1){
               char input[MAX_INPUT];
        printf("Tour : %i\n", tour%2);
        printf("prises possibles : %i\n", priseObligatoire(d,tour%2));
        //printf("Syntaxe des coups : CASE_DE_DEPART CASE_ARRIVEE (ex : A1 B9)\n");
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
        update_damier(d);
        tour++;
    }
     if(egalite(d,ld)==0){ 
       printf("EGALITE");
    }
  return EXIT_SUCCESS;
}
