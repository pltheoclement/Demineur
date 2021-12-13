#include <stdio.h>
#include <stdlib.h>
#include <dirent.h>
#include "variable.h"
#include "fonction.h"

void devoiler_case(int pointeur_grille_test[1000], int pointeur_grille_affichage[1000], int ligne, int colonne)
{
    
    //testons les cases qui sont autours de la case afin de voir si il y a des bombes
    //On prend des coordonnées en 2D qu'on passe en 1D pour faire les tst dans les grilles 1D
    int compteur_bombes = 0;
    if (pointeur_grille_test[(((ligne - 1) * colonnes + (colonne)) - 1)] == -1)
    {
        //case à droite 
        if ((pointeur_grille_test[(((ligne - 1) * colonnes + (colonne + 1)) - 1)]) == 1 && (colonne + 1 < colonnes + 1))
        {
            compteur_bombes++;
        }
        //case à gauche
        if ((pointeur_grille_test[(((ligne - 1) * colonnes + (colonne - 1)) - 1)]) == 1 && (colonne - 1 >= 1))
        {
            compteur_bombes++;
        }
        //case en bas
        if ((pointeur_grille_test[(((ligne - 1 + 1) * colonnes + (colonne)) - 1)]) == 1 && (ligne + 1 < lignes + 1))
        {
            compteur_bombes++;
        }
        //case en haut 
        if ((pointeur_grille_test[(((ligne - 1 - 1) * colonnes + (colonne)) - 1)]) == 1 && (lignes - 1 >= 1))
        {
            compteur_bombes++;
        }
        //case en haut à droite
        if ((pointeur_grille_test[(((ligne - 1 - 1) * colonnes + (colonne + 1)) - 1)]) == 1 && (colonne + 1 < colonnes + 1) && (lignes - 1 >= 1))
        {
            compteur_bombes++;
        }
        //case en bas à droite
        if ((pointeur_grille_test[(((ligne - 1 + 1) * colonnes + (colonne + 1)) - 1)]) == 1 && (ligne + 1 < lignes + 1) && (colonne + 1 < colonnes + 1))
        {
            compteur_bombes++;
        }
        //case en haut à gauche
        if ((pointeur_grille_test[(((ligne - 1 - 1) * colonnes + (colonne - 1)) - 1)]) == 1 && (lignes - 1 >= 0) && (colonne - 1 >= 1))
        {
            compteur_bombes++;
        }
        //case en bas à gauche
        if ((pointeur_grille_test[(((ligne - 1 + 1) * colonnes + (colonne - 1)) - 1)]) == 1 && (ligne + 1 < lignes + 1) && (colonne - 1 >= 1))
        {
            compteur_bombes++;
        }
    }

    //On met à la place de la case dans la grille d'affichage le nombre de bombes qu'il y a autour
    pointeur_grille_affichage[(((ligne - 1) * colonnes + (colonne)) - 1)] = compteur_bombes;

    //Si il y a 0 bombe autour alors on fait le meme appel avec toutes les cases autour 
    if (compteur_bombes == 0)
    {
        //case à droite 
        if ((pointeur_grille_affichage[(((ligne - 1) * colonnes + (colonne + 1)) - 1)]) == -1 && (colonne + 1 < colonnes + 1))
        {
            devoiler_case(grille_1D_test, grille_1D_affichage, ligne, colonne + 1);
        }
        //case à gauche
        if ((pointeur_grille_affichage[(((ligne - 1) * colonnes + (colonne - 1)) - 1)]) == -1 && (colonne - 1 >= 1))
        {
            devoiler_case(grille_1D_test, grille_1D_affichage, ligne, colonne - 1);
        }
        //case en bas
        if ((pointeur_grille_affichage[(((ligne - 1 + 1) * colonnes + (colonne)) - 1)]) == -1 && (ligne + 1 < lignes + 1))
        {
            devoiler_case(grille_1D_test, grille_1D_affichage, ligne + 1, colonne);
        }
        //case en haut 
        if ((pointeur_grille_affichage[(((ligne - 1 - 1) * colonnes + (colonne)) - 1)]) == -1 && (lignes - 1 >= 1))
        {
            devoiler_case(grille_1D_test, grille_1D_affichage, ligne - 1, colonne);
        }
        //case en haut à droite
        if ((pointeur_grille_affichage[(((ligne - 1 - 1) * colonnes + (colonne + 1)) - 1)]) == -1 && (colonne + 1 < colonnes + 1) && (lignes - 1 >= 1))
        {
            devoiler_case(grille_1D_test, grille_1D_affichage, ligne - 1, colonne + 1);
        }
        //case en bas à droite
        if ((pointeur_grille_affichage[(((ligne - 1 + 1) * colonnes + (colonne + 1)) - 1)]) == -1 && (ligne + 1 < lignes + 1) && (colonne + 1 < colonnes + 1))
        {
            devoiler_case(grille_1D_test, grille_1D_affichage, ligne + 1, colonne + 1);
        }
        //case en haut à gauche
        if ((pointeur_grille_affichage[(((ligne - 1 - 1) * colonnes + (colonne - 1)) - 1)]) == -1 && (lignes - 1 >= 0) && (colonne - 1 >= 1))
        {
            devoiler_case(grille_1D_test, grille_1D_affichage, ligne - 1, colonne - 1);
        }
        //case en bas à gauche
        if ((pointeur_grille_affichage[(((ligne - 1 + 1) * colonnes + (colonne - 1)) - 1)]) == -1 && (ligne + 1 < lignes + 1) && (colonne - 1 >= 1))
        {
            devoiler_case(grille_1D_test, grille_1D_affichage, ligne + 1, colonne - 1);
        }
    }
}


