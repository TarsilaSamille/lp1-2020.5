#include <iostream>
#include <fstream>
#include <string>
#include <cstring>
using namespace std;

void mostrar_uso(string nome_prog);
void mostrar_mensagem(string mensagem);
int gravar_mensagem(string mensagem);
int listar_mensagens();

int main(int argc, char *argv[])
{
  string nome_prog = argv[0];
  string action = (argv[1] == NULL) ? " " : argv[1];
  string mensagem;
  if (argc == 2)
  {
    //$./prog add
    if (action == "add")
    {
      cout << "mensagem:";
      cin >> mensagem;
      mostrar_mensagem(mensagem);
      gravar_mensagem(mensagem);
      return -1;
    }
    //$./prog listar
    if (action == "list")
    {
      return listar_mensagens();
    }
  }
  //$./prog ou qualquer outra entrada q difira do padrão $./prog add mensagem ou $./prog add
  if (argc != 3)
  {
    mostrar_uso(nome_prog);
    return -1;
  }
  //$./prog add mensagem
  mostrar_mensagem(argv[2]);
  return gravar_mensagem(argv[2]);
}

void mostrar_uso(string nome_prog)
{
  cout << "Uso: " << nome_prog << " list" << "\n";
  cout << "Uso: " << nome_prog << " add <mensagem>" << "\n";
}

void mostrar_mensagem(string mensagem)
{
  cout << "Mensagem adicionada:" << mensagem << "\n";
}

int gravar_mensagem(string mensagem)
{
  ofstream arquivo;
  arquivo.open("mensagem.txt", fstream::app);
  if (!arquivo.is_open())
  {
    cerr << "Arquivo não existente ou sem permissão de leitura.";
    return -1;
  }
  arquivo << mensagem << "\n";
  arquivo.close();
  return 0;
}

int listar_mensagens()
{
  ifstream arquivo;
  arquivo.open("mensagem.txt");
  if (!arquivo.is_open())
  {
    cerr << "Arquivo não existente ou sem permissão";
    return -1;
  }

  string message;
  int line_number = 0;
  while (!arquivo.eof())
  {
    ++line_number;
    getline(arquivo, message);

    if (message.size() == 0)
    {
      continue;
    }
    cout << line_number << ". " << message << "\n";
  }
  arquivo.close();
  return 0;
}
