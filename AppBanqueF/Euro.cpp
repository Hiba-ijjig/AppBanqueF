#include "pch.h"
#include "Euro.h"
#include "MAD.h"
#include "Dollar.h"
#include<iostream>
using namespace std;
using namespace Banque;
double Euro::to_dollar = 1.13;
double Euro::to_mad = 11;


Banque::Euro::Euro(double val):Devise(val)
{

}

MAD& Banque::Euro::convert_to_mad() const
{
	MAD* tmp = new MAD(convert(this->to_mad));
	return *tmp;
}

Dollar& Banque::Euro::convert_to_dollar() const
{
	Dollar* tmp = new Dollar(convert(to_dollar));
	return *tmp;
}

Euro& Banque::Euro::convert_to_euro() const
{
	Euro* tmp = new Euro(convert(1));
	return *tmp;
}

Devise* Banque::Euro::Creer_devise(double val) const
{
	return new Euro(val);
}
void Banque::Euro::afficher() const
{
	this->Devise::afficher();
	cout << "Euro" << endl;
}

