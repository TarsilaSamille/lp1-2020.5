
#ifndef DATA_H
#define DATA_H
#include <string>

struct Data {
  	int mes;
  	int dia;
  	int ano;

  	bool data_existe();
	std::string format_current_date(std::string format);
	std::string get_current_date();
};

#endif