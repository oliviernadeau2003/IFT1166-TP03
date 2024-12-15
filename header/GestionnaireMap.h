#ifndef GESTIONNAIRE_MAP_H
#define GESTIONNAIRE_MAP_H

#include <map>
#include <vector>
#include <stdexcept>
#include <functional>
#include <algorithm> // max_element function

using namespace std;

// Classe générique pour gérer une map
template <typename Cle, typename Valeur>
class GestionnaireMap
{
private:
    map<Cle, Valeur> elements; // Conteneur map pour stocker les éléments

public:
    // Ajouter un élément
    void ajouter(const Cle &cle, const Valeur &valeur)
    {
        if (elements.find(cle) != elements.end())
        {
            throw runtime_error("Clé déjà existante !");
        }
        elements[cle] = valeur;
    }

    // Supprimer un élément
    void supprimer(const Cle &cle)
    {
        if (elements.find(cle) == elements.end())
        {
            throw runtime_error("Clé inexistante !");
        }
        elements.erase(cle);
    }

    // Lire un élément
    Valeur lire(const Cle &cle) const
    {
        if (elements.find(cle) == elements.end())
        {
            throw runtime_error("Clé inexistante !");
        }
        return elements.at(cle);
    }

    // Afficher tous les éléments
    void afficherTous(function<void(const Cle &, const Valeur &)> affichage) const
    {
        for (const auto &pair : elements)
        {
            affichage(pair.first, pair.second);
        }
    }

    // Obtenir la taille de la map
    size_t taille() const
    {
        return elements.size();
    }

    // Trouver max des élément du map basé sur un Comparator
    template <typename Compare>
    Cle trouverMax(Compare comparateur) const
    {
        if (elements.empty())
            throw runtime_error("Map vide !");

        // Utilise std::max_element avec le comparateur fourni
        auto it = max_element(elements.begin(), elements.end(), comparateur);
        return it->first; // Retourne la clé de l'élément avec la valeur maximale
    }

    template <typename Accumulateur>
    Accumulateur parcourirAvecAccumulateur(Accumulateur valeurInitiale, function<Accumulateur(const Accumulateur &, const Cle &, const Valeur &)> operation) const
    {
        Accumulateur resultat = valeurInitiale;

        for (const auto &pair : elements)
        {
            resultat = operation(resultat, pair.first, pair.second);
        }

        return resultat;
    }

    // ******** BONUS ********
    map<int, vector<int>> relationEpiceFournisseur; // Cle: ID de l'épice, Valeur: Liste des IDs de fournisseurs
    map<int, vector<int>> relationFournisseurEpice; // Cle: ID du fournisseur, Valeur: Liste des IDs d'épices

    // Ajouter une relation entre un fournisseur et une épice
    void ajouterRelation(int idEpice, int idFournisseur)
    {
        relationEpiceFournisseur[idEpice].push_back(idFournisseur);
        relationFournisseurEpice[idFournisseur].push_back(idEpice);
    }

    // Afficher la relation entre les épices et leurs fournisseurs
    void afficherRelationEpicesFournisseurs()
    {
        cout << "Relation entre les épices et leurs fournisseurs :\n";
        for (const auto &pair : relationEpiceFournisseur)
        {
            cout << "Épice ID " << pair.first << " est fournie par : ";
            for (int fournisseurId : pair.second)
            {
                cout << fournisseurId << " ";
            }
            cout << endl;
        }

        cout << "\nRelation entre les fournisseurs et les épices :\n";
        for (const auto &pair : relationFournisseurEpice)
        {
            cout << "Fournisseur ID " << pair.first << " fournit : ";
            for (int epiceId : pair.second)
            {
                cout << epiceId << " ";
            }
            cout << endl;
        }
    }
    // ***
};

#endif
