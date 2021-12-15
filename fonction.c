#include <stdio.h>
#include <stdlib.h>
#include "variable.h"
#include "action.h"
#include "fonction.h"
#include "menu.h"
#include <time.h>

void parametres(int *pointeur_ligne, int *pointeur_colonne, int *pointeur_mines, int *manuel_auto)
{
    //Choix des paramètres
    printf("Veuillez rentrer les nouveaux parametres:\n");
    printf("Nombre de lignes: ");
    scanf("%d", pointeur_ligne);
    printf("\n");
    printf("Nombre de colonnes: ");
    scanf("%d", pointeur_colonne);
    printf("\n");
    printf("Nombre de mines au depart: ");
    scanf("%d", pointeur_mines);

    //Test si le nombre de mines dépasse pas le nombre de cases
    while (*pointeur_mines > (*pointeur_ligne) * (*pointeur_colonne))
    {
        printf("Attention le nombre de mines depasse le nombre de cases veuillez rentrer une nouvelle valeur");
        scanf("%d", pointeur_mines);
    }

    //Choix du placement des mines
    printf("\n");
    printf("Placement des mines manuel ou automatique '0' pour AUTO '1' pour MANUEL: ");
    scanf("%d", manuel_auto);
    while (getchar() != '\n');

    //Test si la valeur de manuel_auto est bonne
    while (*manuel_auto != 0 && *manuel_auto != 1)
    {
        printf("Attention votre valeur est ni 0 ni 1 veuillez rentrer une nouvelle valeur");
        scanf("%d", manuel_auto);
    }

    //Affichage des nouveaux paramètres
    if (*manuel_auto == 0)
    {
        printf("Les nouveaux parametres sont donc:\n nombre de lignes: %d\n nombre de colonnes: %d\n nombre de mines: %d\n Placement automatique des bombes\n", *pointeur_ligne, *pointeur_colonne, *pointeur_mines);
    }
    else
    {
        printf("Les nouveaux parmetres sont donc:\n nombre de lignes: %d\n nombre de colonnes: %d\n nombre de mines: %d\n Placement manuel des bombes\n", *pointeur_ligne, *pointeur_colonne, *pointeur_mines);
    }
    
}

void creation_grille_test(int pointeur_tab_test[1000])
{
    int n;
    //Initialisation de la grille
    int dim_tab_test = colonnes * lignes;

    //La grille se remplie de -1
    for (int j = 0; j < dim_tab_test; j++)
    {
        pointeur_tab_test[j] = -1;
    }

    //Création de la grille de test en automatique
    if (manuel_auto == 0)
    {
        srand(time(NULL));
        for (int j = 0; j < nb_mines; j++)
        {
            //On va générer ici des nombres entre 0 et la dim max de la grille
            //srand(time(NULL));
            n = (rand() % (dim_tab_test + 1));
            printf("%d", n);
            //Les positions des mines sont marquées par des -1 dans la grille
            pointeur_tab_test[n] = 1; 
        }
        printf("\n");
    }

    //Positionnement des bombes par un deuxième joueur
    else
    {
        for (int k = 1; k <= nb_mines; k++)
        {
            //Choix des positions des bombes par le deuxième joueur
            printf("Joueur 2 veuillez rentrer la bombe numero %d dans l'ordre suivant: Ligne puis Colonne\n", k);
            int position_ligne;
            int position_colonne;
            scanf("%d", &position_ligne);
            scanf("%d", &position_colonne);

            //Passage de la postion 2D donnée par l'utilisateur à la position 1D dans la grille
            int position_1D = (((position_ligne - 1) * colonnes + position_colonne) - 1);

            //test si la position donnée est mauvaise ou si elle dépasse les bornes du tableau
            while (position_ligne > lignes || position_colonne > colonnes || pointeur_tab_test[position_1D] == 1)
            {
                printf("Veuillez rentrer une nouvelle position car celle ci n'existe pas ou est deja utilise\n");
                scanf("%d", &position_ligne);
                scanf("%d", &position_colonne);
                position_1D = (((position_ligne - 1) * colonnes + position_colonne) - 1);
            }
            
            //Les positions des mines sont marquées par des -1 dans la grille
            pointeur_tab_test[position_1D] = 1;
        }

        while (getchar() != '\n');  

        //Effacement de la console
        system("cls");
    }
}

