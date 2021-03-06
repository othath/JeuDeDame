/**
* \file input.h
* \brief Traitement de l'entrée et sortie utilisateur
* \author maxime.kuhn1@uha.fr, matheo.marcourt@uha.fr
* \version 1
*/


#ifndef INPUT_H_
#define INPUT_H_

#include <stdlib.h>
#include <stdio.h>
#include <string.h>

/* entêtes */
int checkInput(const char input[]);
int *envoyerInput(const char input[]);

/**
* \fn decode_normal(char input[], int* code)
* \brief Décode un mouvement normal reçu du réseau en code de mouvement
* \param input, chaîne de caractère codée
* \param code, tableau de 4 entiers qui va recevoir le code
* \return rien, mais change le contenu de code
*/
void decode_normal(char input[], int* code);

/**
* \fn decode_rafle(char input[], int** rafle)
* \brief Décode une rafle reçu du réseau en ensemble de codes de mouvement
* \param input, chaîne de caractère codée
* \param rafle, matrice de n*4 entiers qui va recevoir les codes de mouvement avec n le nombre de prises de la rafle
* \return rien, mais change le contenu de rafle
*/
void decode_rafle(char input[], int rafle[][4]);

/**
* \fn encode_normal(int code[4], char* message)
* \brief Encode un code de mouvement pour l'envoyer sur le réseau
* \param code, tableau de 4 entiers décrivant le mouvement à encoder
* \param message, chaîne de caractère qui va recevoir le message
* \return rien, mais change le contenu de message
*/
void encode_normal(int code[4], char* message);
#endif
