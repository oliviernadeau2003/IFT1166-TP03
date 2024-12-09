#include "Contact.h"

// Constructeur par défaut
Contact::Contact()
    : id(0), nom(""), prenom(""), email(""), telephone(""), ville("") {}

// Constructeur paramétré
Contact::Contact(int id, const string &nom, const string &prenom, const string &email,
                 const string &telephone, const string &ville)
    : id(id), nom(nom), prenom(prenom), email(email), telephone(telephone), ville(ville) {}

// Afficher un contact
void Contact::afficher() const
{
    cout << "ID : " << id
         << " | Nom : " << nom
         << " | Prénom : " << prenom
         << " | Email : " << email
         << " | Téléphone : " << telephone
         << " | Ville : " << ville << endl;
}

// Getters
int Contact::getId() const { return id; }
const string &Contact::getNom() const { return nom; }
const string &Contact::getPrenom() const { return prenom; }
const string &Contact::getEmail() const { return email; }
const string &Contact::getTelephone() const { return telephone; }
const string &Contact::getVille() const { return ville; }

// Setters
void Contact::setId(int nouveauId) { id = nouveauId; }
void Contact::setNom(const string &nouveauNom) { nom = nouveauNom; }
void Contact::setPrenom(const string &nouveauPrenom) { prenom = nouveauPrenom; }
void Contact::setEmail(const string &nouvelEmail) { email = nouvelEmail; }
void Contact::setTelephone(const string &nouveauTelephone) { telephone = nouveauTelephone; }
void Contact::setVille(const string &nouvelleVille) { ville = nouvelleVille; }

