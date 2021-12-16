#include "pch.h"
#include "Compte.h"
#include "Devise.h"
#include "Client.h"
#include "MAD.h"
#include "Operations.h"
#include "OperationR.h"
#include "OperationV.h"

using namespace Banque;
using namespace std;
int Compte::Compteur = 0;
Devise* Compte::plafond = new MAD(300);

Banque::Compte::Compte(Client*c, Devise*d) :numcompte(++Compteur)
{
	this->titulaire = c;
	this->solde = d;
	//this->historique = vector<Operations>();
	c->addCompte(this);
}

Banque::Compte::Compte(const Compte&c) :numcompte(c.numcompte)
{
	this->titulaire = c.titulaire;
	this->solde = c.solde;
	if (!this->historique.empty())  this->historique.clear();
	this->historique = c.historique;
}



bool Banque::Compte::check_moitie(const Devise& d) const
{
	return *(this->solde) / 2 >= d;
}

bool Banque::Compte::debiter(Devise* M)
{
	if (*(this->solde) >= *M && *M <= *(Compte::plafond))
	{
		*(this->solde) = *(this->solde) - *M;
	
		Operations* p = new OperationR(M, this);
		this->historique.push_back(p);
		return true;
	}
	return false;
}

void Banque::Compte::crediter(Devise* M)
{
	*(this->solde) = *(this->solde) + *M;
	Operations* p = new OperationV(M, this);
	this->historique.push_back(p);
}

bool Banque::Compte::verser(Devise* M, Compte& C)
{
	this->solde->afficher();
	if (this->debiter(M) == true) {
		this->solde->afficher();
		C.crediter(M);
		C.solde->afficher();
		return true;
	}
	return false;
}

void Banque::Compte::consulter() const
{
	cout << "num compte=" << this->numcompte << endl;
	this->solde->afficher();
	cout << "titulaire " << endl;
	this->titulaire->Afficher();
}

Devise& Banque::Compte::pourcentage(double a) const
{
	return this->solde->operator*(a);
}

bool Banque::Compte::checkSup(Devise* s) const
{

	return (*(this->solde) >= *s);
}

Banque::Compte::~Compte()
{
	if (this->titulaire != nullptr && this->solde != nullptr)
	{
		delete this->solde;
		this->solde=0;
		this->titulaire = nullptr;
		for (int i = 0; i < this->historique.size(); i++)
		{
			delete this->historique[i];
			this->historique[i] = 0;
		}
		
	}
}

