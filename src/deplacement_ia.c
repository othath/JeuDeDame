#include "deplacement_ia.h"
#include "rafle.h"

void listeCoups(PDamier plateau, int t){
    int x1;
    int y1;
    /*parcour du tableau entier*/
    for(int i=0; i<=LIGNES; i++){
        for(int j=0; j<=COLONNES; j++){
            /*si la case n'est pas vide*/
            if(plateau->plateau[i][j]!=VIDE){
                /*si c'est un pion*/
                if(plateau->plateau[i][j]==PION_NOIR || plateau->plateau[i][j]==PION_BLANC){
                    x1=i;
                    y1=j;
                    /*vérification des voisins*/
                    for(int g=-1; g<=1; g+=2){
                        for(int k=-1; k<=1; k+=2){
                            int x2 = x1+(2*k);
                            int y2 = y1+(2*g);
                            if(x1+k>0 && y1+g>0 && x1+k<10 && y1+g<10 && x1<10 && y1<10 && y2<10 && x2<10){
                                if(t==0){
                                    /*check si voisin vide ou ennemie*/
                                    if(plateau->plateau[x1+k][y1+g]==PION_NOIR || plateau->plateau[x1+k][y1+g]==DAME_NOIRE){
                                        if(plateau->plateau[x1+(2*k)][y1+(2*g)]==VIDE){
                                            //TODO: retourner un tableau comprennant x1,y1 x2,y2
                                            printf("prise possible entre x1=%i,y1=%i et x2=%i,y2=%i\n",x1,y1,(x1+(2*k)),(y1+(2*g)));
                                        }
                                    }
                                    else if(plateau->plateau[x1+k][y1+g]==VIDE){
                                        //TODO: retourner un tableau comprennant x1,y1 x2,y2
                                        printf("déplacement possible entre x1=%i,y1=%i et x2=%i,y2=%i\n",x1,y1,(x1+k),(y1+g));
                                    }
                                }
                                if(t==1){
                                    /*check si voisin vide ou ennemie*/
                                    if(plateau->plateau[x1+k][y1+g]==PION_BLANC || plateau->plateau[x1+k][y1+g]==DAME_BLANCHE){
                                        if(plateau->plateau[x1+(2*k)][y1+(2*g)]==VIDE){
                                            //TODO: retourner un tableau comprennant x1,y1 x2,y2
                                            printf("prise possible entre x1=%i,y1=%i et x2=%i,y2=%i\n",x1,y1,(x1+(2*k)),(y1+(2*g)));
                                        }
                                    }
                                    else if(plateau->plateau[x1+k][y1+g]==VIDE){
                                        //TODO: retourner un tableau comprennant x1,y1 x2,y2
                                        printf("déplacement possible entre x1=%i,y1=%i et x2=%i,y2=%i\n",x1,y1,(x1+k),(y1+g));
                                    }
                                }
                            }
                        }
                    }
                }
                /*si c'est une dame*/
                if(plateau->plateau[i][j]==DAME_BLANCHE || plateau->plateau[i][j]==DAME_NOIRE){
                    x1=i;
                    y1=j;
                    int diff_x=COLONNES-i;
                    int diff_y=COLONNES-j;
                    /*si nous sommes sur un diagonale*/
                    if(abs(diff_x)==abs(diff_y)){
                        for(int k=0; k++<=diff_x;k++){
                            if(diff_x<0 && diff_y<0){
                                /*déplacement*/
                                while(plateau->plateau[x1-k][y1-k]==VIDE){
                                    printf("déplacement possible entre x1=%i,y1=%i et x2=%i,y2=%i",x1,y1,(x1-k),(y1-k));
                                }
                                if(t==0){
                                    /*prise dame*/
                                    if(plateau->plateau[x1-k][y1-k]==PION_NOIR || plateau->plateau[x1-k][y1-k]==DAME_NOIRE){
                                        if(plateau->plateau[x1-k-1][y1-k-1]==VIDE){
                                            printf("prise possible entre x1=%i,y1=%i et x2=%i,y2=%i\n",x1,y1,(x1-k-1),(y1-k-1));
                                        }
                                    }
                                }
                                if(t==1){
                                    if(plateau->plateau[x1-k][y1-k]==PION_BLANC || plateau->plateau[x1-k][y1-k]==DAME_BLANCHE){
                                        if(plateau->plateau[x1-k-1][y1-k-1]==VIDE){
                                            printf("prise possible entre x1=%i,y1=%i et x2=%i,y2=%i\n",x1,y1,(x1-k-1),(y1-k-1));
                                        }
                                    }
                                }
                            }
                            if(diff_x>0 && diff_y<0){
                                while(plateau->plateau[x1+k][y1-k]==VIDE){
                                    printf("déplacement possible entre x1=%i,y1=%i et x2=%i,y2=%i\n",x1,y1,(x1+k),(y1-k));
                                }
                                if(t==0){
                                    /*prise dame*/
                                    if(plateau->plateau[x1+k][y1-k]==PION_NOIR || plateau->plateau[x1+k][y1-k]==DAME_NOIRE){
                                        if(plateau->plateau[x1+k+1][y1-k-1]==VIDE){
                                            printf("prise possible entre x1=%i,y1=%i et x2=%i,y2=%i\n",x1,y1,(x1+k+1),(y1-k-1));
                                        }
                                    }
                                }
                                if(t==1){
                                    if(plateau->plateau[x1+k][y1-k]==PION_BLANC || plateau->plateau[x1+k][y1-k]==DAME_BLANCHE){
                                        if(plateau->plateau[x1+k+1][y1-k-1]==VIDE){
                                            printf("prise possible entre x1=%i,y1=%i et x2=%i,y2=%i\n",x1,y1,(x1+k+1),(y1-k-1));
                                        }
                                    }
                                }
                            }
                            if(diff_x<0 && diff_y>0){
                                while(plateau->plateau[x1-k][y1+k]==VIDE){
                                    printf("déplacement possible entre x1=%i,y1=%i et x2=%i,y2=%i\n",x1,y1,(x1-k),(y1+k));
                                }
                                if(t==0){
                                    /*prise dame*/
                                    if(plateau->plateau[x1-k][y1+k]==PION_NOIR || plateau->plateau[x1-k][y1+k]==DAME_NOIRE){
                                        if(plateau->plateau[x1-k-1][y1+k+1]==VIDE){
                                            printf("prise possible entre x1=%i,y1=%i et x2=%i,y2=%i\n",x1,y1,(x1-k-1),(y1+k+1));
                                        }
                                    }
                                }
                                if(t==1){
                                    if(plateau->plateau[x1-k][y1+k]==PION_BLANC || plateau->plateau[x1-k][y1+k]==DAME_BLANCHE){
                                        if(plateau->plateau[x1-k-1][y1+k+1]==VIDE){
                                            printf("prise possible entre x1=%i,y1=%i et x2=%i,y2=%i\n",x1,y1,(x1-k-1),(y1+k+1));
                                        }
                                    }
                                }
                            }
                            if(diff_x>0 && diff_y>0){
                                while(plateau->plateau[x1-k][y1-k]==VIDE){
                                    printf("déplacement possible entre x1=%i,y1=%i et x2=%i,y2=%i\n",x1,y1,(x1+k),(y1+k));
                                }
                                if(t==0){
                                    /*prise dame*/
                                    if(plateau->plateau[x1+k][y1+k]==PION_NOIR || plateau->plateau[x1+k][y1+k]==DAME_NOIRE){
                                        if(plateau->plateau[x1+k+1][y1+k+1]==VIDE){
                                            printf("prise possible entre x1=%i,y1=%i et x2=%i,y2=%i\n",x1,y1,(x1+k+1),(y1+k+1));
                                        }
                                    }
                                }
                                if(t==1){
                                    if(plateau->plateau[x1+k][y1+k]==PION_BLANC || plateau->plateau[x1+k][y1+k]==DAME_BLANCHE){
                                        if(plateau->plateau[x1+k+1][y1+k+1]==VIDE){
                                            printf("prise possible entre x1=%i,y1=%i et x2=%i,y2=%i\n",x1,y1,(x1+k+1),(y1+k+1));
                                        }
                                    }
                                }
                            }
                        }
                    }
                }
            }
        }
    }
}