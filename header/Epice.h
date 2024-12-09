#ifndef EPICE_H
#define EPICE_H

#include <iostream>
#include <string>

using namespace std;

class Epice
{
private:
    int id;
    string nom;
    string type;
    double prix;
    double quantite;
    string categorie;

public:
    // Constructeurs de la classe Epice
    Epice();
    Epice(int id, string nom, string type, double prix, double quantite, string categorie);

    // Getters et Setters
    int getId() const;
    void setId(int id);

    string getNom() const;
    void setNom(const string &nom);

    string getType() const;
    void setType(const string &type);

    double getPrix() const;
    void setPrix(double prix);

    double getQuantite() const;
    void setQuantite(double quantite);

    string getCategorie() const;
    void setCategorie(const string &categorie);

    // Afficher les informations de l'épice
    void afficher() const;
};

#endif // EPICE_H
