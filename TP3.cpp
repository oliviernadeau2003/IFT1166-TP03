#include <stdio.h>
#include <iostream>

#include "classe/Utils.cpp" // namespace

#include "header/Epice.h"
#include "header/Fournisseur.h"
#include "header/GestionnaireMap.h"

using namespace std;

int main()
{
    system("chcp 65001 > NUL"); // Set l'encodeur a UTF-8 pour lire et écrire des charactère spéciaux (... > NUL permet de 'suprimer' l'output de la commande)

    const string PATHFICHIEREPICE = "./data/epices.txt";
    const string PATHFICHIERFOURNISSEUR = "./data/fournisseurs.txt";

    // Initialisation de la liste
    GestionnaireMap<int, Epice> listeEpices;
    GestionnaireMap<int, Fournisseur> listeFournisseurs;

    Utils::chargerFichierFournisseur(PATHFICHIERFOURNISSEUR, listeFournisseurs);
    Utils::chargerFichierEpices(PATHFICHIEREPICE, listeEpices, listeFournisseurs);

    cout << "Données chargées avec succès.\n\n";

    Utils::afficherEpices(listeEpices);

    // cout << "\nListe Fournisseurs :\n";
    // listeFournisseurs.afficherTous([](const int &id, const Fournisseur &fournisseur)
    //                                { fournisseur.afficher(); });

    system("pause");
    return 0;
}