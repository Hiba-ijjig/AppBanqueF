#include "pch.h"
#include "Dollar.h"
#include "MAD.h"
#include "Euro.h"
#include<iostream>
using namespace std;
using namespace Banque;
double Dollar::to_euro = 0.9;
double Dollar::to_mad = 9;


Banque::Dollar::Dollar(double val):Devise(val)
{
}

MAD& Banque::Dollar::convert_to_mad() const
{
	MAD* tmp = new MAD(convert(this->to_euro));
	return *tmp;
}

Dollar& Banque::Dollar::convert_to_dollar() const
{
	Dollar* tmp = new Dollar(convert(1));
	return *tmp;
}

Euro& Banque::Dollar::convert_to_euro() const
{
	Euro* tmp = new Euro(convert(this->to_euro));
	return *tmp;
}


Devise* Banque::Dollar::Creer_devise(double val) const
{
	return new Dollar(val);
}

void Banque::Dollar::afficher() const
{
	this->Devise::afficher();
	cout << "Dollar" << endl;
}
