#include "../include/estabelecimento.hpp"
#include "../include/produto.hpp"

#include <iostream>
#include <fstream>
#include <sstream>
#include <algorithm>
#include <iomanip>
#include <cstring>
#include <regex>

int estabelecimento::quantidadeContas;

estabelecimento::estabelecimento(string estoque,string caixa)
    : estoque(estoque), caixa(caixa)
{
  addAll();
}

estabelecimento::~estabelecimento()
{
  escreverEstoque();
}
void estabelecimento::gerarCaixa()
{
  addAllCaixa();
  double totalGeral = 0, total = 0;

  for (auto produto : produtosVendidos)
  {
    total = produto.quantidadeVendida * produto.preco;
    totalGeral += total;
    if (produto.quantidadeVendida > 0)
      cout << produto.codigo << "-" << produto.nome << "-R$" << produto.preco << "-" << produto.quantidadeVendida << "-" << total << "\n";
  }

  cout << ",,,TOTAL GERAL:,R$" << totalGeral;
}

void estabelecimento::escreverEstoque()
{
  fstream arquivo;
  arquivo.open(estoque);
  if (!arquivo.is_open())
  {
    cerr << "Arquivo não existente ou sem permissão de leitura.";
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


produto *estabelecimento::venda(string nome)
{
  for (size_t i = 0; i < produtos.size(); i++)
  {
    if (compare(produtos[i].nome, nome))
    {
      if (produtos[i].quantidadeEstoque > 0)
      {
        return venda(produtos[i].codigo);
      }else {
          cout << nome << " sem estoque\n";
          return new produto();
      }
    }
  }
  cout << nome << " nome invalido\n";
  return new produto();
}

produto *estabelecimento::venda(int codigo)
{
  produto *pdt;
  for (size_t i = 0; i < produtos.size(); i++)
  {
    if (produtos[i].codigo == codigo)
    {
      pdt = &produtos[i];
      if (pdt->quantidadeEstoque > 0)
      {
        pdt->quantidadeEstoque--;
        pdt->quantidadeVendida++;
      }
    }
  }
  escrever(*pdt);
  return pdt;
}

void estabelecimento::listar()
{
  for (auto i : produtos)
  {
    if(i.quantidadeEstoque > 0) cout << i.codigo << "-" << i.nome << "-R$" << i.preco<< "\n";
  }
}

void estabelecimento::add(produto p)
{
  produtos.push_back(p);
}

void estabelecimento::addAll()
{
  fstream arquivo;
  arquivo.open(estoque);
  if (!arquivo.is_open())
  {
    cerr << "Arquivo não existente ou sem permissão";
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

void estabelecimento::addAllCaixa()
{
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
      produtosVendidos.push_back(p);
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
    cerr << "Arquivo não existente ou sem permissão de leitura.";
  }

  arquivo << "CODIGO,PRODUTO,PREÇO,QUANTIDADE VENDIDA,TOTAL\n";
  produtosVendidos = {};
  addAllCaixa();
  double totalGeral = 0, total = 0;
  bool jaFoiVendido = false;
  int position = -1;
  produto produtoJaVendido;
  if (produtosVendidos.size() > 0)
  {
    for (auto produto : produtosVendidos)
    {
      position++;
      if (p.codigo == produto.codigo)
      {
        produto.quantidadeVendida = produto.quantidadeVendida + 1;
        jaFoiVendido = true;
        produtoJaVendido = produto;
        break;
      }
    }
    if (jaFoiVendido)
    {
      produtosVendidos.erase(produtosVendidos.begin() + position);
      produtosVendidos.push_back(produtoJaVendido);
    }
  }
  if (!jaFoiVendido)
  {
    produtosVendidos.push_back(p);
  }
  sort(produtosVendidos.begin(), produtosVendidos.end(), ordenaPorCodigo);
  for (auto produto : produtosVendidos)
  {
    total = produto.quantidadeVendida * produto.preco;
    totalGeral += total;
    if (produto.quantidadeVendida > 0)
      arquivo << produto.codigo << "," << produto.nome << ",R$" << produto.preco << "," << produto.quantidadeVendida << "," << total << "\n";
  }

  arquivo << ",,,TOTAL GERAL:,R$" << totalGeral;

  arquivo.close();
}

bool estabelecimento::ordenaPorCodigo(produto a, produto b)
{
  return a.codigo < b.codigo;
}

bool estabelecimento::compare(string s1, string s2)
{
    string comAcentos = "ÁÂÀÃáâàãÉÊÈéêèÍÎÌíîìÓÔÒÕóôòõÚÛúûùÇç";
    string semAcentos = "AAAAaaaaEEEeeeIIIiiiOOOOooooUUuuuCc";
    for (int i = 0; i < (int)comAcentos.length(); i++)
    {
        replace(s1.begin(), s1.end(),comAcentos[i], semAcentos[i]);
        replace(s2.begin(), s2.end(),comAcentos[i], semAcentos[i]);
        break;
    }

    for (int i = 0; i < (int)comAcentos.length(); i++)
    {
        s1.erase(remove(s1.begin(), s1.end(), comAcentos[i]), s1.end()); 
        s2.erase(remove(s2.begin(), s2.end(), comAcentos[i]), s2.end()); 
    }
    transform(s1.begin(), s1.end(), s1.begin(), ::toupper);
    transform(s2.begin(), s2.end(), s2.begin(), ::toupper);
    return s1 == s2 ;
}
