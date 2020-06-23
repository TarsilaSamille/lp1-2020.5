#include <iostream>
#include <fstream>
#include <string>

#include "../include/Diary.h"
#include "../include/Date.h"
#include "../include/Time.h"

using namespace std;

Diary::Diary(string filename){
   filename = filename;
   messages_size = 0;
}

void Diary::add(string message)
{
    // adicionar mensagem no array de mensagens
}

void Diary::write()
{
    Date d;
    Time t;
  fstream arquivo;
  arquivo.open(filename, fstream::app);
  if (!arquivo.is_open()) {
    cerr << "Arquivo não existente ou sem permissão de leitura.";
  }
  if (!d.data_existe()) {
    if (arquivo.tellg() != 0){arquivo << "\n";}
    arquivo << "#" << d.get_current_date() << "\n\n";
  }
  arquivo << "- " << t.get_current_time() << " " << messages[messages_size].content<< "\n";
  messages_size++;
  arquivo.close();
}
