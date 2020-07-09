#include <iostream>
#include "conta.hpp"

using namespace std;

int main(){
    // conta c;
    // conta d;
    // conta e(d);
    
    // cliente clC;
    // cliente clD;

    // clC.nome = "João";
    // clD.nome = "Maria";

    // c.titular = clC;
    // d.titular = clD;

    // cout << "Titular da conta C: " << c.titular.nome << endl;
    // cout << "Titular da conta D: " << d.titular.nome << endl;
    // cout << "Titular da conta E: " << e.titular.nome << endl;
    // c.saldo = 20;
    // c.saca(15);

    // cout << "Saldo da conta C: " << c.saldo << endl;

    // c.deposita(50);
    // c.transfere(d, 45);

    // cout << "Saldo da conta C: " << c.saldo << endl;
    // cout << "Saldo da conta D: " << d.saldo << endl;


    cliente cl;
    conta a(cl);
    cout << "Quantidade de clientes: " << cliente::quantidadeClientes << endl;
    cout << "Quantidade de contas: " << conta::quantidadeContas << endl;

    conta b;
    cliente cl2;
    cout << "Quantidade de clientes: " << cliente::quantidadeClientes << endl;
    cout << "Quantidade de contas: " << conta::quantidadeContas << endl;
    return 0;
}
