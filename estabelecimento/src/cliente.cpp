#include "../include/cliente.hpp"
#include "../include/produto.hpp"
#include "../include/exceptions.hpp"

#include <iostream>
#include <fstream>
#include <sstream>
#include <cstring>

using namespace std;

int cliente::quantidadeClientes;

cliente::cliente(string nome, double saldo):nome(nome),saldo(saldo){
    this->quantidadeClientes += 1;
    this->codigo = this->quantidadeClientes;
}

cliente::cliente()
{
    this->codigo = this->quantidadeClientes;
    this->quantidadeClientes += 1;
}

cliente::~cliente()
{
}

void cliente::compra(produto &p)
{
    if(saldo >= p.preco){
        sacola.push(p);
        saldo -= p.preco;
    }else{
        cout << "sem dinheiro pra comprar " << p.nome << endl;
    }
}
void cliente::verSacola()
{
    for (auto i : sacola.getElements())
    {
       cout << i.codigo << "-" << i.nome << "-R$" << i.preco<< "\n";
    }
}
void cliente::registro()
{   
    string t = "clientes/cliente_";
    t += to_string(codigo);
    t += ".txt";
    escrever(t);
}

void cliente::escrever(string filename)
{
  exceptions e;  
  ofstream file;
  file.open(filename);
  try{
    if (!file.is_open())
    {   //num. inteiro qualquer, a ser tratado pelo catch de int e exibir a mensagem de insucesso na abertura do arquivo
        //throw(15);
    }
  }
  catch(int){
      e.erroArquivo();
  }
    double total =0;
    for (auto i : sacola)
    {
        file << i.codigo << "-" << i.nome << "-R$" << i.preco<< "\n";
        total += i.preco;
    }
  file << "TOTAL GERAL:R$" << total<<endl;
  file << "SALDO:R$" << saldo<<endl;
  file << "NOME:" << nome<<endl;
  file.close();
}
