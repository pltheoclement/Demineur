/***Devoiler une case***/
void devoiler_case(int pointeur_grille_test[1000], int pointeur_grille_affichage[1000], int ligne, int colonne);

/***Placer/supp Drapeau***/
void placer_supprimer_drapeau(int pointeur_grille_affichage[1000], int ligne, int colonne);

/***Placer/supp ?***/
void placer_supprimer_interro(int pointeur_grille_affichage[1000], int ligne, int colonne);

/***Demander de l'aide***/
void demander_aide(int pointeur_grille_affichage[1000], int pointeur_grille_test[1000]);

/***Gagner partie***/
int gagner_partie(int pointeur_grille_affichage[1000]);

/***Sauvergarder une partie***/
void sauvegarder_partie();