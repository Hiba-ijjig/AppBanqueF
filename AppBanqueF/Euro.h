#pragma once
#include "Devise.h"
namespace Banque {
    class Euro : public Devise
    {
    public:
        Euro(double val);
        MAD& convert_to_mad()const override;
        Dollar& convert_to_dollar()const override;
        Euro& convert_to_euro()const override;
        Devise* Creer_devise(double val) const override;
        void  afficher() const;
    private:
       static double to_mad, to_dollar;
    };
};
