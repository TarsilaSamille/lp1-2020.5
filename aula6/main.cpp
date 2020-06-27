#include "include/App.h"

int main(int argc, char* argv[]){
    App aplicativo("mensagem.txt");
    return aplicativo.run(argc, argv);
}