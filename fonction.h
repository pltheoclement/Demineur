/****Modification des paramètres de la grille***/
void parametres(int* pointeur_ligne, int* pointeur_colonne, int* pointeur_mines, int* manuel_auto);

/***Création de la grille de test***/
void creation_grille_test(int pointeur_tab_test[1000]);

/***Création de la grille d'affichage***/
void creation_grille_affichage(int pointeur_tab_affichage[1000]);

/***Affichage de la grille 1D en grille 2D***/
void Affichage_grille(int Grille[1000]);

/***Affichage des règles du jeu***/
void Affichage_regles_jeu();

/***Affichagge du menu de jeu***/
void Affichage_menu_jeu();

/***charger la partie***/
void charger_partie();