void Affichage_grille(int Grille[1000])
{

    //Création de deux variables qui permettent de bouger dans le tableau 1D et afficher le tableau 2D
    int fin_ligne = 0;
    int fin_colonne = colonnes;

    printf(" ");

    //Délimitation supérieure de la grille
    for (int k = 0; k < colonnes; k++)
    {
        printf(" ");
        printf("-");
    }
    printf("\n");

    //Affichage de la grille 1D en grille 2D
    for (int i = 0; i < lignes; i++)
    {
        printf("| ");//Permet de délimiter la partie gauche de la grille 
        for (int j = fin_ligne; j < fin_colonne; j++)
        {
            //si la case n'a pas été encore dévoilée
            if (Grille[j] == -1)
            {
                printf("  ");
            }
            //si la case contient un drapeau
            else if (Grille[j] == 9)
            {
                printf("D ");
            }
            //si la case contient un ?
            else if (Grille[j] == 10)
            {
                printf("? ");
            }
            //Si la case est une case dévoilée
            else
            {
                printf("%d ", Grille[j]);
            }
        }
        //Délimitation droite de la grille 
        printf("|");
        //On décale le fin_ligne dans la grille 1D sur la case qui correspond au début de la ligne suivante dans le tableau 2D
        fin_ligne = fin_colonne;
        //On décale le fin_colonne dans la grille 1D sur la case qui correspond à la fin de la ligne suivante dans le tableau 2D
        fin_colonne = fin_colonne + colonnes;
        printf("\n");
    }

    //Délimitation inférieure de la grille
    printf(" ");
    for (int k = 0; k < colonnes; k++)
    {
        printf(" ");
        printf("-");
    }
    printf("\n");
}

