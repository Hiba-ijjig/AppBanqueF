#include "pch.h"
#include "MAD.h"
#include "Dollar.h"
#include "Euro.h"
#include<iostream>
using namespace std;
using namespace Banque;
double MAD::to_euro = 0.09;
double MAD::to_dollar = 0.1;

Banque::MAD::MAD(double val) :Devise(val)
{
}

MAD& Banque::MAD::convert_to_mad() const
{
	MAD* tmp = new MAD(convert(1));
	return *tmp;
}

Dollar& Banque::MAD::convert_to_dollar() const
{
	Dollar* tmp = new Dollar(convert(to_dollar));
	return *tmp;
}

Euro& Banque::MAD::convert_to_euro() const
{
	Euro* tmp = new Euro(convert(to_euro));
	return *tmp;
}


Devise* Banque::MAD::Creer_devise(double val) const
{
	return new MAD(val);
}

void Banque::MAD::afficher() const
{
	this->Devise::afficher();
	cout << "MAD" << endl;
}