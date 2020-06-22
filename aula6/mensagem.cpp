#include "mensagem.h"
#include "data.h"
#include "hora.h"

#include <iostream>
#include <fstream>
#include <string>
#include <cstring>
#include <ctime>
#include <sstream>

using namespace std;

void mostrar_mensagem(string mensagem) {
  cout << "Mensagem adicionada:" << mensagem << "\n";
}

int gravar_mensagem(string mensagem) {
  fstream arquivo;
  arquivo.open("mensagem.txt", fstream::app);
  if (!arquivo.is_open()) {
    cerr << "Arquivo não existente ou sem permissão de leitura.";
    return -1;
  }
  if (!data:data_existe()) {
    if (arquivo.tellg() != 0){arquivo << "\n";}
    arquivo << "#" << data::get_current_date() << "\n\n";
  }
  arquivo << "- " << hora:get_current_time() << " " << mensagem << "\n";
  arquivo.close();
  return 0;
}

int listar_mensagens() {
  ifstream arquivo;
  arquivo.open("mensagem.txt");
  if (!arquivo.is_open()) {
    cerr << "Arquivo não existente ou sem permissão";
    return -1;
  }
  string message;
  int line_number = 0;
  while (!arquivo.eof()) {
    getline(arquivo, message);
    if (message.size() == 0 || (message.rfind("#", 0) == 0)) {
      continue;
    }
    cout << message.erase(0, 11) << "\n";
  }
  arquivo.close();
  return 0;
}