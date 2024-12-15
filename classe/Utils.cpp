#include <fstream>
#include <sstream> // Pour std::istringstream
#include <iostream>

#include "../header/GestionnaireMap.h"

#include "../header/Epice.h"
#include "../header/Fournisseur.h"
namespace Utils
{
    // Fonction pour charger le fichier fournisseurs
    void chargerFichierFournisseur(const string &nomFichier, GestionnaireMap<int, Fournisseur> &listeFournisseurs)
    {
        ifstream fichier(nomFichier);
        if (!fichier)
        {
            throw runtime_error("Impossible de lire le fichier " + nomFichier);
        }

        string ligne;
        while (getline(fichier, ligne))
        {
            stringstream ss(ligne);
            string idStr, nom, prenom, email, telephone;

            // Découpage de la ligne par le séparateur ';'
            getline(ss, idStr, ';');
            getline(ss, nom, ';');
            getline(ss, prenom, ';');
            getline(ss, email, ';');
            getline(ss, telephone, ';');

            int id = stoi(idStr);

            Fournisseur *fournisseur = new Fournisseur(id, nom, prenom, email, telephone);
            listeFournisseurs.ajouter(fournisseur->getId(), *fournisseur);
        }

        fichier.close();
    }

    // Fonction pour charger le fichier epices
    void chargerFichierEpices(const string &nomFichier, GestionnaireMap<int, Epice> &listeEpices, GestionnaireMap<int, Fournisseur> &listeFournisseurs)
    {
        ifstream fichier(nomFichier);
        if (!fichier)
        {
            throw runtime_error("Impossible de lire le fichier " + nomFichier);
        }

        string ligne;
        while (getline(fichier, ligne))
        {
            stringstream ss(ligne);
            string idStr, nom, type, prixStr, quantiteStr, categorie, fournisseursStr;

            // Découpage de la ligne par le séparateur ';'
            getline(ss, idStr, ';');
            getline(ss, nom, ';');
            getline(ss, type, ';');
            getline(ss, prixStr, ';');
            getline(ss, quantiteStr, ';');
            getline(ss, categorie);

            int id = stoi(idStr);
            float prix = stof(prixStr);
            float quantite = stof(quantiteStr);

            Epice *epice = new Epice(id, nom, type, prix, quantite, categorie);

            listeEpices.ajouter(epice->getId(), *epice);
        }

        fichier.close();
    }

    // Afficher l'entete des epices
    void afficherEnteteEpice()
    {
        printf("===== LISTE DES ÉPICES =====\n");
        printf(" ID | Nom             | Type     |  Prix  | Quantité | Catégorie\n");
        printf("----------------------------------------------------------------\n");
    }

    // Afficher tous les epices
    void afficherEpices(const GestionnaireMap<int, Epice> &listeEpices)
    {
        afficherEnteteEpice();
        listeEpices.afficherTous([](const int &id, const Epice &epice)
                                 { epice.afficher(); });
    }

    // Afficher l'entete des fournisseurs
    void afficherEnteteFournisseur()
    {
        printf("===== LISTE DES FOURNISSEURS =====\n");
        printf(" ID | Nom          | Prénom       | Couriel                      | Téléphone\n");
        printf("----------------------------------------------------------------------------\n");
    }

    // Afficher tous les fournisseurs
    void afficherFournisseurs(const GestionnaireMap<int, Fournisseur> &listeFournisseurs)
    {
        afficherEnteteFournisseur();
        listeFournisseurs.afficherTous([](const int &id, const Fournisseur &fournisseur)
                                       { fournisseur.afficher(); });
    }

    //* Épice

    // Ajouter une Épice
    void ajouterEpice(GestionnaireMap<int, Epice> &listeEpices)
    {
        int id;
        string nom, type, categorie;
        double prix, quantite;

        cout << "ID : ";
        cin >> id;
        cin.ignore(); // Consomme le '\n'
        cout << "Nom : ";
        getline(cin, nom);
        cout << "Type : ";
        getline(cin, type);
        cout << "Prix : ";
        cin >> prix;
        cin.ignore();
        cout << "Quantité : ";
        cin >> quantite;
        cin.ignore();
        cout << "Catégorie : ";
        getline(cin, categorie);

        try
        {
            listeEpices.ajouter(id, Epice(id, nom, type, prix, quantite, categorie));
            cout << "Épice ajouté avec succès !" << endl;
        }
        catch (const std::exception &e)
        {
            std::cerr << e.what() << '\n';
        }
    }

    // Suprimer une Épice
    void supprimerEpice(GestionnaireMap<int, Epice> &listeEpices)
    {
        int id;
        cout << "ID de l'épice à supprimer : ";
        cin >> id;

        try
        {
            listeEpices.supprimer(id);
            cout << "Épice supprimé avec succès !" << endl;
        }
        catch (const std::exception &e)
        {
            std::cerr << e.what() << '\n';
        }
    }