void Affichage_grille1(int Grille[1000])
{

    //Création de deux variables qui permettent de bouger dans le tableau 1D et afficher le tableau 2D
    int fin_ligne = 0;
    int fin_colonne = colonnes;

    printf(" ");

    //Délimitation supérieure de la grille
    for (int k = 0; k < colonnes; k++)
    {
        printf(" ");
        printf("-");
    }
    printf("\n");

    //Affichage de la grille 1D en grille 2D
    for (int i = 0; i < lignes; i++)
    {
        printf("| ");//Permet de délimiter la partie gauche de la grille 
        for (int j = fin_ligne; j < fin_colonne; j++)
        {
            //si la case n'a pas été encore dévoilée
            if (Grille[j] == -1)
            {
                printf("  ");
            }
            //si la case contient un drapeau
            else if (Grille[j] == 9)
            {
                printf("D ");
            }
            //si la case contient un ?
            else if (Grille[j] == 10)
            {
                printf("? ");
            }
            //Si la case est une case dévoilée
            else
            {
                printf("%d ", Grille[j]);
            }
        }
        //Délimitation droite de la grille 
        printf("|");
        //On décale le fin_ligne dans la grille 1D sur la case qui correspond au début de la ligne suivante dans le tableau 2D
        fin_ligne = fin_colonne;
        //On décale le fin_colonne dans la grille 1D sur la case qui correspond à la fin de la ligne suivante dans le tableau 2D
        fin_colonne = fin_colonne + colonnes;
        printf("\n");
    }

    //Délimitation inférieure de la grille
    printf(" ");
    for (int k = 0; k < colonnes; k++)
    {
        printf(" ");
        printf("-");
    }
    printf("\n");
}
void Affichage_grille22222222222222(int Grille[1000])
{

    //Création de deux variables qui permettent de bouger dans le tableau 1D et afficher le tableau 2D
    int fin_ligne = 0;
    int fin_colonne = colonnes;

    printf(" ");

    //Délimitation supérieure de la grille
    for (int k = 0; k < colonnes; k++)
    {
        printf(" ");
        printf("-");
    }
    printf("\n");

    //Affichage de la grille 1D en grille 2D
    for (int i = 0; i < lignes; i++)
    {
        printf("| ");//Permet de délimiter la partie gauche de la grille 
        for (int j = fin_ligne; j < fin_colonne; j++)
        {
            //si la case n'a pas été encore dévoilée
            if (Grille[j] == -1)
            {
                printf("  ");
            }
            //si la case contient un drapeau
            else if (Grille[j] == 9)
            {
                printf("D ");
            }
            //si la case contient un ?
            else if (Grille[j] == 10)
            {
                printf("? ");
            }
            //Si la case est une case dévoilée
            else
            {
                printf("%d ", Grille[j]);
            }
        }
        //Délimitation droite de la grille 
        printf("|");
        //On décale le fin_ligne dans la grille 1D sur la case qui correspond au début de la ligne suivante dans le tableau 2D
        fin_ligne = fin_colonne;
        //On décale le fin_colonne dans la grille 1D sur la case qui correspond à la fin de la ligne suivante dans le tableau 2D
        fin_colonne = fin_colonne + colonnes;
        printf("\n");
    }

    //Délimitation inférieure de la grille
    printf(" ");
    for (int k = 0; k < colonnes; k++)
    {
        printf(" ");
        printf("-");
    }
    printf("\n");
}
void Affichage_grille222222222(int Grille[1000])
{

    //Création de deux variables qui permettent de bouger dans le tableau 1D et afficher le tableau 2D
    int fin_ligne = 0;
    int fin_colonne = colonnes;

    printf(" ");

    //Délimitation supérieure de la grille
    for (int k = 0; k < colonnes; k++)
    {
        printf(" ");
        printf("-");
    }
    printf("\n");

    //Affichage de la grille 1D en grille 2D
    for (int i = 0; i < lignes; i++)
    {
        printf("| ");//Permet de délimiter la partie gauche de la grille 
        for (int j = fin_ligne; j < fin_colonne; j++)
        {
            //si la case n'a pas été encore dévoilée
            if (Grille[j] == -1)
            {
                printf("  ");
            }
            //si la case contient un drapeau
            else if (Grille[j] == 9)
            {
                printf("D ");
            }
            //si la case contient un ?
            else if (Grille[j] == 10)
            {
                printf("? ");
            }
            //Si la case est une case dévoilée
            else
            {
                printf("%d ", Grille[j]);
            }
        }
        //Délimitation droite de la grille 
        printf("|");
        //On décale le fin_ligne dans la grille 1D sur la case qui correspond au début de la ligne suivante dans le tableau 2D
        fin_ligne = fin_colonne;
        //On décale le fin_colonne dans la grille 1D sur la case qui correspond à la fin de la ligne suivante dans le tableau 2D
        fin_colonne = fin_colonne + colonnes;
        printf("\n");
    }

    //Délimitation inférieure de la grille
    printf(" ");
    for (int k = 0; k < colonnes; k++)
    {
        printf(" ");
        printf("-");
    }
    printf("\n");
}


void creation_grille_affichage(int pointeur_tab_affichage[1000])
{
    //On remplie la grille d'affichage à -1 au départ 
    int dim_tab = lignes * colonnes;
    for (int i = 0; i < dim_tab; i++)
    {
        pointeur_tab_affichage[i] = -1;
    }
}



