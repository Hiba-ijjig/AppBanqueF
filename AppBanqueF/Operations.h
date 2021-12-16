#pragma once
#include<iostream> 
using namespace std;
namespace Banque {
	class  Devise;
	class  Compte;
	class Operations
	{
	private:
		const int num;
		static int cpt;
		Devise* montant;
		string d;
		Compte* c;
	public:
		Operations(Devise* d, Compte* c);
		~Operations();
	};
};
