#ifndef RESTAURANTE
#define RESTAURANTE

#include <string>
#include "estabelecimento.hpp"

using namespace std;

class restaurante : public estabelecimento {
    public:
        string cardapio;

        restaurante(string cardapio, string caixa);
        restaurante(string caixa);
        ~restaurante();

        void escreverCardapio();
        void addAll();
            void gravar();
};
#endif