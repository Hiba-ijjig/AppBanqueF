#pragma once
#include "Compte.h"
#include <assert.h>
namespace Banque {
	class CompteCourant : public Compte
	{

	public:
		CompteCourant(Client*, Devise*, Devise*);
		bool debiter(Devise* M);

	private:
		Devise* Decouvert;
	};

};

