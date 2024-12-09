// Avec les templates, les méthodes de la classe doivent effectivement être définies directement dans le fichier en-tête (.h).
// Cela signifie que non seulement la déclaration, mais aussi les définitions des méthodes doivent être incluses
// dans le même fichier.

#ifndef GESTIONNAIRE_MAP_H
#define GESTIONNAIRE_MAP_H

#include <map>
#include <stdexcept>
#include <functional>

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
};

#endif
