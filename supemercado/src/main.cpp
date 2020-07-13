#include "../include/app.hpp"

int main(int argc, char* argv[]){
    app aplicativo("estoque.csv", "caixa.csv");
    return aplicativo.run(argc, argv);
}