/*
 *
 * Pour compiler :
 *   se placer dans le dossier tests
 *      (cd ../src; gcc -c *.c; mv *.o ../tests);gcc -c test_deplacement.c; gcc *.o -o test_deplacement
 * Pour exécuter :
 *   ./test_deplacement
 * 
 */

#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#include "../src/deplacement.h"
#include "../src/grille.h"

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

int test_deplacement_case_vide_blanc(){
    /* test si on peut déplacer une case vide, dans le cas ou c'est aux blancs de jouer */

    // on crée les données pour le test
    PDamier d = new_damier();
    init_damier(d);
    int deplacement[] = {0,0,1,1};
    int expected = -1;
    int actual = mv_normal(deplacement, d, 0);

    // on fait le test
    if(actual != expected){
        fprintf(stderr,"\ttest_deplacement_case_vide_blanc, mv_normal : expecting %i while got %i\n",expected,actual);
        return 0; // problème
    }
    return 1; // tout va bien
}

int test_deplacement_case_vide_noir(){
    /* test si on peut déplacer une case vide, dans le cas ou c'est aux noirs de jouer */

    // on crée les données pour le test
    PDamier d = new_damier();
    init_damier(d);
    int deplacement[] = {0,0,1,1};
    int expected = -1;
    int actual = mv_normal(deplacement, d, 0);

    if(actual != expected){
        fprintf(stderr,"\ttest_deplacement_case_vide_noir, mv_normal : expecting %i while got %i\n",expected,actual);
        return 0; // problème
    }
    return 1; // tout va bien
}

int test_transformation_dame_blanc(){
    /* test si on crée le bon nombre de dames, dans le cas ou c'est aux blancs de jouer */

    // on crée les données pour le test
    PDamier d = new_damier();
    init_damier(d);
    d->plateau[0][1] = PION_BLANC;
    d->plateau[0][3] = PION_BLANC;
    d->plateau[1][1] = PION_BLANC;
    d->plateau[0][5] = PION_NOIR;
    int expected = 2;
    dame(d);
    int actual = d->nb_dblanc;
    
    if(actual != expected){
        fprintf(stderr,"\ttest_transformation_dame_blanc, dame : expecting %i while got %i\n",expected,actual);
        return 0;
    }
    return 1;
}

int test_transformation_dame_noir(){
    /* test si on crée le bon nombre de dames, dans le cas ou c'est aux noirs de jouer */

    // on crée les données pour le test
    PDamier d = new_damier();
    init_damier(d);
    d->plateau[9][1] = PION_NOIR;
    d->plateau[9][3] = PION_NOIR;
    d->plateau[9][2] = PION_BLANC;
    d->plateau[9][5] = PION_BLANC;
    int expected = 2;
    dame(d);
    int actual = d->nb_dnoir;
    
    if(actual != expected){
        fprintf(stderr,"\ttest_transformation_dame_noir, dame : expecting %i while got %i\n",expected,actual);
        return 0;
    }
    return 1;
}

int test_prise_obligatoire_blanc_nouveau_damier(){
    /* 
     * test le nombre de prises obligatoires (possibles) pour le joueur blanc,
     * dans le cas ou on a un damier tout neuf (les pions sont positionnés comme pour un
     * début de partie).
     * 
     * RAPPEL : tour des blancs = 0
     */

    // on crée les données du problème
    PDamier d = new_damier();
    init_damier(d);
    int expected = 0;
    int actual = priseObligatoire(d,0);

    if(actual != expected){
        fprintf(stderr,"\ttest_prise_obligatoire_blanc_nouveau_damier, priseObligatoire : expecting %i while got %i\n",expected,actual);
        return 0;
    }
    return 1;
}

int test_prise_obligatoire_noir_nouveau_damier(){
    /* pareil que pour la fonction précédente, mais pour le joueur noir. (tour des noirs = 1) */

    // on crée les données du problème
    PDamier d = new_damier();
    init_damier(d);
    int expected = 0;
    int actual = priseObligatoire(d,1);

    if(actual != expected){
        fprintf(stderr,"\ttest_prise_obligatoire_noir_nouveau_damier, priseObligatoire : expecting %i while got %i\n",expected,actual);
        return 0;
    }
    return 1;
}

