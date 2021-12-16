#pragma once
#include "Compte.h"
namespace Banque {
	class CompteEpargne : public Compte
	{
	public:
		CompteEpargne(Client* c, Devise* s, double t);
		void calculInteret();
		 bool debiter(Devise* M) override;
	private:
		double tauxInteret;
	};
};
