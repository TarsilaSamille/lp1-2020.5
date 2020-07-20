#ifndef CLIENTE
#define CLIENTE

#include <string>

using namespace std;

class cliente {
    private:
        string nome;

    public:
        cliente();
        cliente(string nome);

        void setNome(string nome);
        string getNome();
};

#endif