int test_prise_obligatoire_blanc_situation1(){
    /* test le nombre de prises obligatoire (possibles) pour le jouer blanc dans une situation particulière */

    // on crée les données du problème
    PDamier d = new_damier();
    int tab[10][10] =  {{0,2,0,2,0,2,0,2,0,2},  //tableau de valeur de référence
                        {2,0,2,0,2,0,2,0,2,0},
                        {0,2,0,2,0,2,0,2,0,2},
                        {2,0,0,0,2,0,0,0,2,0},
                        {0,0,0,2,0,2,0,0,0,0},
                        {0,0,0,0,1,0,0,0,0,0},
                        {0,0,0,1,0,1,0,0,0,1},
                        {1,0,1,0,1,0,1,0,1,0},
                        {0,1,0,1,0,1,0,1,0,1},
                        {1,0,1,0,0,0,0,0,0,0}};
    memcpy(d->plateau,tab,4*10*4*10);
    int expected = 2;
    int actual = priseObligatoire(d,0);

    if(actual != expected){
        fprintf(stderr,"\ttest_prise_obligatoire_blanc_situation1, priseObligatoire : expecting %i while got %i\n",expected,actual);
        return 0;
    }
    return 1;
}

int test_prise_obligatoire_blanc_situation2(){
    /* test le nombre de prises obligatoire (possibles) pour le jouer blanc dans une situation particulière */

    // on crée les données du problème
    PDamier d = new_damier();
    int tab[10][10] =  {{0,2,0,2,0,2,0,2,0,2},  //tableau de valeur de référence
                        {2,0,2,0,2,0,2,0,2,0},
                        {0,2,0,2,0,2,0,2,0,2},
                        {2,0,0,0,2,0,0,0,2,0},
                        {0,0,0,2,0,2,0,0,0,0},
                        {0,0,0,0,1,0,0,0,0,0},
                        {0,0,0,2,0,0,0,0,0,1},
                        {1,0,0,0,0,0,0,0,1,0},
                        {0,1,0,1,0,1,0,1,0,1},
                        {1,0,1,0,0,0,0,0,0,0}};
    memcpy(d->plateau,tab,4*10*4*10);
    int expected = 3;
    int actual = priseObligatoire(d,0);

    if(actual != expected){
        fprintf(stderr,"\ttest_prise_obligatoire_blanc_situation2, priseObligatoire : expecting %i while got %i\n",expected,actual);
        return 0;
    }
    return 1;
}

int test_prise_obligatoire_blanc_situation3(){
    /* test le nombre de prises obligatoire (possibles) pour le jouer blanc dans une situation particulière */

    // on crée les données du problème
    PDamier d = new_damier();
    int tab[10][10] =  {{0,2,0,2,0,2,0,2,0,2},  //tableau de valeur de référence
                        {2,0,2,0,2,0,2,0,2,0},
                        {0,2,0,2,0,2,0,2,0,2},
                        {2,0,0,0,2,0,0,0,2,0},
                        {0,0,0,0,0,0,0,0,0,0},
                        {0,0,0,0,1,0,0,0,0,0},
                        {0,0,0,2,0,2,0,0,0,1},
                        {1,0,0,0,0,0,0,0,1,0},
                        {0,1,0,1,0,1,0,1,0,1},
                        {1,0,1,0,0,0,0,0,0,0}};
    memcpy(d->plateau,tab,4*10*4*10);
    int expected = 2;
    int actual = priseObligatoire(d,0);

    if(actual != expected){
        fprintf(stderr,"\ttest_prise_obligatoire_blanc_situation3, priseObligatoire : expecting %i while got %i\n",expected,actual);
        return 0;
    }
    return 1;
}

int test_prise_obligatoire_blanc_situation4(){
    /* test le nombre de prises obligatoire (possibles) pour le jouer blanc dans une situation particulière */

    // on crée les données du problème
    PDamier d = new_damier();
    int tab[10][10] =  {{0,2,0,2,0,2,0,2,0,2},  //tableau de valeur de référence
                        {2,0,2,0,2,0,2,0,2,0},
                        {0,2,0,2,0,2,0,2,0,2},
                        {2,0,0,0,2,0,0,0,2,0},
                        {0,0,0,2,0,2,0,0,0,0},
                        {0,0,0,0,1,0,0,0,0,0},
                        {0,0,0,2,0,2,0,0,0,1},
                        {1,0,0,0,0,0,0,0,1,0},
                        {0,1,0,1,0,1,0,1,0,1},
                        {1,0,1,0,0,0,0,0,0,0}};
    memcpy(d->plateau,tab,4*10*4*10);
    int expected = 4;
    int actual = priseObligatoire(d,0);

    if(actual != expected){
        fprintf(stderr,"\ttest_prise_obligatoire_blanc_situation4, priseObligatoire : expecting %i while got %i\n",expected,actual);
        return 0;
    }
    return 1;
}