void Affichage_regles_jeu()
{

    //Rappel des règles du jeu
    printf("Pour rappel les regles du jeu sont les suivantes:\n");
    printf("Le but de la partie est de devoiler l'ensemble des cases ou il n'y a pas de bombes. Attention si vous tombez sur une case ou il y a une bombe la partie est perdu\n");
    printf("Vous aurez le choix entre differentes options lors de la partie\n");
    printf("Vous pourrez devoiler une case, placer/supprimer un drapeau, placer/supprimer un ?, demander de l'aide, sauvegarder et chager une partie ou tout simplement en creer une nouvelle\n");
    printf("Placer un drapeau pourra vous aider a deviner ou peuvent se situer les bombes\n");
    printf("Lorsque vous demandez de l'aide l'ensemble des cases qui sont marquees d'un ? seront soit remise a 0 si il n'y a pas de bombes ou alors remplacees par un drapeau si il y a une bombe\n");
}



void Affichage_menu_jeu()
{
    //Variables de positionnement des différents éléments
    int ligne_dev;
    int colonne_dev;
    int ligne_drapeau;
    int colonne_drapeau;
    int ligne_interro;
    int colonne_interro;

    //Variable de victoire 
    int win_game;
    int replay;

    //Affichage des différents modes de jeu
    printf("A vous de jouer !\n");
    printf("Choisissez une option de jeu\n");
    printf("1: Devoiler une case\n");
    printf("2: Placer/supprimer un drapeau sur une case\n");
    printf("3: Placer/supprimer un ? sur une case\n");
    printf("4: Demander de l'aide\n");
    printf("5: sauvegarder la partie\n");

    //Creation d'un switch pour le choix des différentes options
    int choix_jeu;
    scanf("%d", &choix_jeu);

    switch (choix_jeu)
    {
    case 1:
        //Coordonnées des cases à dévoiler
        printf("Choisissez une case a devoiler dans l'ordre suivant: ligne puis colonne\n");
        scanf("%d", &ligne_dev);
        scanf("%d", &colonne_dev);

        //Conversion 2D en 1D
        int position_1D = (((ligne_dev - 1) * colonnes + colonne_dev) - 1);

        //vérification si le joueur à perdu ou pas
        if (grille_1D_test[position_1D] == 1)
        {
            printf("LA PARTIE EST PERDU ... RETENTEZ VOTRE CHANCE UNE PROCHAINE FOIS !\n");
            //Test pour recommencer une partie 
            printf("Voulez vous jouer une nouvelle partie? 1 pour OUI 0 pour NON");
            scanf("%d",&replay);
            //Si oui alors recommencer partie 
            if (replay==1)
            {
                Affichage_menu();
            }
            else
            {
                break;
            }
        }

        //Si le joueur ne séléctionne pas une bombe 
        else
        {
            //Vérification des coordonnées si la case à déja été dévoilée ou si elle n'existe pas
            while (grille_1D_affichage[position_1D] != -1 || ligne_dev > lignes || colonne_dev > colonnes)
            {
                printf("La case choisie est soit deja devoilee ou alors la position sort de la grille. Rentrez une nouvelle valeur\n");
                scanf("%d", &ligne_dev);
                scanf("%d", &colonne_dev);
                position_1D = (((ligne_dev - 1) * colonnes + colonne_dev) - 1);
            }

            //Dévoilement de la case 
            devoiler_case(grille_1D_test, grille_1D_affichage, ligne_dev, colonne_dev);
            printf("\n");
            //Affichage de la nouvelle grille du démineur
            Affichage_grille(grille_1D_affichage);
            //Le compteur de tours augmente
            compteur_tour++;
            //Test si le joueur à gagné la partie
            win_game=gagner_partie(grille_1D_affichage);
            //SI OUI 
            if (win_game==1)
            {
                printf("BRAVO VOUS VENEZ DE GAGNER LA PARTIE en %d tours!\n",compteur_tour);
                //Test pour recommencer une partie 
                printf("Voulez vous jouer une nouvelle partie? 1 pour OUI 0 pour NON");
                scanf("%d",&replay);
                //Si oui alors recommencer partie
                if (replay==1)
                {
                    Affichage_menu();
                }
                else
                {
                    break;
                }
            }
            //SI NON
            else
            {
                //Relance du menu de jeu 
                Affichage_menu_jeu();
            }
        }
        break;

    case 2:
        //Choix de la case où mettre le drapeau 
        printf("Choisissez une case pour y poser un drapeau: ligne puis colonne\n");
        scanf("%d", &ligne_drapeau);
        scanf("%d", &colonne_drapeau);

        //Vérification des coordonnées si la case n'existe pas
        while (ligne_drapeau > lignes || colonne_drapeau > colonnes)
        {
            printf("La position sort de la grille. Rentrez une nouvelle valeur\n");
            scanf("%d", &ligne_drapeau);
            scanf("%d", &colonne_drapeau);
        }
        
        //Appel de la fonction pour placer ou supprimer un drapeau
        placer_supprimer_drapeau(grille_1D_affichage, ligne_drapeau, colonne_drapeau);
        printf("\n");
        //Affichage de la grille 
        Affichage_grille(grille_1D_affichage);
        //Appel récursif du menu de jeu 
        Affichage_menu_jeu();
        break;

    case 3:
        //Choix de la case où mettre le ? 
        printf("Choisissez une case pour y poser un drapeau: ligne puis colonne\n");
        scanf("%d", &ligne_interro);
        scanf("%d", &colonne_interro);

        //Vérification des coordonnées si la case n'existe pas
        while (ligne_interro > lignes || colonne_interro > colonnes)
        {
            printf("La position sort de la grille. Rentrez une nouvelle valeur\n");
            scanf("%d", &ligne_interro);
            scanf("%d", &colonne_interro);
        }

        //Appel de la fonction pour placer ou supprimer un ?
        placer_supprimer_interro(grille_1D_affichage, ligne_interro, colonne_interro);
        printf("\n");
        //Affichage de la grille 
        Affichage_grille(grille_1D_affichage);
        //Appel récursif du menu de jeu
        Affichage_menu_jeu();
        break;

    case 4:
        //Appel de la fonction pour demander de l'aide 
        demander_aide(grille_1D_affichage, grille_1D_test);
        //Affcihage de la grille 
        Affichage_grille(grille_1D_affichage);
        //Appel récursif du menu de jeu 
        Affichage_menu_jeu();
        break;

    case 5:
        //Appel de la fonction pour sauvergarder une partie
        sauvegarder_partie();
        break;

    default:
        break;
    }
}

