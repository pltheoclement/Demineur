#include <stdio.h>
#include "fonction.h"
#include "variable.h"

i
k
l

//Fonction affichage qui est le premier menu affiché au joueur 
void Affichage_menu(){

    //Affcihage des règles du jeu 
    Affichage_regles_jeu();
    printf("\n");
    
    int choix;
    printf("Bienvenue sur le menu du jeu 'Le demineur'\n");
    printf("Veuillez faire un choix entre les differentes options:\n");

    //Choix entre les différentes options du menu
    printf("1- Creer une partie et jouer \n2-Charger une partie sauvegardee \n3-Quitter le jeu\n");

    //Vérification de la saisie du choix soit 1, 2 ou 3 
    do
    {
        scanf("%d", &choix);
    } while (choix !=1 && choix !=2 && choix !=3);
    
    //switch permettant de définir les fonctions à utiliser en fonction du choix de l'utilisateur
    switch (choix)
    {
        case 1:
            //définition des paramètres de jeu 
            parametres(&lignes, &colonnes, &nb_mines, &manuel_auto);
            //création de la grille de test
            creation_grille_test(grille_1D_test);
            //création grille affichage
            creation_grille_affichage(grille_1D_affichage);
            //Affichage de la grille en 2D
            Affichage_grille(grille_1D_affichage);
            //Affcihage du menu de jeu 
            Affichage_menu_jeu();
            break; 
        
        case 2:
            //Chargement de la partie
            charger_partie();
            //Affichage de la grille en 2D
            Affichage_grille(grille_1D_affichage);
            //Affichage du menu de jeu 
            Affichage_menu_jeu();
            break;

        case 3:
            //Dans ce cas le joueur décide de quitter la partie 
            printf("Au plaisir de te revoir jouer! A une prochaine fois!");
            while (getchar()!='\n');
            while (getchar()!='\n');            
            break;
    }
}
