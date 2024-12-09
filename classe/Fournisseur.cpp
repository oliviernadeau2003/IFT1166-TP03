#include "../header/Fournisseur.h"

#include <string>
#include <iostream>
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

void Fournisseur::afficher() const
{
    cout << "ID: " << this->id << ", Nom: " << this->nom << ", Prénom: " << this->prenom << ", Courriel: " << this->courriel << ", Téléphone: " << this->telephone << "\n";
}