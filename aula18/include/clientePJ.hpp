
#ifndef CLIENTEPJ
#define CLIENTEPJ

#include "cliente.hpp"
#include <string>

using namespace std;

class clientePJ : public cliente {
    private:
        string cnpj;

    public:
        clientePJ();
        clientePJ(string nome, string cnpj);

        void setCnpj(string cnpj);
        string getCnpj();
};
#endif