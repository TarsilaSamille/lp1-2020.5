#include <iostream>
#include <string> 
#include <cstring>
using namespace std;

int main(int argc, char *argv[])
{
  string mensagem;
  //$./prog add
  if (argc == 2 && !strcmp(argv[1], "add")){
    cout << "mensagem:" ;
    cin >> mensagem;
    cout << "Mensagem adicionada:" << mensagem << ".\n";
    return -1;
  }
  //$./prog ou qualquer outra entrada q difira do padrão $./prog add mensagem ou $./prog add
  if (argc != 3 ){
    cout << "Uso: " << argv[0] << " add <mensagem>" << ".\n";
    return -1;
  }
  //$./prog add mensagem
  cout << "Mensagem adicionada:" << argv[2]  << ".\n";
  return 0;
}
