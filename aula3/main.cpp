#include <iostream>
#include <fstream>
#include <string> 
#include <cstring>
using namespace std;

void mostrar_mensagem(string mensagem);
void gravar_mensagem(string mensagem);

int main(int argc, char *argv[])
{
  string mensagem;
  //$./prog add
  if (argc == 2 && !strcmp(argv[1], "add")){
    cout << "mensagem:";
    cin >> mensagem;
    mostrar_mensagem(mensagem);
    gravar_mensagem(mensagem);
    return -1;
  }
  //$./prog ou qualquer outra entrada q difira do padrão $./prog add mensagem ou $./prog add
  if (argc != 3 ){
    cout << "Uso: " << argv[0] << " add <mensagem>" << ".\n";
    return -1;
  }
  //$./prog add mensagem
  mostrar_mensagem(argv[2]);
  gravar_mensagem(argv[2]);
  return 0;
}

void mostrar_mensagem(string mensagem){
    cout << "Mensagem adicionada:" << mensagem << "\n";
}

void gravar_mensagem(string mensagem){
  ofstream arquivo;
  arquivo.open ("mensagem.txt");
  arquivo << mensagem << "\n";
  arquivo.close();  
}
