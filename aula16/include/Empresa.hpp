#ifndef EMPRESA
#define EMPRESA

#include <string>

using namespace std;

class Empresa
{
private:
    string nome;
    string cnpj;

public:
    void setNome(string nome);
    string getNome();

    void setCnpj(string cnpj);
    string getCnpj();

};
#endif
