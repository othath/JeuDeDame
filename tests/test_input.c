/*
 *
 * Pour compiler :
 *   se placer dans le dossier tests
 *      (cd ../src; gcc -c *.c; mv *.o ../tests);gcc -c test_input.c; gcc *.o -o test_input
 * Pour exécuter :
 *   ./test_input
 * 
 */

#include <stdlib.h>
#include <stdio.h>

#include "../src/input.h"

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

int test_input_valide(){
    /* teste un input valide : 'G1 F0' */
    char* inpt = "G1 F0";
    int expected = 0;
    int actual = checkInput(inpt);

    if(actual != expected){
        fprintf(stderr,"\ttest_input_valide, checkInput : expecting %i while got %i\n",expected,actual);
        return 0;
    }
    return 1;
}

int test_input_valide2(){
    /* teste un input valide : 'H8 D9    '*/
    char* inpt = "H8 D9     ";
    int expected = 0;
    int actual = checkInput(inpt);

    if(actual != expected){
        fprintf(stderr,"\ttest_input_valide2, checkInput : expecting %i while got %i\n",expected,actual);
        return 0;
    }
    return 1;
}

int test_input_invalide(){
    /* teste un input invalide : 'K8 D2' */
    char* inpt = "K8 D2";
    int expected = -1;
    int actual = checkInput(inpt);

    if(actual != expected){
        fprintf(stderr,"\ttest_input_invalide, checkInput : expecting %i while got %i\n",expected,actual);
        return 0;
    }
    return 1;
}

int test_input_invalide2(){
    /* teste un input invalide : 'D10 E5' */
    char* inpt = "D10 E5";
    int expected = -1;
    int actual = checkInput(inpt);

    if(actual != expected){
        fprintf(stderr,"\ttest_input_invalide2, checkInput : expecting %i while got %i\n",expected,actual);
        return 0;
    }
    return 1;
}

int test_input_invalide3(){
    /* teste un input invalide : 'a1 B2' */
    char* inpt = "a1 B2";
    int expected = -1;
    int actual = checkInput(inpt);

    if(actual != expected){
        fprintf(stderr,"\ttest_input_invalide3, checkInput : expecting %i while got %i\n",expected,actual);
        return 0;
    }
    return 1;
}

int main_test_input(int argc, char **argv){
    int runs = 0;
    int failures = 0;

    printf("TEST_INPUT.C\n");

    run_test(&test_input_valide,&runs,&failures);
    run_test(&test_input_valide2,&runs,&failures);
    run_test(&test_input_invalide,&runs,&failures);
    run_test(&test_input_invalide2,&runs,&failures);
    run_test(&test_input_invalide3,&runs,&failures);

    /* affichage des résultats */
    printf("Nombre de tests lancés : %i\nNombre de tests passés : %i\n",runs,runs-failures);

    return EXIT_SUCCESS;
}
