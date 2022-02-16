#include "ihm.h"

PDamier d;
 PListeDamier ld;
int tour = 0;

void fermerFenetre(GtkWidget *widget, gpointer data){ 
    /* détruit la boucle principale ==> fermeture de l'application */ 
    gtk_main_quit(); 
}

void button_cb(GtkWidget *widget, gpointer data){
    GtkWidget *drawing_area = data;

    /* Now invalidate the affected region of the drawing area. */
    gtk_widget_queue_draw(drawing_area);

}
void clear(cairo_t *cr){ 
    /* Sauvegarde de l'état du tableau */
    cairo_save(cr); 
    cairo_set_source_rgb(cr, 1, 1, 1); 
    cairo_paint(cr); 

    /* Restore context */ 
    cairo_restore(cr); 
}

void dessinBordure(cairo_t *cr){ 
    /* Save current context */
    cairo_save(cr);

    /* Création du fond beige */
    cairo_set_source_rgb(cr, 1, 0.9, 0.8);
    cairo_rectangle(cr, 0, 0, LARGEUR, HAUTEUR);
    cairo_fill (cr);
    cairo_stroke(cr);

    /* Création de la bordure */
    cairo_set_source_rgb(cr, 0.6, 0.4, 0.3);
    cairo_rectangle(cr, 0, 0, RLargeur*12, RHauteur*12);
    cairo_fill (cr);
    cairo_stroke(cr);

    /* Création d'un grand carré pour faire un contour en noir de la bordure */
    cairo_set_source_rgb(cr, 0, 0, 0);
    cairo_rectangle(cr, 0, 0, RLargeur*12, RHauteur*12);
    cairo_stroke(cr);

    /* Restore context */ 
    cairo_restore(cr); 
}

void dessinContour(cairo_t *cr){ 
    /* Save current context */
    cairo_save(cr);

    /* Initialisation de variable */
    int e = 0;
    int f = 0;

    cairo_set_font_size(cr, 15);

    /* Contour de chiffre de 0 à 9 dans la ligne du haut */
    for(int j=60; j<(RLargeur+5)*10;j+=RLargeur){
        cairo_move_to(cr, j-5, 25); 
        cairo_set_source_rgb(cr, 0, 0, 0); 
        char chiffres[2];
        chiffres[0] = 48+e;
        chiffres[1] = '\0';
        cairo_show_text(cr, chiffres);
        e++;
    }

    /* Contour de lettre de A à j dans la colone de gauche */
    for(int j=60; j<(RHauteur+5)*10;j+=RHauteur){
        cairo_move_to(cr, 10, j+5); 
        cairo_set_source_rgb(cr, 0, 0, 0);
        char lettres[2];
        lettres[0] = 65+f;
        lettres[1] = '\0';
        cairo_show_text(cr, lettres);
        f++;
    }

    /* Création d'un grand carré pour faire un contour en noir de la grille */
    cairo_rectangle(cr, RLargeur, RHauteur, RLargeur*10, RHauteur*10);
    cairo_set_source_rgb(cr, 0, 0, 0);
    cairo_stroke(cr);

    /* Restore context */ 
    cairo_restore(cr); 
}

void dessinDamier(cairo_t *cr){ 
    /* Save current context */
    cairo_save(cr);
    /* dessin des carreaux du damier */
    for(int i=1; i<11; i++){
        for(int j=1; j<11; j++){
            /* dessine le rectangle */
            cairo_rectangle(cr, i*RLargeur, j*RHauteur, RLargeur, RHauteur); // (x, y, largeur, hauteur)
            /* cahnger la couleur de fond de chaque case en noir*/  
            if(i%2==(j+1)%2){
                cairo_set_source_rgb(cr, 0.6, 0.4, 0.3);
                cairo_fill (cr);
            }
            if(i%2==j%2){
                cairo_set_source_rgb(cr, 1, 0.9, 0.8);
                cairo_fill (cr);
            }
            cairo_stroke(cr);  
        }
    }
    cairo_restore(cr); 
}

void dessinTour(cairo_t *cr){
    /* Save current context */
    cairo_save(cr);
    cairo_move_to(cr, 180,  HAUTEUR-10);
    cairo_set_font_size(cr, 15);

    cairo_set_source_rgb(cr, 0, 0, 0);
    if(tour%2==0){
        cairo_show_text(cr, "Tour des blancs");
    }
    else{
        cairo_show_text(cr, "Tour des noirs");
    }   
}

