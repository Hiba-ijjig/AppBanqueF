#include "pch.h"
#include "CompteCourant.h"

Banque::CompteCourant::CompteCourant(Client* c, Devise* s, Devise* d): Compte(c, s) {
	assert(*s >= *d);
	this->Decouvert = d;
}

bool Banque::CompteCourant::debiter(Devise* M)
{
	if (this->checkSup(&(*M + *(this->Decouvert))))
		return this->Compte::debiter(M);
	return false;
}
