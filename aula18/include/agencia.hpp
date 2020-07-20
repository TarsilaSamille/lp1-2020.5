#ifndef AGENCIA
#define AGENCIA

#include <string>

using namespace std;

class agencia {

    private:
        string nome;
        string id;

    public:
        agencia();
        agencia(string nome);

        void setNome(string nome);
        string getNome();

        void setId(string id);
        string getId();
};
#endif