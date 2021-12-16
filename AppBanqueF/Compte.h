#pragma once
#include"Client.h"
#include "Devise.h"
#include "Operations.h"
#include <iostream>
namespace Banque {
	class Compte
	{
	private:
		const int numcompte;
		static int Compteur;
		Client* titulaire; 
		Devise* solde;
		static Devise* plafond;
		vector<Operations*> historique;
	public:
		Compte(Client*, Devise*); // avec parametres
		Compte(const Compte&);
		Compte operator=(const Compte&)=delete;
		bool check_moitie(const Devise& d) const;
		virtual bool debiter(Devise* M)=0;
		virtual void crediter(Devise* M);
		virtual bool verser(Devise* M, Compte& C);
		void consulter()const;
		virtual ~Compte();
		protected: Devise& pourcentage(double a) const;
		protected: bool checkSup(Devise* s) const;


	};

};
