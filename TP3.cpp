#include <stdio.h>
#include <iostream>

#include "classe/Utils.cpp" // namespace

#include "header/Epice.h"
#include "header/Fournisseur.h"
#include "header/GestionnaireMap.h"

using namespace std;

void afficherMenu()
{
    cout << "\n================= MENU PRINCIPAL =================" << endl;

    cout << "1. Ajouter une nouvelle épice" << endl;
    cout << "2. Afficher toutes les épices" << endl;
    cout << "3. Supprimer une épice" << endl;
    cout << "4. Rechercher un fournisseur par courriel" << endl;
    cout << "5. Supprimer un fournisseur" << endl;
    cout << "6. Afficher tous les fournisseurs" << endl;
    cout << "7. Afficher le nombre total d’épices et de fournisseurs" << endl;
    cout << "8. Afficher l’épice avec le prix le plus élevé" << endl;
    cout << "9. Afficher la moyenne des prix des épices" << endl;
    cout << "10. Quitter" << endl;

    cout << "==================================================" << endl;
    cout << "Entrez votre choix : ";
}

int main()
{
    system("chcp 65001 > NUL"); // Set l'encodeur a UTF-8 pour lire et écrire des charactère spéciaux (... > NUL permet de 'suprimer' l'output de la commande)

    const string PATHFICHIEREPICE = "./data/epices.txt";
    const string PATHFICHIERFOURNISSEUR = "./data/fournisseurs.txt";

    // Initialisation de la liste
    GestionnaireMap<int, Epice> listeEpices;
    GestionnaireMap<int, Fournisseur> listeFournisseurs;

    try
    {
        // Charger les fichiers de données
        Utils::chargerFichierFournisseur(PATHFICHIERFOURNISSEUR, listeFournisseurs);
        Utils::chargerFichierEpices(PATHFICHIEREPICE, listeEpices, listeFournisseurs);
        cout << "Données chargées avec succès.\n\n";

        int choix;
        while (choix != 10)
        {
            afficherMenu();
            cin >> choix;
            switch (choix)
            {
            case 1:
                Utils::ajouterEpice(listeEpices);
                break;
            case 2:
                Utils::afficherEpices(listeEpices);
                break;
            case 3:
                Utils::supprimerEpice(listeEpices);
                break;
            case 4:
                Utils::rechercherFournisseurParCourriel(listeFournisseurs);
                break;
            case 5:
                Utils::supprimerFournisseur(listeFournisseurs);
                break;
            case 6:
                Utils::afficherFournisseurs(listeFournisseurs);
                break;
            case 7:
                Utils::afficherNbEpiceEtFournisseur(listeEpices, listeFournisseurs);
                break;
            case 8:
                Utils::afficherEpicePrixMax(listeEpices);
                break;
            case 9:
                Utils::afficherPrixMoyenEpice(listeEpices);
                break;
            case 10:
                cout << "Au revoir !" << endl;
                break;
            default:
                cout << "Choix invalide, veuillez réessayer." << endl;
            }
            system("pause");
            system("cls"); // Clear l'affichage
        }
    }
    catch (const exception &e)
    {
        cerr << "Erreur : " << e.what() << endl;
        system("pause");
    }

    return 0;
}