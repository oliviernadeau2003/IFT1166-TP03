#include <iostream>
#include <fstream>
#include <sstream>
#include "Contact.h"
#include "GestionnaireMap.h"

using namespace std;

// Fonction pour lire les contacts depuis un fichier
void chargerContacts(const string &fichier, GestionnaireMap<int, Contact> &gestionnaire)
{
    ifstream fichierEntree(fichier);
    if (!fichierEntree.is_open())
    {
        throw runtime_error("Impossible de lire le fichier " + fichier);
    }

    string ligne;
    while (getline(fichierEntree, ligne))
    {
        stringstream fluxLigne(ligne);
        string idStr, nom, prenom, email, telephone, ville;

        getline(fluxLigne, idStr, ';');
        getline(fluxLigne, nom, ';');
        getline(fluxLigne, prenom, ';');
        getline(fluxLigne, email, ';');
        getline(fluxLigne, telephone, ';');
        getline(fluxLigne, ville, ';');

        int id = stoi(idStr);
        gestionnaire.ajouter(id, Contact(id, nom, prenom, email, telephone, ville));
    }
}

// Fonction pour afficher tous les contacts
void afficherContacts(const GestionnaireMap<int, Contact> &gestionnaire)
{
    cout << "===== LISTE DES CONTACTS =====" << endl;
    cout << "ID   | Nom       | Prénom    | Email                     | Téléphone" << endl;
    cout << "----------------------------------------------------------------------" << endl;
    gestionnaire.afficherTous([](const int &id, const Contact &contact)
                              { contact.afficher(); });
}

// Fonction pour ajouter un contact
void ajouterContact(GestionnaireMap<int, Contact> &gestionnaire)
{
    int id;
    string nom, prenom, email, telephone, ville;

    cout << "ID : ";
    cin >> id;
    cin.ignore(); // Consomme le '\n'
    cout << "Nom : ";
    getline(cin, nom);
    cout << "Prénom : ";
    getline(cin, prenom);
    cout << "Email : ";
    getline(cin, email);
    cout << "Téléphone : ";
    getline(cin, telephone);
    cout << "Ville : ";
    getline(cin, ville);

    gestionnaire.ajouter(id, Contact(id, nom, prenom, email, telephone, ville));
    cout << "Contact ajouté avec succès !" << endl;
}

// Fonction pour rechercher des contacts par ville
void rechercherContactsParVille(const GestionnaireMap<int, Contact> &gestionnaire)
{
    string ville;
    cout << "Ville : ";
    cin.ignore(); // Consomme le '\n'
    getline(cin, ville);

    cout << "\nContacts dans la ville : " << ville << endl;
    gestionnaire.afficherTous([&ville](const int &id, const Contact &contact)
                              {
        if (contact.getVille() == ville) {
            contact.afficher();
        } });
}

// Fonction pour supprimer un contact
void supprimerContact(GestionnaireMap<int, Contact> &gestionnaire)
{
    int id;
    cout << "ID du contact à supprimer : ";
    cin >> id;

    gestionnaire.supprimer(id);
    cout << "Contact supprimé avec succès !" << endl;
}

// Fonction pour afficher le menu
void afficherMenu()
{
    cout << "\n====== MENU GESTION CONTACTS ======" << endl;
    cout << "1. Afficher tous les contacts" << endl;
    cout << "2. Ajouter un contact" << endl;
    cout << "3. Rechercher des contacts par ville" << endl;
    cout << "4. Supprimer un contact par ID" << endl;
    cout << "5. Quitter" << endl;
    cout << "===================================" << endl;
    cout << "Entrez votre choix : ";
}

int main()
{
    GestionnaireMap<int, Contact> gestionnaireContacts;
    const string fichierContacts = "src/donnees/contacts.txt";

    try
    {
        // Charger les contacts depuis le fichier
        chargerContacts(fichierContacts, gestionnaireContacts);
        cout << "Contacts chargés avec succès !" << endl;

        int choix;
        do
        {
            afficherMenu();
            cin >> choix;

            switch (choix)
            {
            case 1:
                afficherContacts(gestionnaireContacts);
                break;
            case 2:
                ajouterContact(gestionnaireContacts);
                break;
            case 3:
                rechercherContactsParVille(gestionnaireContacts);
                break;
            case 4:
                supprimerContact(gestionnaireContacts);
                break;
            case 5:
                cout << "Au revoir !" << endl;
                break;
            default:
                cout << "Choix invalide, veuillez réessayer." << endl;
            }
        } while (choix != 5);
    }
    catch (const exception &e)
    {
        cerr << "Erreur : " << e.what() << endl;
    }

    return 0;
}
