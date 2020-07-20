#ifndef GERENTE
#define GERENTE

#include "funcionario.hpp"
#include <string>

using namespace std;

class gerente : public funcionario {
    private:
        string chave_acesso;
    
    public:
        gerente();

        void setChaveAcesso(string chave_acesso);
        string getChaveAcesso();
};
#endif