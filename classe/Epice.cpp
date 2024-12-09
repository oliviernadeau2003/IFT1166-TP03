#include "../header/Epice.h"

#include <iomanip> // Pour std::fixed et std::setprecision
#include <iostream>

using namespace std;

// Constructeurs
Epice::Epice() : id(0), nom(""), type(""), prix(0.0), quantite(0.0), categorie("") {}

Epice::Epice(int id, string nom, string type, double prix, double quantite, string categorie)
    : id(id), nom(nom), type(type), prix(prix), quantite(quantite), categorie(categorie) {}

// Getters et Setters
int Epice::getId() const { return this->id; }
void Epice::setId(int id) { this->id = id; }

string Epice::getNom() const { return this->nom; }
void Epice::setNom(const string &nom) { this->nom = nom; }

string Epice::getType() const { return this->type; }
void Epice::setType(const string &type) { this->type = type; }

double Epice::getPrix() const { return this->prix; }
void Epice::setPrix(double prix) { this->prix = prix; }

double Epice::getQuantite() const { return this->quantite; }
void Epice::setQuantite(double quantite) { this->quantite = quantite; }

string Epice::getCategorie() const { return this->categorie; }
void Epice::setCategorie(const string &categorie) { this->categorie = categorie; }

// Afficher les informations de l'épice
void Epice::afficher() const
{
#include <iostream>
#include <iomanip> // Pour std::fixed et std::setprecision

    std::cout << "ID: " << this->id
              << ", Nom: " << this->nom
              << ", Type: " << this->type
              << ", Prix: " << std::fixed << std::setprecision(2) << this->prix << "$"
              << ", Quantité: " << this->quantite
              << ", Catégorie: " << this->categorie
              << "\n";
}