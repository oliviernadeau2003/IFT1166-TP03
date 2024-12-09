#include <fstream>
#include <sstream> // Pour std::istringstream
#include <iostream>

#include "../header/GestionnaireMap.h"

#include "../header/Epice.h"
#include "../header/Fournisseur.h"

namespace Utils
{
    void chargerFichierFournisseur(const string &nomFichier, GestionnaireMap<int, Fournisseur> &listeFournisseurs)
    {
        ifstream fichier(nomFichier);
        if (!fichier)
        {
            cerr << "Erreur : Ouverture du fichier '" << nomFichier << "' impossible." << endl;
            return;
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

    void chargerFichierEpices(const string &nomFichier, GestionnaireMap<int, Epice> &listeEpices, GestionnaireMap<int, Fournisseur> &listeFournisseurs)
    {
        ifstream fichier(nomFichier);
        if (!fichier)
        {
            cerr << "Erreur : Ouverture du fichier '" << nomFichier << "' impossible." << endl;
            return;
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
};