void dessinPieces(cairo_t *cr){
    cairo_save(cr);

    /* dessin des pions noir en fonction du tableau */
    for(int i=0; i<10; i++){
        for (int j=0; j<10;j++){
            /* dessine les pions noir */
            if(d->plateau[i][j]==PION_NOIR){
                cairo_arc(cr, j*RLargeur+60, i*RHauteur+60, DIAMETRE, 0, 2 * M_PI);
                /* changer la coueleur du pion*/
                cairo_set_source_rgb(cr, 0, 0, 0);
                cairo_fill (cr);
            }
            /* dessine les pions blanc */
            else if(d->plateau[i][j]==PION_BLANC){
                cairo_arc(cr, j*RLargeur+60, i*RHauteur+60, DIAMETRE, 0, 2 * M_PI);
                /* changer la coueleur du pion*/
                cairo_set_source_rgb(cr, 1, 1, 1);
                cairo_fill (cr);
            }
            else if(d->plateau[i][j]==DAME_NOIRE){
                /* dessin des dames noires en fonction du tableau */
                cairo_rectangle(cr, j*RLargeur+50, i*RHauteur+50, Dlargeur, Dhauteur);
                cairo_set_source_rgb(cr, 0, 0, 0);
                cairo_fill (cr);
            }
            else if(d->plateau[i][j]==DAME_BLANCHE){
                /* dessine des dames blanches représenté par un carré blanc*/
                cairo_rectangle(cr, j*RLargeur+50, i*RHauteur+50, Dlargeur, Dhauteur);
                cairo_set_source_rgb(cr, 1, 1, 1);
                cairo_fill (cr);
            }
        }     
    }
  
    /* Restore context */ 
    cairo_restore(cr);
}

void activationEntree(GtkEntry *entry, gpointer data){
	const gchar *text;
	/* Recuperation du texte contenu dans le GtkEntry */
	text = gtk_entry_get_text(GTK_ENTRY(entry));
    if(checkInput(text)==0){
        if(choisir_deplacement(d,envoyerInput(text),tour%2)==0){
            dame(d);
            tour++;
        }
    }
/*mv_aleatoire(d,tour%2);//juste pour le test
            update_damier(d);
            tour++;*/
    const gchar test[1] = "\0";
    gtk_entry_set_text(entry, test);
}

gboolean draw_cb(GtkWidget *widget, cairo_t *cr, gpointer data){ 
    GtkWidget *drawing_area = data; 
    clear(cr);
    /* fonction d'appel pour les dessins*/
    dessinBordure(cr);
    dessinContour(cr);
    dessinDamier(cr);
    dessinPieces(cr);
    dessinTour(cr);

    return FALSE; 
}


/*************** MAIN *****************/


  int main(int argc, char **argv){

    /* Déclaration des widgets */
    GtkWidget *window; 
    GtkWidget *vBox; 
    GtkWidget *drawing_area;
    GtkWidget* entry;
    GtkWidget* entryButton;
    GtkWidget *button;

    /* Création d'un nouveau damier */
    d = new_damier();
    init_damier(d);
    ld=init_listeDamier();
    /* Initialisation de GTK+ */
    gtk_init(&argc, &argv); 
   
    /* Création de la fenête principale */ 
    window = gtk_window_new(GTK_WINDOW_TOPLEVEL); 
    /* Centrer la fenêtre sur l'écran */ 
    gtk_window_set_position(GTK_WINDOW(window), GTK_WIN_POS_CENTER); 
    /* Taille de la fenêtre */ 
    gtk_window_set_default_size(GTK_WINDOW(window), LARGEUR, HAUTEUR); 
    /* Changement du titre de la fenêtre */ 
    gtk_window_set_title(GTK_WINDOW(window), "Jeu de Dames");
    
    /* Création de la box verticale */ 
    vBox = gtk_box_new(GTK_ORIENTATION_VERTICAL, 0); 
    /* Insertion de la box dans la fenêtre */ 
    gtk_container_add(GTK_CONTAINER(window), vBox); 
     
    /* Création de la zone de dessin */ 
    drawing_area = gtk_drawing_area_new(); 
    /* Changer la taille minimum */ 
    gtk_widget_set_size_request(drawing_area, LARGEUR, HAUTEUR); 
    /* Insertion de la zone de dessin dans la box vertical */ 
    gtk_box_pack_start(GTK_BOX(vBox), drawing_area, TRUE, TRUE, 0);  

    /* Création de la zone de texte */
    entry = gtk_entry_new();
    /* Insertion de la zone de texte dans la box */
    gtk_box_pack_start(GTK_BOX(vBox), entry, FALSE, TRUE, 0);
   
    /* Signals used to draw the content of the widget */
    g_signal_connect(drawing_area, "draw", G_CALLBACK(draw_cb), drawing_area);
    g_signal_connect(G_OBJECT(entry), "activate", G_CALLBACK(activationEntree), NULL);
    g_signal_connect(G_OBJECT(entry), "activate", G_CALLBACK(button_cb), drawing_area);
  
    /* Connection of signal named "destroy" */
    g_signal_connect(G_OBJECT(window), "destroy", G_CALLBACK(fermerFenetre), NULL);

    /* Récupération évènements + signaux */ 
    gtk_widget_show_all(window);

    /* Boucle principale */ 
    gtk_main(); 
     
    return EXIT_SUCCESS; 
}   
