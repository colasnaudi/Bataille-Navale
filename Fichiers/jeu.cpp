/**
 * @author Colas NAUDI
 * @name jeu.cpp
 * @modify 24 novembre 2021
 * @desc Le corps du module Jeu contenant les définitions des fonctions et procédures déclarés dans jeu.h .
*/

#include "jeu.h"
#include "bateau.h"
#include "game-tools.h"
#include <iostream>
using namespace std;
using OS::afficherTexteEnCouleur;

void initialiserTableaux (bool posBateau[][9], char vueMer[][9], const unsigned int nbCases)
{
    for (int i = 0 ; i < nbCases ; i++)
    {
        for (int j = 0; j < nbCases; j++)
        {
            posBateau[i][j] = false;
            vueMer[i][j] = ' ';
        }
    }
}

void afficherTableau (char vueMer[][9], const unsigned int nbCases)
{
    cout << "   " << "A B C D E F G H I" << endl;
    for (int i = 0 ; i < 9 ; i++)
    {
        cout << i+1 << "  ";
        for (int j = 0; j < 9; j++)
        {
            if(vueMer[i][j]=='o')
            {
                afficherTexteEnCouleur('o', rouge, false);
            }
            else if (vueMer[i][j]=='~')
            {
                afficherTexteEnCouleur('~', cyan, false);
            }
            else
            {
                cout << " ";
            }
            
            cout << " ";
        }
        cout << endl;
    }
    cout << endl;
}

int determinerLigne(string saisieJoueur, unsigned short int& Ligne)
{
    switch (saisieJoueur[1])
    {
    case '1':
        Ligne = 0;
        break;
    case '2':
        Ligne = 1;
        break;
    case '3':
        Ligne = 2;
        break;
    case '4':
        Ligne = 3;
        break;
    case '5':
        Ligne = 4;
        break;
    case '6':
        Ligne = 5;
        break;
    case '7':
        Ligne = 6;
        break;
    case '8':
        Ligne = 7;
        break;
    case '9':
        Ligne = 8;
        break;
    }
    return Ligne;
}

int determinerColonne(string saisieJoueur, unsigned short int& Colonne)
{
    switch (saisieJoueur[0])
    {
    case 'A':
        Colonne = 0;
        break;
    case 'B':
        Colonne = 1;
        break;
    case 'C':
        Colonne = 2;
        break;
    case 'D':
        Colonne = 3;
        break;
    case 'E':
        Colonne = 4;
        break;
    case 'F':
        Colonne = 5;
        break;
    case 'G':
        Colonne = 6;
        break;
    case 'H':
        Colonne = 7;
        break;
    case 'I':
        Colonne = 8;
        break;
    }
    return Colonne;
}

void afficherRegles(unsigned short int rotationBateau, unsigned short int premiereCaseBateauX, unsigned short int premiereCaseBateauY)
{
    cout << "B A T A I L L E   N A V A L E" << endl;
    cout << "Le joueur doit couler un bateau de 4 cases" << endl;
    cout << "(vertical ou horizontal ou diagonal)." << endl;
    cout << endl;
    cout << "Bateau = ";
    coordBateau(rotationBateau, premiereCaseBateauX, premiereCaseBateauY);
    cout << endl;
}

char chiffreEnLettre (unsigned short int caseY)
{
    char caseYLettre; // Le caractère correspondant au numéro de caseY
    switch (caseY)
    {
    case 1:
        caseYLettre = 'A';
        break;
    case 2:
        caseYLettre = 'B';
        break;
    case 3:
        caseYLettre = 'C';
        break;
    case 4:
        caseYLettre = 'D';
        break;
    case 5:
        caseYLettre = 'E';
        break;
    case 6:
        caseYLettre = 'F';
        break;
    case 7:
        caseYLettre = 'G';
        break;
    case 8:
        caseYLettre = 'H';
        break;
    case 9:
        caseYLettre = 'I';
        break;
    }
    return caseYLettre;
}

void verifCoord(unsigned int& nbTour, string& saisieJoueur)
{
    //Verifie si les coordonnes entrées sont correctes
    do
    {
        //Affichage du numero de tir actuel
        cout << "Votre " << nbTour << "eme tir (ex. A3) ou abandonner (@@) ? ";

        //Demande de saisir de coordonnées
        cin >> saisieJoueur;

        //Si le premier caractère est faux --> "Erreur en X"
        if (!((saisieJoueur[0]=='A')||(saisieJoueur[0]=='B')||(saisieJoueur[0]=='C')||(saisieJoueur[0]=='D')||(saisieJoueur[0]=='E')||(saisieJoueur[0]=='F')||(saisieJoueur[0]=='G')||(saisieJoueur[0]=='H')||(saisieJoueur[0]=='I')||(saisieJoueur[0]=='@')))
        {
            cout << "Erreur en 'X' !" << endl;
        }

        //Si le deuxième caractère est faux --> "Erreur en Y"
        if (!((saisieJoueur[1]=='1')||(saisieJoueur[1]=='2')||(saisieJoueur[1]=='3')||(saisieJoueur[1]=='4')||(saisieJoueur[1]=='5')||(saisieJoueur[1]=='6')||(saisieJoueur[1]=='7')||(saisieJoueur[1]=='8')||(saisieJoueur[1]=='9')||(saisieJoueur[1]=='@')))
        {
            cout << "Erreur en 'Y' !" << endl;
        }

        //Si la saisie est trop longue
        if(saisieJoueur.size() > 2)
        {
            cout << "La saisie est trop longue ! (1 Lettre, 1 Chiffre)." << endl;
        }

    } while ((!(saisieJoueur.size()==2)&&((saisieJoueur[0]=='A')||(saisieJoueur[0]=='B')||(saisieJoueur[0]=='C')||(saisieJoueur[0]=='D')||(saisieJoueur[0]=='E')||(saisieJoueur[0]=='F')||(saisieJoueur[0]=='G')||(saisieJoueur[0]=='H')||(saisieJoueur[0]=='I')||(saisieJoueur[0]=='@')))||(!((saisieJoueur[1]=='1')||(saisieJoueur[1]=='2')||(saisieJoueur[1]=='3')||(saisieJoueur[1]=='4')||(saisieJoueur[1]=='5')||(saisieJoueur[1]=='6')||(saisieJoueur[1]=='7')||(saisieJoueur[1]=='8')||(saisieJoueur[1]=='9')||(saisieJoueur[1]=='@'))));
}

void toucheCoule (bool posBateau[][9], char vueMer[][9], unsigned short int& Ligne, unsigned short int& Colonne, unsigned short int& compteur)
{
    //Si le joueur touche le bateau on affiche 'o' et le compteur de cases trouvés est incrémenté;
    if ((posBateau[Ligne][Colonne] == true ) && (vueMer[Ligne][Colonne] != 'o'))
    {
        vueMer[Ligne][Colonne] = 'o';
        compteur ++;
    }
    //Si le joueur n'a pas touché le bateau on affiche '.'
    else if ((posBateau[Ligne][Colonne] == false) && (vueMer[Ligne][Colonne] != '~'))
    {
        vueMer[Ligne][Colonne] = '~';
    }
}