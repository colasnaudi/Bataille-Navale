/**
 * @author Colas NAUDI
 * @name bateau.h
 * @modify 28 decembre 2021
 * @desc Module Bateau contenant toutes les procédures relatives au bateau à trouver de la bataille navale.
*/

#ifndef BATEAU_H
#define BATEAU_H

#include <iostream>
using namespace std;

void positionnerBateau(bool posBateau[][9], unsigned short int& rotationBateau, unsigned short int& premiereCaseBateauX, unsigned short int& premiereCaseBateauY);
// BUT : Initialise la position de bateau à trouver dans un tableau de booléen bateau, orienté sous 4 formes (vertical
//       horizontale, diagonale Haut-Droit/Bas-Gauche, diagonale Haut-Gauche/Bas-Droit) rotationBateau et la 
//       première case (premiereCaseBateauX, premiereCaseBateauY) est trouvée aléatoirement.

void coordBateau (unsigned short int rotationBateau, unsigned short int premiereCaseBateauX, unsigned short int premiereCaseBateauY);
// BUT : Affiche les coordonnées du bateau dans l'affichage des règles pour pouvoir le retrouver. Nous avons seulement besoin de
//       savoir l'orientation de bateau rotationBateau ainsi que la première case (premiereCaseBateauX, premiereCaseBateauY).

#endif