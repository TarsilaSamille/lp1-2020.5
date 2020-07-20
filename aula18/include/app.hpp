#ifndef APP
#define APP

#include "banco.hpp"
#include <string>

using namespace std;

class app {
    
    public:
        banco bancoA;

        app();
        
        int run();
        void add();
        void add(string nome, string agencia);
        void show_qty();
        void print_menu();
};
#endif