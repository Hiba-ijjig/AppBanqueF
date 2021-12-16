#pragma once
#include "Operations.h"

namespace Banque {
    
    class OperationR :public Operations
    {
    public:
        OperationR(Devise* d, Compte* c);
    private:
        static string libelle;
    };
};
