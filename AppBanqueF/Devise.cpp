#include "pch.h"
#include "Devise.h"
#include "MAD.h"
#include "Euro.h"	
#include "Dollar.h"	
#include  <iostream>
#include <typeinfo>
using namespace std;
using namespace Banque;
Devise::Devise(double val)
{
	this->val = val;
}

Devise& Devise::operator+(const Devise& M) const
{
	Devise& res = this->convert_to_my_type(M);
	Devise& tmp2 =* Creer_devise(res.val + this->val);
	delete &res;
	return tmp2;
}

Devise& Devise::operator-(const Devise& M) const
{
	Devise& res = this->convert_to_my_type(M);
	Devise& tmp2 = *Creer_devise(this->val- res.val);
	delete& res;
	return tmp2;
}

Devise& Banque::Devise::operator*(const Devise& M) const
{
	Devise& res = this->convert_to_my_type(M);
	Devise& tmp2 = *Creer_devise(this->val * res.val);
	delete& res;
	return tmp2;
}

Devise& Banque::Devise::operator*(double val) const
{
	return *Creer_devise(this->val*val);
}

Devise& Banque::Devise::operator/(double val) const
{
	return *Creer_devise(this->val / val);
}

bool Devise::operator<=(const Devise& M) const
{
	Devise& res = this->convert_to_my_type(M); 
	bool a= this->val <= res.val;
	delete& res;
	return a;
}

bool Devise::operator>=(const Devise& M) const
{
	Devise& res = this->convert_to_my_type(M);
	bool a = this->val >= res.val;
	delete& res;
	return a;
}

void Devise::afficher() const
{
	cout << "le solde est : " << this->val;
}

double Banque::Devise::convert(double indice) const
{
	return this->val*indice;
}

Devise& Banque::Devise::convert_to_my_type(const Devise& d) const
{
	if (typeid(*this) == typeid(MAD)) return d.convert_to_mad();
	if (typeid(*this) == typeid(Dollar)) return d.convert_to_dollar();
	if (typeid(*this) == typeid(Euro)) return d.convert_to_euro();
}



