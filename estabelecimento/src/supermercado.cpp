#include "../include/supermercado.hpp"
#include "../include/estabelecimento.hpp"
#include <iostream>
#include <fstream>
#include <sstream>
#include <iomanip>
#include <cstring>
using namespace std;

supermercado::supermercado(string estoque, string caixa, string fornecedorF)
 : estoque(estoque), estabelecimento(caixa), fornecedorS(fornecedorF)
{
  addAll();
}
supermercado::supermercado(string caixa, string fornecedorF) : estabelecimento(caixa), fornecedorS(fornecedorF)
{
}
supermercado::~supermercado()
{
      escreverEstoque();
}

void supermercado::gravar()
{
    escreverEstoque();
}

void supermercado::escreverEstoque()
{
  fstream arquivo;
  arquivo.open(estoque);
  if (!arquivo.is_open())
  {
    cerr << "Arquivo não existente ou sem permissão de leitura. 2";
  }

  arquivo << "COD,PRODUTO,UNIDADE DE MEDIDA,PREÇO,QUANTIDADE" << endl;
  double centavos;
  for (auto produto : produtos)
  {
    centavos = (produto.preco - (int)produto.preco);
    centavos = centavos * 100;
    arquivo << produto.codigo << "," << produto.nome << "," << produto.unidadeMedida << ',' << '"' << "R$ " << (int)produto.preco;
    if (centavos != 0)
      arquivo << "," << centavos;
    else
      arquivo << ","
              << "00";
    arquivo << '"' << ',' << produto.quantidadeEstoque << "\n";
  }
  arquivo.close();
}



void supermercado::addAll()
{
  fstream arquivo;
  arquivo.open(estoque);
  if (!arquivo.is_open())
  {
    cerr << "Arquivo não existente ou sem permissão ESTOQUE";
  }
  produto p;

  string msg, cod, pr, pc, quantidade;
  while (!arquivo.eof())
  {
    getline(arquivo, msg);
    if (msg.size() == 0)
    {
      continue;
    }
    vector<string> strings;
    istringstream f(msg);
    string s;
    if (msg.rfind("C", 0) != 0 && msg.rfind(",", 0) != 0)
    {
      while (getline(f, s, ','))
      {
        strings.push_back(s);
      }
      cod = strings[0];
      pr = strings[3];
      pc = strings[4];
      quantidade = strings[5];
      p.nome = strings[1];
      p.unidadeMedida = strings[2];
      p.codigo = atoi(cod.c_str());
      p.quantidadeEstoque = atoi(quantidade.c_str());
      p.preco = atof(pr.substr(4, msg.size()).c_str()) + (atof(pc.substr(0, 2).c_str()) / 100);
      add(p);
    }
  }
  arquivo.close();
}