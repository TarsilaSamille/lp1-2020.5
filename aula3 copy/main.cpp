#include <iostream>
#include <fstream>
#include <string>
#include <cstring>
#include <ctime>
#include <sstream>

using namespace std;

void mostrar_uso(string nome_prog);
void mostrar_mensagem(string mensagem);
int gravar_mensagem(string mensagem);
bool data_existe();
string format_current_date(string format);
string get_current_date();
string get_current_time();
int listar_mensagens();

int main(int argc, char * argv[]) {
  string nome_prog = argv[0];
  string action = (argv[1] == NULL) ? " " : argv[1];
  string mensagem;
  if (argc == 2) {
    //$./prog add
    if (action == "add") {
      cout << "mensagem:";
      cin >> mensagem;
      mostrar_mensagem(mensagem);
      gravar_mensagem(mensagem);
      return -1;
    }
    //$./prog listar
    if (action == "list") {
      return listar_mensagens();
    }
  }
  //$./prog ou qualquer outra entrada q difira do padrão $./prog add mensagem ou $./prog add
  if (argc != 3) {
    mostrar_uso(nome_prog);
    return -1;
  }
  //$./prog add mensagem
  mostrar_mensagem(argv[2]);
  return gravar_mensagem(argv[2]);
}

void mostrar_uso(string nome_prog) {
  cout << "Uso: " << nome_prog << " list" << "\n";
  cout << "Uso: " << nome_prog << " add <mensagem>" << "\n";
}

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
  if (!data_existe()) {
    if (arquivo.tellg() != 0){arquivo << "\n";}
    arquivo << "#" << get_current_date() << "\n\n";
  }
  arquivo << "- " << get_current_time() << " " << mensagem << "\n";
  arquivo.close();
  return 0;
}

bool data_existe() {
  fstream arquivo;
  arquivo.open("mensagem.txt", fstream:: in | fstream::out | fstream::app);
  string message;
  while (!arquivo.eof()) {
    getline(arquivo, message);
    if (message.rfind("#", 0) == 0) {
      if (message.rfind(get_current_date(), 1) == 1) {
        return true;
      }
    }
    if (message.size() == 0) {
      continue;
    }
  }
  return false;
}

string format_current_date(string format) {
  time_t now = time(nullptr);
  char result[1024];
  strftime(result, sizeof(result), format.c_str(), localtime( & now));
  return string(result);
}
string get_current_date() {
  return format_current_date("%d/%m/%Y");
}
string get_current_time() {
  return format_current_date("%H:%M:%S");
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