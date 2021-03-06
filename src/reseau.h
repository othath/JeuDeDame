/**
* \file reseau.h
* \brief bibliothèque de gestion de communication TCP/UDP
* \author matheo.marcout@uha.fr
* \version 1
*/

#ifndef RESEAU_H_
#define RESEAU_H_

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netdb.h>
#include <netinet/in.h>
#include <arpa/inet.h>

#define SOCKET int
#define INVALID_SOCKET -1
#define SOCKET_ERROR -1

/**
* \fn udp_connecter_client(char* ip, short port)
* \brief Connexion à un serveur UDP
* \param ip, chaîne de charactères contenant l'adresse IP sous la forme X.X.X.X
* \param port, entier court donant port de connexion
* \return le SOCKET (un entier) de communication, ou -1 en cas d'erreur
*/
SOCKET udp_connecter_client(char* ip, short port);

/**
* \fn udp_ecrire_client(SOCKET s, char* donnes)
* \brief envoie des données textuelles en UDP, côté client
* \param SOCKET (entier) s, le socket de communication
* \param donnes, chaîne de caractères à envoyer
* \return le nombre d'octets envoyés, ou -1 en cas d'erreur
*/
int udp_ecrire_client(SOCKET s, char* donnes);

/**
* \fn udp_lire_client(SOCKET s, char* sortie)
* \brief reçoit des données textuelles en UDP et les stoques, côté client
* \param SOCKET (entier) s, le socket de communication
* \param sortie, chaîne de caractères qui va reçevoir les données
* \return le nombre d'octets reçus, ou -1 en cas d'erreur
*/
int udp_lire_client(SOCKET s, char* sortie);

/**
* \fn udp_creer_serveur(short port)
* \brief créé un serveur UDP
* \param port, entier court donant le port de connexion
* \return le SOCKET (entier) de communication, ou -1 en cas d'erreur
*/
SOCKET udp_creer_serveur(short port);

/**
* \fn udp_lire_serveur(SOCKET s,  struct sockaddr_in* source, char* sortie)
* \brief reçoit des données textuelles en UDP et les stoques, côté serveur
* \param SOCKET (entier) s, le socket de communication
* \param source, pointeur vers la structure d'adresse source
* \param sortie, chaîne de caractères qui va reçevoir les données
* \return le nombre d'octets reçus, ou -1 en cas d'erreur
*/
int udp_lire_serveur(SOCKET s, struct sockaddr_in* source, char* sortie);

/**
* \fn udp_ecrire_serveur(SOCKET s, struct sockaddr_in* source, char* entree)
* \brief envoie des données textuelles en UDP, côté serveur
* \param SOCKET (entier) s, le socket de communication
* \param source, pointeur vers la structure d'adresse source
* \param entree, chaîne de caractères à envoyer
* \return le nombre d'octets envoyés, ou -1 en cas d'erreur
*/
int udp_ecrire_serveur(SOCKET s, struct sockaddr_in* source, char* entree);

/**
* \fn tcp_connecter_client(char* ip, short port)
* \brief Connexion à un serveur TCP
* \param ip, chaîne de charactères contenant l'adresse IP sous la forme X.X.X.X
* \param port, entier court donant port de connexion
* \return le SOCKET (un entier) de communication, ou -1 en cas d'erreur
*/
SOCKET tcp_connecter_client(char* ip, short port);

/**
* \fn tcp_ecrire(SOCKET s, char* contenu)
* \brief envoie des données textuelles en TCP
* \param s, le SOCKET (entier) de communication
* \param contenu, chaîne de caractères à envoyer
* \return le nombre d'octets envoyés, ou -1 en cas d'erreur
*/
int tcp_ecrire(SOCKET s, char* contenu);

/**
* \fn tcp_creer_serveur(short port)
* \brief créé un serveur TCP
* \param port, entier court donant le port de connexion
* \return le SOCKET (entier) de communication, ou -1 en cas d'erreur
*/
SOCKET tcp_creer_serveur(short port);

/**
* \fn tcp_lire_client(SOCKET s, char* sortie, unsigned int longeur_attendue)
* \brief reçoit des données textuelles en TCP et les stoques
* \param s, le SOCKET (entier) de communication
* \param sortie, chaîne de caractères qui va reçevoir les données
* \param longeur_attendue, entier positif donant le nombre d'octets attendus
* \return le nombre d'octets reçus, ou -1 en cas d'erreur
*/
int tcp_lire(SOCKET s, char* contenu, unsigned int longeur_attendue);

/**
* \fn tcp_lire_court(SOCKET s)
* \brief lit un entier court
* \param s, le SOCKET (entier) de communication
* \return un entier court
*/
short tcp_lire_court(SOCKET s);

/**
* \fn tcp_envoyer_court(SOCKET s, short donnes)
* \brief envoye un entier court
* \param s, le SOCKET (entier) de communication
* \param donnes, l'entier court à envoyer
* \return le nombre d'octets envoyés (2 noralement) ou -1 en cas d'erreur
*/
int tcp_envoyer_court(SOCKET s, short donnes);
#endif