int test_prise_obligatoire_noir_situation1(){
    /* test le nombre de prises obligatoire (possibles) pour le jouer noir dans une situation particulière */

    // on crée les données du problème
    PDamier d = new_damier();
    int tab[10][10] =  {{0,2,0,2,0,2,0,2,0,2},  //tableau de valeur de référence
                        {2,0,2,0,2,0,2,0,2,0},
                        {0,2,0,2,0,2,0,2,0,2},
                        {2,0,0,0,2,0,0,0,2,0},
                        {0,1,0,1,0,1,0,0,0,0},
                        {0,0,0,0,0,0,1,0,0,0},
                        {0,0,0,0,0,0,0,0,0,1},
                        {1,0,0,0,0,0,0,0,1,0},
                        {0,1,0,1,0,1,0,1,0,1},
                        {1,0,1,0,0,0,0,0,0,0}};
    memcpy(d->plateau,tab,4*10*4*10);
    int expected = 2;
    int actual = priseObligatoire(d,1);

    if(actual != expected){
        fprintf(stderr,"\ttest_prise_obligatoire_noir_situation1, priseObligatoire : expecting %i while got %i\n",expected,actual);
        return 0;
    }
    return 1;
}

int test_prise_obligatoire_avec_dames_noires_situation1(){
    /* test le nombre de prises obligatoires (possibles) pour le joueur noir dans une situation particulière */

    // on crée les données du problème
    PDamier d = new_damier();
    int tab[10][10] =  {{0,2,0,2,0,2,0,2,0,2},  //tableau de valeur de référence
                        {2,0,2,0,2,0,2,0,2,0},
                        {0,2,0,2,0,2,0,2,0,2},
                        {2,0,0,0,20,0,0,0,2,0},
                        {0,1,0,1,0,0,0,0,0,0},
                        {0,0,0,0,0,0,1,0,0,0},
                        {0,0,0,0,0,0,0,0,0,1},
                        {1,0,0,0,0,0,0,0,1,0},
                        {0,1,0,1,0,1,0,1,0,1},
                        {1,0,1,0,0,0,0,0,0,0}};
    memcpy(d->plateau,tab,4*10*4*10);
    int expected = 3;
    int actual = priseObligatoire(d,1);

    if(actual != expected){
        fprintf(stderr,"\ttest_prise_obligatoire_avec_dames_noires_situation2, priseObligatoire : expecting %i while got %i\n",expected,actual);
        return 0;
    }
    return 1;
}

int test_prise_obligatoire_avec_dames_noires_situation2(){
    /* test le nombre de prises obligatoires (possibles) pour le joueur noir dans une situation particulière */

    // on crée les données du problème
    PDamier d = new_damier();
    int tab[10][10] =  {{0,2,0,2,0,2,0,2,0,2},  //tableau de valeur de référence
                        {2,0,2,0,2,0,2,0,2,0},
                        {0,2,0,2,0,2,0,2,0,2},
                        {2,0,0,0,20,0,0,0,2,0},
                        {0,0,0,1,0,0,0,0,0,0},
                        {1,0,1,0,0,0,1,0,0,0},
                        {0,20,0,0,0,0,0,1,0,1},
                        {1,0,1,0,0,0,0,0,1,0},
                        {0,1,0,0,0,1,0,1,0,1},
                        {1,0,1,0,0,0,0,0,0,0}};
    memcpy(d->plateau,tab,4*10*4*10);
    int expected = 1;
    int actual = priseObligatoire(d,1);

    if(actual != expected){
        fprintf(stderr,"\ttest_prise_obligatoire_avec_dames_noires_situation2, priseObligatoire : expecting %i while got %i\n",expected,actual);
        return 0;
    }
    return 1;
}

