// test.cpp : Ce fichier contient la fonction 'main'. L'exécution du programme commence et se termine à cet endroit.
//
#include <iostream>
#include "Client.h"
#include "Dollar.h"
#include "Euro.h"
#include "MAD.h"
#include "Compte.h"
#include "CompteCourant.h"
#include "CompteEpargne.h"
#include "ComptePayant.h"
using namespace std;
using namespace Banque;

int main()
{
    Client* c1 = new Client("c1", "c1", "Add1");
    Devise* D1 = new Dollar(3000);
    Devise* D2 = new Euro(5000);
    Devise* D3 = new MAD(7000);
    Devise* Dec = new MAD(200);
    Devise* Dec2 = new Euro(200);
    Compte* cpt1 = new CompteCourant(c1,D1,Dec);
    Compte* cpt2 = new CompteEpargne(c1, D2,20);
    Compte* cpt3 = new ComptePayant(c1, D3,Dec2);
    cout << "********compte Courant**************" << endl;
    c1->Afficher();
    cpt1->consulter();
    cpt1->crediter(new Dollar(10));
    cpt1->consulter();
    cout << "********compte Epargne*****************" << endl;
    cpt2->consulter();
    cpt2->crediter(new Dollar(10));
    cpt2->consulter();
    cout << "***************compte Payant*************" << endl;
    cpt3->consulter();
    cpt3->crediter(new MAD(10));
    cpt3->consulter();
    cout << "********compte Courant**************" << endl;
    bool a=cpt1->debiter(new Dollar(10));
    if (a) printf("\nopération accéptée\n");
    else printf("\nopération refusée\n");
    cpt1->consulter();
    cout << "********compte Epargne*****************" << endl;
    bool b=cpt2->debiter(new Dollar(10000));
    if (b) printf("\nopération accéptée\n");
    else printf("\nopération refusée\n");
    cpt2->consulter();
    cout << "***************compte Payant*************" << endl;
    bool c=cpt3->debiter(new Dollar(10));
    if (c) printf("\nopération accéptée\n");
    else printf("\nopération refusée\n");
    cpt3->consulter();
}

// Exécuter le programme : Ctrl+F5 ou menu Déboguer > Exécuter sans débogage
// Déboguer le programme : F5 ou menu Déboguer > Démarrer le débogage

// Astuces pour bien démarrer : 
//   1. Utilisez la fenêtre Explorateur de solutions pour ajouter des fichiers et les gérer.
//   2. Utilisez la fenêtre Team Explorer pour vous connecter au contrôle de code source.
//   3. Utilisez la fenêtre Sortie pour voir la sortie de la génération et d'autres messages.
//   4. Utilisez la fenêtre Liste d'erreurs pour voir les erreurs.
//   5. Accédez à Projet > Ajouter un nouvel élément pour créer des fichiers de code, ou à Projet > Ajouter un élément existant pour ajouter des fichiers de code existants au projet.
//   6. Pour rouvrir ce projet plus tard, accédez à Fichier > Ouvrir > Projet et sélectionnez le fichier .sln.
