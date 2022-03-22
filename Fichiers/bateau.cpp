/**
 * @author Colas NAUDI
 * @name bateau.cpp
 * @modify 28 decembre 2021
 * @desc Corps du module Bateau, contenant les définitions des procédures déclarés dans bateau.h .
*/

#include "bateau.h"
#include "jeu.h"
#include "game-tools.h"
#include <iostream>
using namespace std;
using OS::random;

void positionnerBateau(bool posBateau[][9], unsigned short int& rotationBateau, unsigned short int& premiereCaseBateauX, unsigned short int& premiereCaseBateauY){
    /* ------------------------------- TRAITEMENTS ------------------------------ */

    //Choix aleatoire de l'orientation du bateau
    rotationBateau = random(1,4);
    //Positionner le bateau
    switch (rotationBateau)
    {
    case 1://Position verticale
        premiereCaseBateauX = random(0,8);
        premiereCaseBateauY = random(0,5);
        for (int i = 0; i < 4; i++)
        {
            posBateau[premiereCaseBateauY+i][premiereCaseBateauX] = true;
        }
        break;
    case 2://Position horizontale
        premiereCaseBateauX = random(0,8);
        premiereCaseBateauY = random(0,5);
        for (int i = 0; i < 4; i++)
        {
            posBateau[premiereCaseBateauY][premiereCaseBateauX+i] = true;
        }
        break;
    case 3://Diagonale HautGauche - BasDroit
        premiereCaseBateauX = random(0,5);
        premiereCaseBateauY = random(0,5);
        for (int i = 0; i < 4; i++)
        {
            posBateau[premiereCaseBateauY+i][premiereCaseBateauX+i] = true;
        }
        break;
    case 4://Diagonale HautDroit - BasGauche
        premiereCaseBateauX = random(3,8);
        premiereCaseBateauY = random(0,5);
        for (int i = 0; i < 4; i++)
        {
            posBateau[premiereCaseBateauY+i][premiereCaseBateauX-i] = true;
        }
        break;
    }
}

void coordBateau (unsigned short int rotationBateau, unsigned short int premiereCaseBateauX, unsigned short int premiereCaseBateauY)
{
    switch (rotationBateau)
    {
    case 1:
        for (int i = 0; i < 4; i++)
        {
            cout << "( " << chiffreEnLettre(premiereCaseBateauX+1) << ", " << premiereCaseBateauY+i+1 << " )";
        }
        break;
    case 2:
        for (int i = 0; i < 4; i++)
        {
            cout << "( " << chiffreEnLettre(premiereCaseBateauX+i+1) << ", " << premiereCaseBateauY+1 << " )";
        }
        break;
    case 3:
        for (int i = 0; i < 4; i++)
        {
            cout << "( " << chiffreEnLettre(premiereCaseBateauX+i+1) << ", " << premiereCaseBateauY+i+1 << " )";
        }
        break;
    case 4:
        for (int i = 0; i < 4; i++)
        {
            cout << "( " << chiffreEnLettre(premiereCaseBateauX-i+1) << ", " << premiereCaseBateauY+i+1 << " )";
        }
        break;
    }
}