int test_prise_dame_blanc(){
    /* test si une prise (faite par une) dame se passe bien */

    // on crée les données du problème
    PDamier d = new_damier();
    int tab[10][10] =  {{0,20,0,2,0,2,0,2,0,2},  //tableau de valeur de référence
                        {2,0,0,0,2,0,2,0,2,0},
                        {0,2,0,1,0,2,0,2,0,2},
                        {2,0,0,0,0,0,0,0,2,0},
                        {0,0,0,1,0,0,0,0,0,0},
                        {0,0,1,0,0,0,1,0,0,0},
                        {0,20,0,0,0,0,0,1,0,1},
                        {1,0,10,0,0,0,0,0,1,0},
                        {0,1,0,0,0,1,0,1,0,1},
                        {1,0,1,0,0,0,0,0,0,0}};
    memcpy(d->plateau,tab,4*10*4*10);
    int deplacement[] = {2,7,0,5};
    int expected = 0;
    int actual = prise_dame(d,0,deplacement);

    if(actual != expected){
        fprintf(stderr,"\ttest_prise_dame_noir, prise_dame : expecting %i while got %i\n",expected,actual);
        return 0;
    }
    return 1;
}

int test_prise_dame_noir(){
    /* test si une prise (faite par une) dame se passe bien */

    // on crée les données du problème
    PDamier d = new_damier();
    int tab[10][10] =  {{0,20,0,2,0,2,0,2,0,2},  //tableau de valeur de référence
                        {2,0,0,0,2,0,2,0,2,0},
                        {0,2,0,1,0,2,0,2,0,2},
                        {2,0,0,0,0,0,0,0,2,0},
                        {0,0,0,1,0,0,0,0,0,0},
                        {1,0,1,0,0,0,1,0,0,0},
                        {0,20,0,0,0,0,0,1,0,1},
                        {1,0,1,0,0,0,0,0,1,0},
                        {0,1,0,0,0,1,0,1,0,1},
                        {1,0,1,0,0,0,0,0,0,0}};
    memcpy(d->plateau,tab,4*10*4*10);
    int deplacement[] = {1,0,4,3};
    int expected = 0;
    int actual = prise_dame(d,1,deplacement);

    if(actual != expected){
        fprintf(stderr,"\ttest_prise_dame_noir, prise_dame : expecting %i while got %i\n",expected,actual);
        return 0;
    }
    return 1;
}

int test_deplacement_dame_blanc_tour_blanc(){
    /* test le déplacement d'une dame blanche dans le cas ou c'est le tour des blancs */

    // on crée les données du problème
    PDamier d = new_damier();
    int tab[10][10] =  {{0,20,0,2,0,2,0,2,0,2},  //tableau de valeur de référence
                        {2,0,0,0,2,0,2,0,2,0},
                        {0,2,0,1,0,2,0,2,0,2},
                        {2,0,0,0,0,0,0,0,2,0},
                        {0,0,0,0,0,0,0,0,0,0},
                        {1,0,0,0,0,0,1,0,0,0},
                        {0,10,0,0,0,0,0,1,0,1},
                        {1,0,1,0,0,0,0,0,1,0},
                        {0,1,0,0,0,1,0,1,0,1},
                        {1,0,1,0,0,0,0,0,0,0}};
    memcpy(d->plateau,tab,4*10*4*10);
    int deplacement[] = {1,6,4,3};
    int expected = 0;
    int actual = depDame(deplacement,d,0);

    if(actual != expected){
        fprintf(stderr,"\ttest_deplacement_dame_blanc_tour_blanc, depDame : expecting %i while got %i\n",expected,actual);
        return 0;
    }
    return 1;
}

int test_deplacement_dame_blanc_tour_noir(){
    /* test le déplacement d'une dame blanche dans le cas ou c'est le tour des noirs */

    // on crée les données du problème
    PDamier d = new_damier();
    int tab[10][10] =  {{0,20,0,2,0,2,0,2,0,2},  //tableau de valeur de référence
                        {2,0,0,0,2,0,2,0,2,0},
                        {0,2,0,1,0,2,0,2,0,2},
                        {2,0,0,0,0,0,0,0,2,0},
                        {0,0,0,0,0,0,0,0,0,0},
                        {1,0,0,0,0,0,1,0,0,0},
                        {0,10,0,0,0,0,0,1,0,1},
                        {1,0,1,0,0,0,0,0,1,0},
                        {0,1,0,0,0,1,0,1,0,1},
                        {1,0,1,0,0,0,0,0,0,0}};
    memcpy(d->plateau,tab,4*10*4*10);
    int deplacement[] = {1,6,4,3};
    int expected = -1;
    int actual = depDame(deplacement,d,1);

    if(actual != expected){
        fprintf(stderr,"\ttest_deplacement_dame_blanc_tour_noir, depDame : expecting %i while got %i\n",expected,actual);
        return 0;
    }
    return 1;
}

