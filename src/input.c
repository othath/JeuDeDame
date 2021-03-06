/* bibliothèques */
#include "input.h"

int checkInput(const char input[]){
    /*
     * renvoie 0 si l'input est de la bonne forme,
     * -1 sinon.
     * forme attendue : A1 B2
     * A1 case de départ B2 case d'arrivée
     */
    if((int)input[0]>=(int)'A' && (int)input[0]<=(int)'J'){
        // 1er caractère valide (lettre)
        if((int)input[1]>=(int)'0' && (int)input[1]<=(int)'9'){
            // 2eme caractère valide (chiffre)
            if(input[2]==' '){
                // 3eme caractère valide (espace)
                if((int)input[3]>=(int)'A' && (int)input[3]<=(int)'J'){
                    // 4eme caractère valide (lettre)
                    if((int)input[1]>=(int)'0' && (int)input[1]<=(int)'9'){
                        // 5eme caractère valide (chiffre)
                        return 0;
                    }
                    else{
                        printf("                    ^Erreur, chiffre entre 0 et 9 attendu !\n");
                        return -1;
                    }
                }
                else{
                    printf("                   ^Erreur, lettre entre A et J attendue !\n");
                    return -1;
                }
            }
            else{
                printf("                 ^Erreur, espace attendu !\n");
                return -1;
            }
        }
        else{
            printf("                ^Erreur, chiffre entre 0 et 9 attendu !\n");
            return -1;
        }
    }
    else{
        printf("               ^Erreur, lettre entre A et J attendue !\n");
        return -1;
    }
    return -1;
}

int *envoyerInput(const char input[]){
    /*
     * renvoie un tableau d'entiers correspondant au coordonnées
     * de la case initiale et de la case finale
     * RETURN : [ligne de départ, colonne de départ, ligne d'arrivée, colonne d'arrivée]
     */
    int* inp = (int*)malloc(4*sizeof(int));
    *(inp+1) = (int)input[0]%13; // ASCII -> chiffre entre 0 et 9
    *(inp) = (int)input[1]-(int)'0';
    // *(input+2) = espace
    *(inp+3) = (int)input[3]%13;
    *(inp+2) = (int)input[4]-(int)'0';
    return inp;
}

void decode_normal(char input[], int* code){
    code[0]=(int)input[1]-(int)'0';
    code[1]=(int)input[0]-(int)'0';
    code[2]=(int)input[3]-(int)'0';
    code[3]=(int)input[2]-(int)'0';
}

void decode_rafle(char input[], int rafle[][4]){
    int longeur=(strlen(input)-2)/2; //nombre de prises dans la rafle
    for (int i=0; i<longeur; i++){
        rafle[i][0]=(int)input[2*i+1]-(int)'0';
        rafle[i][1]=(int)input[2*i]-(int)'0';
        rafle[i][2]=(int)input[2*i+3]-(int)'0';
        rafle[i][3]=(int)input[2*i+2]-(int)'0';
    }
}

void encode_normal(int code[4], char* message){
    message[0]=(char)(code[1]+(int)'0');
    message[1]=(char)(code[0]+(int)'0');
    message[2]=(char)(code[3]+(int)'0');
    message[3]=(char)(code[2]+(int)'0');
    message[4]='\0';
}
