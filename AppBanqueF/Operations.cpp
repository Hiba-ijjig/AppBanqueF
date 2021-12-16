#include "pch.h"
#include "Operations.h"
using namespace Banque;
int Operations::cpt = 0;
Banque::Operations::Operations(Devise* m, Compte* c) :num(++cpt)
{
	this->montant = m;
	this->c = c;
}

Banque::Operations::~Operations()
{
	c = nullptr;
	delete this->montant;
	this->montant = 0;
}
