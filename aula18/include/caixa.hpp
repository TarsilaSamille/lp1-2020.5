#ifndef CAIXA
#define CAIXA

#include "funcionario.hpp"

class caixa : public funcionario {
    private:
        double quebra_caixa;
    
    public:
        caixa();

        void setQuebraCaixa(double quebra_caixa);
        double getQuebraCaixa();
};
#endif