void placer_supprimer_drapeau(int pointeur_grille_affichage[1000], int ligne, int colonne)
{
    //Le drapeau est caractérisée par un 9 dans la grille d'affichage 
    //Si la case n'est pas dévoilée ou si il y a deja un drapeau dessus 
    if (pointeur_grille_affichage[(((ligne - 1) * colonnes + (colonne)) - 1)] == -1 || pointeur_grille_affichage[(((ligne - 1) * colonnes + (colonne)) - 1)] == 9)
    {
        //Si il y a pas de drapeau alors on pose un drapeau
        if (pointeur_grille_affichage[(((ligne - 1) * colonnes + (colonne)) - 1)] != 9)
        {
            pointeur_grille_affichage[(((ligne - 1) * colonnes + (colonne)) - 1)] = 9;
        }

        //Si drapeau alors on l'enlève 
        else
        {
            printf("Un drapeau se trouve deja sur cette case il va donc etre supp de la grille");
            pointeur_grille_affichage[(((ligne - 1) * colonnes + (colonne)) - 1)] = -1;
        }
    }

    //Si case déja dévoilée
    else
    {
        printf("La case est devoile vous ne pouvez pas mettre un drapeau ici");
    }
}

void placer_supprimer_interro(int pointeur_grille_affichage[1000], int ligne, int colonne)
{
    //Le point d'interro est caractérisé par un 10 dans la grille de test 
    //Si la case n'est pas dévoilée ou si il y a deja un ? dessus
    if (pointeur_grille_affichage[(((ligne - 1) * colonnes + (colonne)) - 1)] == -1 || pointeur_grille_affichage[(((ligne - 1) * colonnes + (colonne)) - 1)] == 10)
    {
        //Si il y a pas de ? alors on pose un ?
        if (pointeur_grille_affichage[(((ligne - 1) * colonnes + (colonne)) - 1)] != 10)
        {
            pointeur_grille_affichage[(((ligne - 1) * colonnes + (colonne)) - 1)] = 10;
        }

        //Si ? alors on l'enlève
        else
        {
            printf("Un ? se trouve deja sur cette case il va donc etre supp de la grille");
            pointeur_grille_affichage[(((ligne - 1) * colonnes + (colonne)) - 1)] = -1;
        }
    }
    //si case déja dévoilée
    else
    {
        printf("La case est devoile vous ne pouvez pas mettre un ? ici");
    }
}

void demander_aide(int pointeur_grille_affichage[1000], int pointeur_grille_test[1000])
{
    //taille max du tableau 2D en 1D
    int dimension_1D = colonnes * lignes;


    for (int i = 0; i < dimension_1D; i++)
    {
        //Si ? et bombe 
        if (pointeur_grille_affichage[i] == 10 && pointeur_grille_test[i] == 1)
        {
            //On place un drapeau
            pointeur_grille_affichage[i] = 9;
        }
        //Si pas de bombe alors on supprime le ?
        else if (pointeur_grille_affichage[i] == 10 && pointeur_grille_test[i] == -1)
        {
            pointeur_grille_affichage[i] = -1;
        }
    }
}

int gagner_partie(int pointeur_grille_affichage[1000])
{
    int compteur=0;
    int dim_tab=colonnes*lignes;
    //Parcours de la grille d'affichage de la grille d'affichage
    for (int i = 0; i < dim_tab; i++)
    {
        //Si on trouve que la case comporte un nombre de bombes affichées dans la grille alors on ajoute 1 au compteur
        if (pointeur_grille_affichage[i]==0 || pointeur_grille_affichage[i]==1 || pointeur_grille_affichage[i]==2 || pointeur_grille_affichage[i]==3 || pointeur_grille_affichage[i]==4 || pointeur_grille_affichage[i]==5 || pointeur_grille_affichage[i]==6 || pointeur_grille_affichage[i]==7 || pointeur_grille_affichage[i]==8)//&& pointeur_grille_affichage[i]!=9 && pointeur_grille_affichage[i]!=10
        {
            compteur=compteur+1;
        }
    }
    //Test si le nombre total de cases dévoilées est égale a la taille max de la grille moins le nombre de bombes (si oui la partie est gagnée)
    if (compteur==dim_tab-nb_mines)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}


void sauvegarder_partie()
{
    int i, n;
    FILE *write1;//flot de donnée (pointeur qui va pointer sur le fichier ou on ecrit)
    
    char nom[20];
    printf("Donnez un nom de sauvegarde\n");
    scanf("%s", nom);
    strcat(nom, ".txt");//concataine le nom qu'on a donné avec txt 

    write1 = fopen(nom, "wb");// wb permet d'ecrire en binaire
    
    /* On ecrit le compteur */
    n = compteur_tour;
    fprintf(write1,"%d\n",n);//fprintf permet de print dans le fichier
    
    /* On ecrit le nombre de colonnes */
    n = colonnes;
    fprintf(write1,"%d\n",n);
    
   
    /* On ecrit le nombre de lignes */
    n = lignes;
    fprintf(write1,"%d\n",n);
  
   
    
    for (i = 0; i < colonnes*lignes; i++)
    {
        /* On recupere les élément du tableau un à un */
        n = grille_1D_test[i];
        fprintf(write1,"%d\n",n);
        
    }
    
    for (i = 0; i < colonnes*lignes; i++)
    {
        /* On recupere les élément du tableau un à un */
        n = grille_1D_affichage[i];
        fprintf(write1,"%d\n",n);
        
    }
    fclose (write1);
    
}
