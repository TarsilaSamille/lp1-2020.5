#include <iostream>
#include "carro.hpp"

using namespace std;

int main(){
    Carro c;
    c.tipo = "Sedan";
    c.numPortas = 4;
    c.placa = "XYZ-0102";

    cout << "Tipo do carro: " << c.tipo << endl;
    cout << "Quantidade de portas: " << c.numPortas << endl;
    cout << "Placa do carro: " << c.placa << endl;
    cout << "A cor do carro é: " << c.cor << endl;
    c.ligaCarro();
    c.acelera(50);
    cout << "A velocidade atual é: " << c.velocidade << "KM/H" << endl;
    c.freia (20);
    cout << "A velocidade atual é: " << c.velocidade << "KM/H" << endl;

    Carro c1("roxo");
    Carro c2("rosa");
    Carro c3("vermelho");
    Carro c4;

    cout << "\nQuantidade de carros criados: "
                << Carro::quantidadeCarros << endl;


    return 0;
}