#include "../include/restaurante.hpp"
#include <iostream>
#include <fstream>
#include <sstream>
#include <iomanip>
#include <cstring>
using namespace std;

restaurante::restaurante(string cardapio, string caixa)
 : estabelecimento(caixa), cardapio(cardapio)
{
    addAll();
}
restaurante::restaurante(string caixa) :estabelecimento(caixa)
{
}
restaurante::~restaurante()
{
}

void restaurante::gravar()
{
}

void restaurante::addAll()
{
  fstream arquivo;
  arquivo.open(cardapio);
  if (!arquivo.is_open())
  {
    cerr << "Arquivo não existente ou sem permissão CARDAPIO";
  }
  produto p;
  int i = 0;
  string msg, cod, pr, pc, quantidade;
  while (!arquivo.eof())
  {
    getline(arquivo, msg);
    if (msg.size() == 0)
    {
      continue;
    }
    i++;
    vector<string> strings;
    istringstream f(msg);
    string s;
    cout << msg;
    if (msg.rfind("ITEM", 0) != 0 && msg.rfind(",", 0) != 0)
    {
      while (getline(f, s, ','))
      {
        strings.push_back(s);
      }
      pr = strings[1];
      p.nome = strings[0];
      p.codigo = i;
      p.preco = atof(pr.substr(3, msg.size()).c_str());
      p.quantidadeEstoque = 1000;
      cout << p.nome << p.preco << endl;

      add(p);
    }
  }
  arquivo.close();
}


void restaurante::listar()
{
  for (auto i : produtos)
  {
      cout << i.nome << "-R$" << i.preco << "\n";
  }
}
