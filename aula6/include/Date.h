#ifndef DATE_H
#define DATE_H

#include <string>

struct Date
{
    unsigned year;
    unsigned month;
    unsigned day;

    Date();
    std::string to_string();
    void set_from_string(std::string date);
    bool data_existe();
    std::string format_current_date(std::string format);
    std::string get_current_date();
};
#endif