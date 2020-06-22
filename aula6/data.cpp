#include "mensagem.h"
#include <iostream>
#include <fstream>
#include <string>
#include <cstring>
#include <ctime>
#include <sstream>

using namespace std;

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