void charger_partie()
{
    /* Pointeur*/
    FILE *open;
    int i, j;
    char buffer[10];//permet de stocker chaque ligne du fichier
    char nom[20];

    //Choix du nom de fichier 
    printf("Donnez le nom de la partie à sauvegarder\n");
    scanf("%s", nom);
    strcat(nom, ".txt");//On concatène le nom du fichier avec .txt

    /* Pointeur ouvre le fichier en mode lecture */
    open = fopen(nom, "rb");//read binaire
    
    //On récupère compteur_tour
    fgets(buffer, 10, open);
    compteur_tour = atoi(buffer);//atoi permet de changer une chaine de caractère en int

    //On récupère colonnes
    fgets(buffer, 10, open);
    colonnes = atoi(buffer);

    //On récupère lignes
    fgets(buffer, 10, open);
    lignes = atoi(buffer);

    //On récupère la grille de test 
    for (i = 0; i < colonnes * lignes ; i++)
    {
        /* On recupere les caracteres un à un */
        fgets(buffer, 10, open);
        grille_1D_test[i] = atoi(buffer);
        
    }

    //On récupère la grille d'affichage 
    for (i = 0; i < colonnes * lignes ; i++)
    {
        /* meme chose pour le second tableau */
        fgets(buffer, 10, open);
        grille_1D_affichage[i] = atoi(buffer);
        
    }

    //On ferme le fichier 
    fclose(open);
}
