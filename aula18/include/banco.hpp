#ifndef BANCO
#define BANCO

#include <vector>
#include "conta.hpp"

class banco {
    public:
        banco();

        vector<conta> contas;

        void add(string nome, string angencia);
        int qtd_contas();
};
#endif