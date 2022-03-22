/**
 * @file BatailleNavale.cpp
 * @author Colas NAUDI (colasnaudi@gmail.com)
 * @brief Programme principal de la bataille navale
 * @version 0.1
 * @date 15-02-2022
 * 
 * @copyright Copyright (c) 2022
 * 
**/

#include <iostream>
using namespace std;
#include "Fichiers/bateau.h"     // Module bateau contenant les procédures relatives au bateau.
#include "Fichiers/jeu.h"        // Module jeu contenant les procédures & fonctions relatives au jeu.
#include "Fichiers/game-tools.h"    // Module game-tools pour afficher les caractères en couleurs et utiliser une fonction random.

int main (void)
{
    /* -------------------------------------------------------------------------- */
    /*                                  VARIABLES                                 */
    /* -------------------------------------------------------------------------- */
    const unsigned int NB_CASES = 9;          // Le nombre de cases des tableaux tab & bateau de dimension 2.
    char vueMer[NB_CASES][NB_CASES];          // Le tableau tab de taille NB_CASES * NB_CASES contenant les caractères des positions joués par l'utilisateur.
    bool posBateau[NB_CASES][NB_CASES];       // Le tableau bateau de taille NB_CASES * NB_CASES contenant 4 valeur true correspondantes à la position du bateau, le reste est à false.
    string saisieJoueur;                      // La chaîne de caractère saisie pas l'utilisateur
    unsigned short int numeroLigne;           // La coordonnée en X convertie sous forme d'entier pour accéder à l'élement du tableau
    unsigned short int numeroColonne;         // La coordonnée en Y convertie sous forme d'entier pour accéder à l'élement du tableau
    unsigned int nbTour;                      // Le numero du tour joué
    unsigned short int compteurTouche;        // Le compteur de case du bateau trouvé par l'utilisateur, il faut qu'il atteigne 4 pour gagner la partie.
    unsigned short int rotationBateau;        // Variables prenant une valeur aléatoire entre 1 et 4 pour les 4 orientations du bateau (vertical, horizontal, diagonale Haut-Droit/Bas-Gauche, diagonale Haut-Gauche/Bas-Droit).
    unsigned short int premiereCaseBateauX;   // La coordonnée en X de la première case de bateau choisie aléatoirement entre deux bornes determinées selon l'orientation orientationBateau.
    unsigned short int premiereCaseBateauY;   // La coordonnée en Y de la première case de bateau choisie aléatoirement entre deux bornes determinées selon l'orientation orientationBateau.
    bool abandon;                             // Booléen qui indique si le joueur a abandonné ou pas

    /* -------------------------------------------------------------------------- */
    /*                                 TRAITEMENTS                                */
    /* -------------------------------------------------------------------------- */

    /* ------------------------------- Initialiser ------------------------------ */
    compteurTouche = 0;
    nbTour = 0;
    abandon = false;
    initialiserTableaux(posBateau, vueMer, NB_CASES);     //Initialiser le tableau tab & le tableau bateau
    positionnerBateau(posBateau, rotationBateau, premiereCaseBateauX, premiereCaseBateauY);        //Positionner le bateau

    /* ------------------- Jouer au jeu de la bataille navale ------------------- */
    while(true)
    {
        nbTour ++;
        afficherRegles(rotationBateau, premiereCaseBateauX, premiereCaseBateauY);   //Affichage des règles
        afficherTableau(vueMer, NB_CASES);     //Afficher le tableau avec les coups précédemments joués (s'il y en a)
        verifCoord(nbTour, saisieJoueur);   //Vérifier si les coordonnées entrées sont correctes en X et en Y

        /* ------------ Si la saisie est différente de l'abandon on joue ------------ */
        if (saisieJoueur != "@@")
        {
            determinerColonne(saisieJoueur, numeroColonne);     // Retourne le numero de la colonne correspondante au parcours du tableau
            determinerLigne(saisieJoueur, numeroLigne);     // Retourne le numero de la ligne correspondante au parcours du tableau
            toucheCoule(posBateau, vueMer, numeroLigne, numeroColonne, compteurTouche);     //Affiche '.' si le coup joué tombe dans l'eau
                                                                                            //sinon 'o' si le bateau est touché.
        }
        /* --------------------- S'il abandonne le jeu s'arrête --------------------- */
        else
        {
            abandon = true;
            break;
        }
        /* --------- Si il touche moins de 4 fois on efface, sinon on quitte -------- */
        if(compteurTouche!=4)
        {
            OS::effacer();
        }
        else
        {
            break;
        }
    }
    /* ------------------------------ Fin de partie ----------------------------- */
    /* -------------------------- Si le joueur a gagné -------------------------- */
    if (abandon == false)
    {
        afficherRegles(rotationBateau, premiereCaseBateauX, premiereCaseBateauY); //Affiche les règles du jeu ainsi que la position du bateau
        afficherTableau(vueMer, NB_CASES);     //Afficher le tableau avec les coups précédemments joués (s'il y en a)
        cout << "C O U L E  en " << nbTour << " tirs." << endl; //Nombre de tentatives que l'utilisateur a pris pour couler le bateau
    }
    /* ------------------------ Si le joueur à abandonné ------------------------ */
    else
    {
        cout << endl << "ABANDON bateau touche " << compteurTouche << " fois sur "  << nbTour << endl;
    }
    return 0;
}