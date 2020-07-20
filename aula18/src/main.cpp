#include <iostream>
#include "../include/app.hpp"
#include "../include/clientePF.hpp"
#include "../include/fila.hpp"
#include "../include/clientePJ.hpp"
using namespace std;

int main(){
  app aplicativo;

    clientePF a("Gabriel", "123");
    clientePF b("Lucas", "456");
    clientePF c("Denied", "Não vai entrar");

    clientePJ d("Riachuelo", "789");
    clientePJ e("C&A", "101112");
    clientePJ f("Denied", "Não vai entrar");

    cout << "fila dos Clientes:" << endl;
    fila<clientePF> clientes(2);
    clientes.adiciona(a);
    clientes.adiciona(b);
    clientes.adiciona(c);
    clientes.imprime();

    cout << "fila dos Clientes Juridicos:" << endl;
    fila<clientePJ> clientespj(2);
    clientespj.adiciona(d);
    clientespj.adiciona(e);
    clientespj.adiciona(f);
    clientespj.imprime();    

  return aplicativo.run();
}