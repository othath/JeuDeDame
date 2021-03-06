#include "jeu.h"
#include "reseau.h"
#include "alea.h"
#include <string.h>
#include <stdlib.h>

/*
 * Options de lancement du programme :
 *      --pvp   => JOUEUR CONTRE JOUEUR
 *
 * Si option invalide,
 * erreur + fin du programme
 */


void afficheOptions(){
    /* affiche toutes les options de lancement du programme */
    printf("Liste des options : \n");
    printf("\t--pvp : joueur contre joueur\n");
    printf("\t--port port : créer un serveur");
    printf("\t --connect ip:port : se connecter au serveur\n");

}

int mai(int argc, char* argv[]){

    if(argc < 2){ // vérifie qu'on a bien une option

        fprintf(stderr, "Il  faut une option pour lancer le programme !\n./dames --help pour voir les options\n");
        return EXIT_FAILURE;

    }


    if(strcmp("--help", argv[1]) == 0){ // affichage des options
        afficheOptions();
        return EXIT_SUCCESS;
    }

    if(strcmp("--pvp", argv[1]) == 0){ // vérifie si l'option est bonne

        /* création + initialisation du damier */
        PDamier d=new_damier();
        init_damier(d);
        /* lancement du jeu */

        //update_damier(d);
        jeu(d);

    }
    else if(strcmp("--port", argv[1]) == 0){
        SOCKET maitre=tcp_creer_serveur(atoi(argv[2]));
        if (maitre==INVALID_SOCKET) exit(1);
        printf("Serveur créé!\n En attente d'une connexion... ");
        SOCKET esclave=accept(maitre,NULL,0);
        printf("connecté!\n");
        PDamier d=new_damier();
        init_damier(d);
        float rand=frand();
        printf("le résultat du toss est %f\n",rand);
        if (rand<=0.5){
            printf("Le serveur joura les blancs, et le client les noirs!\n");
            tcp_envoyer_court(esclave,(short)2);
            jeu_blanc(d, esclave);
        }
        else{
            printf("Le serveur joura les noirs, et le client les blancs!\n");
            tcp_envoyer_court(esclave,(short)1);
            jeu_noir(d, esclave);
        }
        shutdown(esclave, 2);
        shutdown(maitre,2);
    }
    else if(strcmp("--connect", argv[1]) == 0){
        char* ip = strtok(argv[2],":");
        int port = atoi(strtok(NULL,":"));
        printf("connection à l'IP %s sur le port %i ... ",ip,port);
        SOCKET chaussette=tcp_connecter_client(ip,port);
        if (chaussette==INVALID_SOCKET) exit(1);
        PDamier d=new_damier();
        init_damier(d);
        printf("connecté!\n En attente de la décision du serveur...\n");
        if (tcp_lire_court(chaussette)==1){
            printf("Je vais donc jouer les blancs!\n");
            jeu_blanc(d, chaussette);
        }
        else {
            printf("Je vais donc jouer les noirs!\n");
            jeu_noir(d, chaussette);
        }
        shutdown(chaussette,2);
    }
    else{

        fprintf(stderr,"Option invalide : %s !\n./dames --help pour voir les options\n", argv[1]);
        return EXIT_FAILURE;

    }

    return EXIT_SUCCESS;
}
