#ifndef CONTACT_H
#define CONTACT_H

#include <string>
#include <iostream>

using namespace std;

// Classe représentant un contact
class Contact {
private:
    int id;
    string nom;
    string prenom;
    string email;
    string telephone;
    string ville;

public:
    // Constructeurs
    Contact();
    Contact(int id, const string &nom, const string &prenom, const string &email,
            const string &telephone, const string &ville);

    // Méthodes
    void afficher() const;

    // Getters
    int getId() const;
    const string &getNom() const;
    const string &getPrenom() const;
    const string &getEmail() const;
    const string &getTelephone() const;
    const string &getVille() const;

    // Setters
    void setId(int nouveauId);
    void setNom(const string &nouveauNom);
    void setPrenom(const string &nouveauPrenom);
    void setEmail(const string &nouvelEmail);
    void setTelephone(const string &nouveauTelephone);
    void setVille(const string &nouvelleVille);
};

#endif
