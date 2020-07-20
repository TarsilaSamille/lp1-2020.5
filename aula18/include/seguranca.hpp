#ifndef SEGURANCA
#define SEGURANCA

#include "funcionario.hpp"

using namespace std;

class seguranca : public funcionario {
    private: 
        string chave;

    public:
        seguranca();

        void setChave(string chave);
        string getChave();
};
#endif