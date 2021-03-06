#include "../include/estabelecimento.hpp"
#include "../include/produto.hpp"

#include <iostream>
#include <fstream>
#include <sstream>
#include <algorithm>
#include <iomanip>
#include <cstring>
#include <regex>
#include <vector>
using namespace std;

int estabelecimento::quantidadeContas;

estabelecimento::estabelecimento(string caixa)
    :caixa(caixa)
{
}

estabelecimento::~estabelecimento()
{
}

produto estabelecimento::venda(string nome)
{
  for (size_t i = 0; i < produtos.size(); i++)
  {
    if (compare(produtos.at(i).nome, nome))
    {
      if (produtos.at(i).quantidadeEstoque > 0)
      {
        return venda(produtos.at(i).codigo);
      }
      else
      {
        cout << nome << " sem estoque\n";
        return produto();
      }
    }
  }
  cout << nome << " nome invalido\n";
  return produto();
}

produto estabelecimento::venda(int codigo)
{
  produto pdt;
  for (size_t i = 0; i < produtos.size(); i++)
  {
    if (produtos.at(i).codigo == codigo)
    {
      pdt = produtos.at(i);
      if (pdt.quantidadeEstoque > 0)
      {
        vector<produto> v = produtos.getElements();
        v[i].quantidadeEstoque--;
        v[i].quantidadeVendida++;
        produtos.setElements(v);
      }
    }
  }
  escrever(pdt);
  return pdt;
}

void estabelecimento::listar()
{
  for (auto i : produtos)
  {
    if (i.quantidadeEstoque > 0)
      cout << i.codigo << "-" << i.nome << "-R$" << i.preco << "-" << i.quantidadeEstoque << " " << i.unidadeMedida << "\n";
  }
}

void estabelecimento::add(produto p)
{
  produtos.push(p);
}

void estabelecimento::addAllCaixa()
{
  produtosVendidos = {};
  fstream arquivo;
  arquivo.open(caixa);
  if (!arquivo.is_open())
  {
    cerr << "Arquivo não existente ou sem permissão";
  }
  produto p;
  string msg, cod, pr, quantidade;
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
      pr = strings[2];
      quantidade = strings[3];
      p.nome = strings[1];
      p.codigo = atoi(cod.c_str());
      p.quantidadeVendida = atoi(quantidade.c_str());
      p.preco = atof(pr.substr(2, pr.size()).c_str());
      produtosVendidos.push(p);
    }
    if (msg.rfind(",", 0) == 0)
    {
      break;
    }
  }
  arquivo.close();
}

void estabelecimento::escrever(produto p)
{
  fstream arquivo;
  arquivo.open(caixa);
  if (!arquivo.is_open())
  {
    cerr << "Arquivo não existente ou sem permissão de leitura. 1";
  }

  arquivo << "CODIGO,PRODUTO,PREÇO,QUANTIDADE VENDIDA,TOTAL\n";
  addAllCaixa();
  double totalGeral = 0, total = 0;
  bool jaFoiVendido = false;
  int position = -1;
  produto produtoJaVendido;
  if (produtosVendidos.size() > 0)
  {
    for (size_t i = 0; i < produtosVendidos.size(); i++)
    {
      position++;
      if (p.codigo == produtosVendidos.at(i).codigo)
      {
        vector<produto> v = produtosVendidos.getElements();
        v[i].quantidadeVendida++;
        produtosVendidos.setElements(v);
        jaFoiVendido = true;
        produtoJaVendido = produtosVendidos.at(i);
        break;
      }
    }
  }
  if (!jaFoiVendido)
  {
    p.quantidadeVendida++;
    produtosVendidos.push(p);
  }
  sort(produtosVendidos.begin(), produtosVendidos.end(), ordenaPorCodigo);

  for (auto produto : produtosVendidos)
  {
    total = produto.quantidadeVendida * produto.preco;
    totalGeral += total;
    arquivo << produto.codigo << "," << produto.nome << ",R$" << produto.preco << "," << produto.quantidadeVendida << "," << total << "\n";
  }

  arquivo << ",,,TOTAL GERAL:,R$" << totalGeral;

  arquivo.close();
  gravar();
}

void estabelecimento::gravar()
{
}

void estabelecimento::reabastecer(produto pdtNovo)
{
  for (size_t i = 0; i < produtos.size(); i++)
  {
    if (compare(produtos.at(i).nome, pdtNovo.nome))
    {
      vector<produto> v = produtos.getElements();
      v[i].quantidadeEstoque += pdtNovo.quantidadeEstoque;
      produtos.setElements(v);
    }
  }
  gravar();
}

bool estabelecimento::ordenaPorCodigo(produto a, produto b)
{
  return a.codigo < b.codigo;
}

bool estabelecimento::compare(string s1, string s2)
{
  string comAcentos = "ÁÂÀÃáâàãÉÊÈéêèÍÎÌíîìÓÔÒÕóôòõÚÛúûùÇç";
  string semAcentos = "AAAAaaaaEEEeeeIIIiiiOOOOooooUUuuuCc";
  s1.erase(std::remove_if(s1.begin(), s1.end(), ::isspace), s1.end());
  s2.erase(std::remove_if(s2.begin(), s2.end(), ::isspace), s2.end());
  for (int i = 0; i < (int)comAcentos.length(); i++)
  {
    replace(s1.begin(), s1.end(), comAcentos[i], semAcentos[i]);
    replace(s2.begin(), s2.end(), comAcentos[i], semAcentos[i]);
    break;
  }

  for (int i = 0; i < (int)comAcentos.length(); i++)
  {
    s1.erase(remove(s1.begin(), s1.end(), comAcentos[i]), s1.end());
    s2.erase(remove(s2.begin(), s2.end(), comAcentos[i]), s2.end());
  }
  transform(s1.begin(), s1.end(), s1.begin(), ::toupper);
  transform(s2.begin(), s2.end(), s2.begin(), ::toupper);
  return s1 == s2;
}
