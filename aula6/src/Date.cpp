#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <iomanip>

#include "../include/Date.h"
#include "../include/Time.h"

using namespace std;

Date::Date(): year(0), month(0), day(0)
{
}

void Date::set_from_string(std::string date)
{
   stringstream stream(date);
    char discard;
    stream >> day;   stream >> discard;
    stream >> month; stream >> discard;
    stream >> year;
}

std::string Date::to_string()
{
   stringstream stream;
    stream <<setfill('0') <<setw(2) << day;   stream << '/';
    stream <<setfill('0') <<setw(2) << month; stream << '/';
    stream << year;
    return stream.str();
}

bool Date::data_existe() {
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

string Date::format_current_date(string format) {
  time_t now = time(nullptr);
  char result[1024];
  strftime(result, sizeof(result), format.c_str(), localtime( & now));
  return string(result);
}
string Date::get_current_date() {
  return format_current_date("%d/%m/%Y");
}