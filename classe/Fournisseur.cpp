#include <string>
#include <iostream>

#include "../header/Fournisseur.h"

using namespace std;

// Constructeurs
Fournisseur::Fournisseur() : id(0), nom(""), prenom(""), courriel(""), telephone("") {}
Fournisseur::Fournisseur(int id, string nom, string prenom, string courriel, string telephone)
    : id(id), nom(nom), prenom(prenom), courriel(courriel), telephone(telephone) {};

// Getters - Setters
int Fournisseur::getId() const { return this->id; }
void Fournisseur::setID(int id) { this->id = id; }

string Fournisseur::getNom() const { return this->nom; }
void Fournisseur::setNom(string nom) { this->nom = nom; }

string Fournisseur::getPrenom() const { return this->prenom; }
void Fournisseur::setPrenom(string prenom) { this->prenom = prenom; }

string Fournisseur::getCourriel() const { return this->courriel; }
void Fournisseur::setCourriel(string courriel) { this->courriel = courriel; }

string Fournisseur::getTelephone() const { return this->telephone; }
void Fournisseur::setTelephone(string telephone) { this->telephone = telephone; }

// Afficher les informations du fournisseur
//! Fix the use of special character
void Fournisseur::afficher() const
{
    //* c_string() converti l'objet en pointeur (Néccessaire lorsque printf est utilisé)
    printf("%-3d | %-12s | %-12s | %-28s | %-s\n", this->id, this->nom.c_str(), this->prenom.c_str(), this->courriel.c_str(), this->telephone.c_str());
}