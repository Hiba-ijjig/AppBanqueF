#include "pch.h"
#include "Client.h"

Banque::Client::Client(string n, string p, string ad)
{
	this->nom = n;
	this->prenom = p;
	this->adresse = ad;
}

void Banque::Client::Afficher() const
{
	cout << "nom :" << this->nom << "\n" << "prenom:" << this->prenom << "\n" << "Adresse:" << this->adresse << endl;

}

void Banque::Client::addCompte(Compte* c)
{
	this->lstComptes.push_back(c);
}

Banque::Client::~Client()
{
	for (int i = 0; i < this->lstComptes.size(); i++)
	{
		delete this->lstComptes[i];
		this->lstComptes[i] = 0;
	}
}