    // Afficher l'Épice avec le prix le plus élevé
    void afficherEpicePrixMax(GestionnaireMap<int, Epice> &listeEpices)
    {
        // Comparateur pour trouver l'élément avec le prix maximum
        auto comparateur = [](const pair<int, Epice> &a, const pair<int, Epice> &b)
        {
            return a.second.getPrix() < b.second.getPrix(); // Compare les prix
        };

        try
        {
            int idEpice = listeEpices.trouverMax(comparateur);
            Epice epicePrixMax = listeEpices.lire(idEpice);

            cout << "L'épice avec le prix le plus élevé : " << endl;
            afficherEnteteEpice();
            epicePrixMax.afficher();
        }
        catch (const runtime_error &e)
        {
            cout << "Erreur : " << e.what() << endl;
        }
    }

    void afficherPrixMoyenEpice(const GestionnaireMap<int, Epice> &listeEpices)
    {
        if (listeEpices.taille() == 0)
            throw runtime_error("Aucune épice dans la liste !");

        // Convertir explicitement le lambda en std::function
        function<double(const double &, const int &, const Epice &)> accumulateur =
            [](const double &somme, const int &, const Epice &epice) -> double
        {
            return somme + epice.getPrix();
        };

        // Spécifiez explicitement le type attendu pour le lambda
        double sommePrix = listeEpices.parcourirAvecAccumulateur(0.0, accumulateur);

        printf("Le prix moyen des épices est de %.2f$\n", sommePrix / listeEpices.taille());
    }

    //* ---

    //* Fournisseur

    // Ajouter un Fournisseur
    void ajouterFournisseur(GestionnaireMap<int, Fournisseur> &listeFournisseurs)
    {
        int id;
        string nom, prenom, courriel, telephone;

        cout << "ID : ";
        cin >> id;
        cin.ignore(); // Consomme le '\n'
        cout << "Nom : ";
        getline(cin, nom);
        cout << "Prénom : ";
        getline(cin, prenom);
        cout << "Courriel : ";
        getline(cin, courriel);
        cout << "Téléphone : ";
        getline(cin, telephone);

        try
        {
            listeFournisseurs.ajouter(id, Fournisseur(id, nom, prenom, courriel, telephone));
            cout << "Fournisseur ajouté avec succès !" << endl;
        }
        catch (const std::exception &e)
        {
            std::cerr << e.what() << '\n';
        }
    }

    // Suprimer un Fournisseur
    void supprimerFournisseur(GestionnaireMap<int, Fournisseur> &listeFournisseurs)
    {
        int id;
        cout << "ID du fournisseur à supprimer : ";
        cin >> id;
        try
        {
            listeFournisseurs.supprimer(id);
            cout << "Fournisseur supprimé avec succès !" << endl;
        }
        catch (const std::exception &e)
        {
            std::cerr << e.what() << '\n';
        }
    }

    // Rechercher un fournisseur par courriel
    void rechercherFournisseurParCourriel(const GestionnaireMap<int, Fournisseur> &listeFournisseurs)
    {
        string courriel;
        cout << "Courriel : ";
        cin >> courriel;
        // getline(cin, courriel);

        cout << "\nFournisseur(s) avec comme courriel : " << courriel << endl;
        Utils::afficherEnteteFournisseur();
        listeFournisseurs.afficherTous([&courriel](const int &id, const Fournisseur &fournisseur)
                                       {
        if (fournisseur.getCourriel() == courriel) {
            fournisseur.afficher();
        } });
    }

    //* ---

    //* Autres

    void afficherNbEpiceEtFournisseur(GestionnaireMap<int, Epice> &listeEpices, GestionnaireMap<int, Fournisseur> &listeFournisseurs)
    {
        cout << "Il y a " << listeEpices.taille() << " Épice(s)\n";
        cout << "Il y a " << listeFournisseurs.taille() << " Fournisseur(s)\n";
    }

    //* ---

    // ******** BONUS ********

    void ajouterRelationEpiceFournisseur(GestionnaireMap<int, Epice> &listeEpices, GestionnaireMap<int, Fournisseur> &listeFournisseurs)
    {
        int idEpice, idFournisseur;

        cout << "Entrez l'ID de l'épice : ";
        cin >> idEpice;
        cout << "Entrez l'ID du fournisseur : ";
        cin >> idFournisseur;

        try
        {
            // Vérifier si l'épice et le fournisseur existent
            Epice epice = listeEpices.lire(idEpice);
            Fournisseur fournisseur = listeFournisseurs.lire(idFournisseur);

            // Ajouter la relation dans les deux sens
            listeEpices.ajouterRelation(idEpice, idFournisseur);
            listeFournisseurs.ajouterRelation(idEpice, idFournisseur);

            cout << "Relation ajoutée entre l'épice et le fournisseur." << endl;
        }
        catch (const runtime_error &e)
        {
            cout << "Erreur : " << e.what() << endl;
        }
    }

    void afficherRelations(GestionnaireMap<int, Epice> &listeEpices)
    {
        listeEpices.afficherRelationEpicesFournisseurs();
    }

    // ***

};