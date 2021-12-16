#include "pch.h"
#include "ComptePayant.h"

Banque::ComptePayant::ComptePayant(Client* c, Devise* s, Devise* d) :CompteCourant(c, s, d)
{
}

bool Banque::ComptePayant::debiter(Devise* M)
{
	Devise& tmp =*M->Creer_devise(0.05);
	tmp.operator*(*M);
	return this->Compte::debiter(&tmp.operator+(*M));
}

void Banque::ComptePayant::crediter(Devise* M)
{
	Devise& tmp = *M->Creer_devise(0.05);
	tmp.operator*(*M);
	this->Compte::crediter(&tmp.operator-(*M));
}

bool Banque::ComptePayant::verser(Devise* M, Compte& C)
{
	Devise& tmp = *M->Creer_devise(0.05);
	tmp.operator*(*M);
	return this->Compte::verser(&tmp.operator+(*M),C);
}
