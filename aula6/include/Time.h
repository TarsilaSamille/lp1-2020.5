#ifndef TIME_H
#define TIME_H

#include <string>

struct Time
{
    unsigned hour;
    unsigned minute;
    unsigned second;

    Time();
    std::string to_string();
    void set_from_string(std::string time);
    std::string get_current_time();
};
#endif