#pragma once
namespace Banque {
	class MAD;
	class Euro;
	class Dollar;
	class Devise
	{
	private:
		double val;
	public:
		Devise(double val);
		Devise& operator+(const Devise& M) const;
		Devise& operator-(const Devise& M) const;
		Devise& operator*(const Devise& M) const;
		Devise& operator*(double val) const;
		Devise& operator/(double val) const;
		bool operator<=(const Devise& M)const;
		bool operator>=(const Devise& M) const;
		virtual void afficher() const;
		virtual MAD& convert_to_mad()const=0;
		virtual Dollar& convert_to_dollar()const =0;
		virtual Euro& convert_to_euro()const =0;
		virtual Devise* Creer_devise(double val)const =0;
		double convert(double indice)const;
		Devise& convert_to_my_type(const Devise& d)const;
	};
};
