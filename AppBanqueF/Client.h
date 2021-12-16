#pragma once
#include <iostream>
#include  <vector>
using namespace std;


namespace Banque {
	class Compte;
	class Client
	{
		// attributs
	private:
		string nom;
		string prenom;
		string adresse;
		vector<Compte*> lstComptes; //composition

	public:
		Client(string, string, string);
		void Afficher()const;
		void addCompte(Compte* c);
		~Client();

	};
};
