#ifndef CLIENTEPF
#define CLIENTEPF

#include <string>
#include "cliente.hpp"

using namespace std;

class clientePF : public cliente {
    private:
        string cpf;

    public:
        clientePF();
        clientePF(string nome, string cpf);
        
        void setCpf(string cpf);
        string getCpf();


};
#endif