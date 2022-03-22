/**
 * @author Colas NAUDI
 * @name jeu.h
 * @modify 24 novembre 2021
 * @desc Module Jeu contenant toutes les fonctions & procédures relatives au jeu de la bataille navale.
*/

#ifndef JEU_H
#define JEU_H

#include <iostream>
using namespace std;

void initialiserTableaux (bool posBateau[][9], char vueMer[][9], const unsigned int nbCases);
// BUT : Initialiser le tableau booléen tab1 de nbCases à false et le tableau de caractères de nbCases à " ".

void afficherTableau (char vueMer[][9], const unsigned int nbCases);
// BUT : Affiche le tableau tableau de nbCases avec les coups précédement joués (s'il y en a) sinon le tableau est affiché vide.

int determinerColonne(string saisieJoueur, unsigned short int& Colonne);
// BUT : Détermine d'après la saisie de joueur saisieJoueur le numero de colonne Colonne qu'il veut jouer.
//       Exemple : Colonne A correspond à 0 quand on accède au tableau

int determinerLigne(string saisieJoueur, unsigned short int& Ligne);
// BUT : Détermine d'après la saisie de joueur saisieJoueur le numero de la ligne Ligne qu'il veut jouer.
//       Exemple : Ligne 2 correspond à 1 qaund on accède au tableau

void afficherRegles(unsigned short int rotationBateau, unsigned short int premiereCaseBateauX, unsigned short int premiereCaseBateauY);
// BUT : Affiche les règles du jeu ainsi que les coordonnées du bateau grâce à l'orientation rotationBateau et de la première case
//       (premiereCaseBateauX, premierecaseBateauY).

char chiffreEnLettre (unsigned short int caseY);
// BUT : Converti l'entier court non signé CaseY en caractère correspondant à la lettre de la colonne où il se situe
//       Exemple : Colonne 2 = 'B'

void verifCoord(unsigned int& nbTour, string& saisieJoueur);
// BUT : Affiche, tant que saisieJoueur (les coordonnées entrées en X & Y) ne sont pas bonnes, un message de saisi ainsi que nbTour (le numero du tour joué).
//       Lorsque la coordonnée X n'est pas bonne "Erreur en X !" est affiché
//       Lorsque la coordonnée Y n'est pas bonne "Erreur en Y !" est affiché
//       Et si les deux coordonnées ne sont pas bonne les deux message seront affichées. Le numero du tour ne change pas tant que la saisie n'est pas bonne.

void toucheCoule (bool posBateau[][9], char vueMer[][9], unsigned short int& Ligne, unsigned short int& Colonne, unsigned short int& compteur);
// BUT : Suivant les coordonnees entrées, on regarde :
//       -  Si tab1[Ligne][Colonne] = true, si oui et que tab2[Ligne][Colonne] est différent de 'o', on ajoute le caractère 'o'
//          à tab2[Ligne][Colonne] et on incrémente compteur (le compteur de cases du bateau trouvés).
//       -  Sinon, si tab1[Ligne][Colonne] = false et que tab2[Ligne][Colonne] est différent de '.', on ajoute le caractère '.' à tab2[Ligne][Colonne].

#endif