int test_nombre_prises_pion_blanc_tour_blanc(){
    /* teste la fonction nombrePrisesPourUnPion */

    // on crée les données du problème
    PDamier d = new_damier();
    int tab[10][10] =  {{0,20,0,2,0,2,0,2,0,2},  //tableau de valeur de référence
                        {2,0,0,0,2,0,2,0,2,0},
                        {0,2,0,1,0,2,0,2,0,2},
                        {2,0,0,0,0,0,0,0,2,0},
                        {0,0,0,0,0,2,0,2,0,0},
                        {1,0,0,0,0,0,1,0,0,0},
                        {0,1,0,0,0,2,0,2,0,1},
                        {1,0,1,0,0,0,0,0,0,0},
                        {0,1,0,0,0,1,0,1,0,1},
                        {1,0,1,0,0,0,0,0,0,0}};
    memcpy(d->plateau,tab,4*10*4*10);
    int i = 5;
    int j = 6;
    int expected = 3;
    int actual = nombrePrisesPourUnPion(d,0,i,j);

    if(actual != expected){
        fprintf(stderr,"\ttest_nombre_prises_pion_blanc_tour_blanc, nombrePrisesPourUnPion : expecting %i while got %i\n",expected,actual);
        return 0;
    }
    return 1;
}

int test_nombre_prises_pion_noir_tour_noir(){
    /* teste le nombre de prises pour un pion noir */

    // on crée les données du problème
    PDamier d = new_damier();
    int tab[10][10] =  {{0,20,0,2,0,2,0,2,0,2},  //tableau de valeur de référence
                        {2,0,0,0,2,0,2,0,2,0},
                        {0,2,0,1,0,2,0,2,0,2},
                        {2,0,0,1,0,0,0,0,2,0},
                        {0,0,2,0,0,2,0,2,0,0},
                        {1,1,0,0,0,0,1,0,0,0},
                        {0,1,0,0,0,2,0,2,0,1},
                        {1,0,1,0,0,0,0,0,0,0},
                        {0,1,0,0,0,1,0,1,0,1},
                        {1,0,1,0,0,0,0,0,0,0}};
    memcpy(d->plateau,tab,4*10*4*10);
    int expected = 2;
    int i = 4;
    int j = 2;
    int actual = nombrePrisesPourUnPion(d,1,i,j);

    if(actual != expected){
        fprintf(stderr,"\ttest_nombre_prises_pion_noir_tour_noir, nombrePrisesPourUnPion : expecting %i while got %i\n",expected,actual);
        return 0;
    }
    return 1;
}

int main_test_deplacement(int argc, char **argv){
    /* compteurs */
    int test_count = 0;
    int failures = 0;

    printf("TEST_DEPLACEMENT.C\n");

    /* lancement des tests */
    run_test(&test_deplacement_case_vide_blanc,&test_count,&failures);
    run_test(&test_deplacement_case_vide_noir,&test_count,&failures);
    run_test(&test_transformation_dame_blanc,&test_count,&failures);
    run_test(&test_transformation_dame_noir,&test_count,&failures);
    run_test(&test_prise_obligatoire_blanc_nouveau_damier,&test_count,&failures);
    run_test(&test_prise_obligatoire_noir_nouveau_damier,&test_count,&failures);
    run_test(&test_prise_obligatoire_blanc_situation1,&test_count,&failures);
    run_test(&test_prise_obligatoire_blanc_situation2,&test_count,&failures);
    run_test(&test_prise_obligatoire_blanc_situation3,&test_count,&failures);
    run_test(&test_prise_obligatoire_blanc_situation4,&test_count,&failures);
    run_test(&test_prise_obligatoire_noir_situation1,&test_count,&failures);
    run_test(&test_prise_obligatoire_avec_dames_noires_situation1,&test_count,&failures);
    run_test(&test_prise_obligatoire_avec_dames_noires_situation2,&test_count,&failures);
    run_test(&test_prise_dame_blanc,&test_count,&failures);
    run_test(&test_prise_dame_noir,&test_count,&failures);
    run_test(&test_deplacement_dame_blanc_tour_blanc,&test_count,&failures);
    run_test(&test_deplacement_dame_blanc_tour_noir,&test_count,&failures);
    run_test(&test_nombre_prises_pion_blanc_tour_blanc,&test_count,&failures);
    run_test(&test_nombre_prises_pion_noir_tour_noir,&test_count,&failures);
    
    /* affichage des résultats */
    printf("Nombre de tests lancés : %i\nNombre de tests passés : %i\n",test_count,test_count-failures);
    return EXIT_SUCCESS;
}
