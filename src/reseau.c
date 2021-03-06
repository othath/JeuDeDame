#include "reseau.h"

SOCKET udp_connecter_client(char* ip, short port){
    struct protoent* ppe = getprotobyname("udp");
    if (ppe == NULL) exit(1);
    SOCKET s = socket(AF_INET, SOCK_DGRAM, ppe->p_proto);
    if (s==INVALID_SOCKET) exit(1);
    struct sockaddr_in sin;
    memset(&sin, 0, sizeof(sin));
    sin.sin_family=AF_INET;
    sin.sin_addr.s_addr=inet_addr(ip);
    sin.sin_port=htons(port);
    if (connect(s, (struct sockaddr*) &sin, sizeof(sin))==SOCKET_ERROR) exit(1);
    return s;
}

int udp_ecrire_client(SOCKET s, char* donnes){ //envoie le contenu de donnes au serveur associé au socket s. retourne la quantitée d'octets envoyés
    int longeur = strlen(donnes);
    int quantite_envoyee = send(s, donnes, longeur, 0);
    if (quantite_envoyee == SOCKET_ERROR) exit(1);
    return quantite_envoyee;
}

int udp_lire_client(SOCKET s, char* sortie){ //attends que le serveur associé au socket s envoye un message, le stoque dans sortie et renvoie le nombre d'octets reçus
    char reserve[1500];
    int quantite_recue = recv(s, reserve, sizeof(reserve),0);
    if (quantite_recue == SOCKET_ERROR) exit(1);
    strncpy(sortie, reserve, quantite_recue);
    return quantite_recue;
}

SOCKET udp_creer_serveur(short port){ //créé un serveur UDP au port port
    struct protoent* ppe = getprotobyname("udp");
    if (ppe == NULL) exit(1);
    SOCKET s = socket(AF_INET, SOCK_DGRAM, ppe->p_proto);
    if (s==INVALID_SOCKET) exit(1);
    struct sockaddr_in sin;
    memset(&sin, 0, sizeof(sin));
    sin.sin_family=AF_INET;
    sin.sin_addr.s_addr=INADDR_ANY;
    sin.sin_port=htons(port);
    if (bind(s, (struct sockaddr*) &sin, sizeof(sin))==SOCKET_ERROR) exit(1);
    return s;
}

int udp_lire_serveur(SOCKET s, struct sockaddr_in* source, char* sortie){ //attend que le client envoie qqch, le réceptione dans sortie et renvoie le nombre d'octets reçus
    char reserve[1500];
    unsigned int longeur = sizeof(*source);
    int recus=recvfrom(s,reserve,sizeof(reserve),0,(struct sockaddr*)source,&longeur);
    if (recus==SOCKET_ERROR) exit(1);
    strncpy(sortie, reserve, recus);
    sortie[recus]='\0';
    return recus;
}

int udp_ecrire_serveur(SOCKET s, struct sockaddr_in* source, char* entree){ //envoye au client entree, retourne le nombre d'octets envoyés
    int envoyes=sendto(s, entree, sizeof(entree),0,(struct sockaddr*)source, sizeof(*source));
    if (envoyes==SOCKET_ERROR) exit(1);
    return envoyes;
}

SOCKET tcp_connecter_client(char* ip, short port){ //Connexion à un serveur tcp à l'adresse ip sur lo port port, renvoie le socket de communication
    struct protoent* ppe = getprotobyname("tcp");
    if (ppe == NULL) exit(1);
    SOCKET s = socket(AF_INET, SOCK_STREAM, ppe->p_proto);
    if (s==INVALID_SOCKET) exit(1);
    struct sockaddr_in sin;
    memset(&sin, 0, sizeof(sin));
    sin.sin_family=AF_INET;
    sin.sin_addr.s_addr=inet_addr(ip);
    sin.sin_port=htons(port);
    if (connect(s, (struct sockaddr*) &sin, sizeof(sin))==SOCKET_ERROR) exit(1);
    return s;
}

int tcp_ecrire(SOCKET s, char* contenu){//Envoye au serveur TCP le contenu de contenu et retourne le nombre d'octets envoyés
    int envoyes=send(s,contenu,strlen(contenu),0);
    if (envoyes==SOCKET_ERROR) exit(1);
    return envoyes;
}

SOCKET tcp_creer_serveur(short port){//Créé un serveur TCP sur le port port
    struct protoent* ppe = getprotobyname("tcp");
    if (ppe == NULL) exit(1);
    SOCKET s = socket(AF_INET, SOCK_STREAM, ppe->p_proto);
    if (s==INVALID_SOCKET) exit(1);
    struct sockaddr_in sin;
    memset(&sin, 0, sizeof(sin));
    sin.sin_family=AF_INET;
    sin.sin_addr.s_addr=INADDR_ANY;
    sin.sin_port=htons(port);
    if (bind(s, (struct sockaddr*) &sin, sizeof(sin))==SOCKET_ERROR) exit(1);
    if (listen(s,10)==SOCKET_ERROR) exit(1);
    return s;
}

int tcp_lire(SOCKET s, char* contenu, unsigned int longeur_attendue){//Lis le message envoyé, le stoque dans contenu, et renvoye le nombre d'octets reçus
    char reserve[1500];
    char* tmp=reserve;
    int longeur_reserve=sizeof(reserve);
    int longeur;
    int longeur_finale=0;
    do{
        //printf("attente d'un nouveau paquet\n");
        longeur=recv(s,tmp,longeur_reserve,0);
        tmp+=longeur;
        longeur_reserve-=longeur;
        longeur_finale+=longeur;
        //printf("paquet de %i octets reçu, il reste %i octets dans la réserve, on attend encore %i octets\n",longeur,longeur_reserve,longeur_attendue-longeur_finale);
    }while (longeur!=SOCKET_ERROR && longeur_finale<longeur_attendue && longeur_reserve!=0);
    if (longeur==SOCKET_ERROR) exit(1);
    memcpy(contenu,reserve,longeur_finale);
    contenu[longeur_finale]='\0';
    return longeur_finale;
}

short tcp_lire_court(SOCKET s){//Lit un entier court et le renvoie
    char* reserve=malloc(3);
    tcp_lire(s, reserve, 3);
    printf("chaîne reçue: %s \n", reserve);
    return atoi(reserve);
}

int tcp_envoyer_court(SOCKET s, short donnes){//Envoye un entier court, renvoie le nombre d'octets envoyés (2 normalement) ou -1 en cas d'erreur
    char capsule[3];
    capsule[0]=(char)(donnes/10)+48;
    capsule[1]=(char)(donnes%10)+48;
    capsule[2]='\0';
    printf("Message %s envoyé\n",capsule);
    int envoyes=send(s,capsule,sizeof(capsule),0);
    if (envoyes==SOCKET_ERROR) exit(1);
    return envoyes;
}

