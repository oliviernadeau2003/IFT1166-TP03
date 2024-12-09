#ifndef FOURNISSEUR_H
#define FOURNISSEUR_H

#include <string>
using namespace std;

class Fournisseur
{
private:
    int id;
    string nom;
    string prenom;
    string courriel;
    string telephone;

public:
    // Constructeurs
    Fournisseur();
    Fournisseur(int id, string nom, string prenom, string courriel, string telephone);

    // Getters et Setters
    int getId() const;
    void setID(int id);

    string getNom() const;
    void setNom(string nom);

    string getPrenom() const;
    void setPrenom(string prenom);

    string getCourriel() const;
    void setCourriel(string courriel);

    string getTelephone() const;
    void setTelephone(string telephone);

    // Afficher les informations du fournisseur
    void afficher();
};

#endif // FOURNISSEUR_H
