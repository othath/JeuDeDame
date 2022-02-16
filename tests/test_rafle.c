/*
 *
 * Pour compiler :
 *   se placer dans le dossier tests
 *      (cd ../src; gcc -c *.c; mv *.o ../tests);gcc -c test_rafle.c; gcc *.o -o test_rafle
 * Pour exécuter :
 *   ./test_rafle
 * 
 */

#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#include "../src/grille.h"
#include "../src/rafle.h"

/* couleurs pour l'affichage */
#define ROUGE "\e[0;31m"
#define VERT "\e[0;32m"
#define MAGENTA "\e[0;35m"
#define res "\e[0m"

void run_test(int (*f)(), int *runs, int*fails){
    /* lancement des tests */
    printf("%s===> Test numéro %02i : %s",MAGENTA,(*runs)+1,res);
    if(!f()){
        (*fails)++;
        printf("%sFAILED%s\n",ROUGE,res);
    }
    else{
        printf("%sOK%s\n",VERT,res);
    }
    (*runs)++;
}

int test_rafle_blanc(){
    /* teste la rafle pour les blancs */

    // on crée les données du problème
    PDamier d = new_damier();
    int tab[10][10] =  {{0,0,0,0,0,0,0,0,0,0},  //tableau de valeur de référence
                        {0,0,0,0,0,0,0,0,0,0},
                        {0,0,0,0,0,0,2,0,0,0},
                        {0,0,0,0,0,0,0,0,0,0},
                        {0,0,0,0,2,0,0,0,0,0},
                        {0,0,0,0,0,0,0,0,0,0},
                        {0,0,2,0,0,0,0,0,0,0},
                        {0,1,0,0,0,0,0,0,0,0},
                        {0,0,0,0,0,0,0,0,0,0},
                        {0,0,0,0,0,0,0,0,0,0}};
    memcpy(d->plateau,tab,4*10*4*10);
    int expected = 3;
    int pos[2] = {1,7};
    liste_t *l = liste_init();
    int actual = rafle(pos,d,0,l,0);

    if(actual != expected){
        fprintf(stderr,"\ttest_rafle_blanc, rafle : expecting %i while got %i\n",expected,actual);
        return 0;
    }
    return 1;
}

int test_rafle_blanc2(){
    /* teste la rafle pour les blancs */

    // on crée les données du problème
    PDamier d = new_damier();
    int tab[10][10] =  {{0,0,0,0,0,0,0,0,0,0},  //tableau de valeur de référence
                        {0,0,0,0,0,0,0,0,0,0},
                        {0,0,0,0,0,0,2,2,0,0},
                        {0,0,0,0,0,0,0,0,0,0},
                        {0,0,0,0,2,2,0,0,0,0},
                        {0,0,0,0,0,0,0,0,0,0},
                        {0,0,2,2,0,0,0,0,0,0},
                        {0,1,0,0,0,0,0,0,0,0},
                        {0,2,0,0,0,0,0,0,0,0},
                        {1,0,0,0,0,0,0,0,0,0}};
    memcpy(d->plateau,tab,4*10*4*10);
    int expected = 4;
    int pos[2] = {0,9};
    liste_t *l = liste_init();
    int actual = rafle(pos,d,0,l,0);

    if(actual != expected){
        fprintf(stderr,"\ttest_rafle_blanc, rafle : expecting %i while got %i\n",expected,actual);
        return 0;
    }
    return 1;
}

int test_liste_creation_insertion(){
    /* teste la création et l'insertion d'une cellule dans une liste */
    liste_t *l = liste_init();
    liste_insere(l, new_cel(23,45));
    liste_insere(l, new_cel(56,56));
    liste_insere(l, new_cel(1, 10));
    //liste_print(l);
    return 1;
}

int test_liste_trouve(){
    /* teste la recherche d'un couple de coordonnées dans une liste chaînée (simple) */
    liste_t *l = liste_init();
    liste_insere(l, new_cel(23,45));
    liste_insere(l, new_cel(56,56));
    liste_insere(l, new_cel(1, 10));

    int expected = 0; // trouvé
    int actual = liste_trouve(l,1,10);
    
    if(actual != expected){
        fprintf(stderr,"\ttest_liste_trouve, liste_trouve : expecting %i while got %i\n",expected,actual);
        return 0;
    }
    return 1;
}

int test_liste_trouve2(){
    /* teste la recherche d'un couple de coordonnées dans le cas ou ce couple n'est pas dans la liste */
    liste_t *l = liste_init();
    liste_insere(l, new_cel(23,45));
    liste_insere(l, new_cel(56,56));
    liste_insere(l, new_cel(1, 10));
    
    int expected = -1;
    int actual = liste_trouve(l,1,9);

    if(actual != expected){
        fprintf(stderr,"\ttest_liste_trouve2, liste_trouve : expecting %i while got %i\n",expected,actual);
        return 0;
    }
    return 1;
}

int test_liste_trouve3(){
    /* teste la recherche d'un couple de coordonnées pas dans la liste */
    liste_t *l = liste_init();
    liste_insere(l, new_cel(23,45));
    liste_insere(l, new_cel(56,56));
    liste_insere(l, new_cel(1, 10));

    int expected = -1;
    int actual = liste_trouve(l,23,10);

    if(actual != expected){
        fprintf(stderr,"\ttest_liste_trouve3, liste_trouve : expecting %i while got %i\n",expected,actual);
        return 0;
    }
    return 1;
}

int test_liste_trouve4(){
    /* teste la recherche d'un couple de coordonnées pas dans la liste */
    liste_t *l = liste_init();
    liste_insere(l, new_cel(23,45));
    liste_insere(l, new_cel(56,56));
    liste_insere(l, new_cel(1, 10));

    int expected = -1;
    int actual = liste_trouve(l,18,7);

    if(actual != expected){
        fprintf(stderr,"\ttest_liste_trouve4, liste_trouve : expecting %i while got %i\n",expected,actual);
        return 0;
    }
    return 1;
}

int main_test_rafle(int argc, char **argv){
    /* compteurs */
    int runs = 0;
    int failures = 0;

    printf("TEST_RAFLE.C\n");

    /* lancement des tests */
    run_test(&test_rafle_blanc,&runs,&failures);
    run_test(&test_rafle_blanc2,&runs,&failures);
    run_test(&test_liste_creation_insertion,&runs,&failures);
    run_test(&test_liste_trouve,&runs,&failures);
    run_test(&test_liste_trouve2,&runs,&failures);
    run_test(&test_liste_trouve3,&runs,&failures);
    run_test(&test_liste_trouve4,&runs,&failures);


    /* affichage des résultats */
    printf("Nombre de tests lancés : %i\nNombre de tests passés : %i\n",runs,runs-failures);
    return EXIT_SUCCESS;
}
