#ifndef GESTIONNAIRE_MAP_H
#define GESTIONNAIRE_MAP_H

#include <map>
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
};

#endif
