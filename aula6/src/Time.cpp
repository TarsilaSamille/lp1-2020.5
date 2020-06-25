#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <iomanip>

#include "../include/Date.h"
#include "../include/Time.h"

using namespace std;

Time::Time() : hour(0), minute(0), second(0)
{
}

void Time::set_from_string(string time)
{
    stringstream stream(time);
    char discard;
    stream >> hour;   stream >> discard;
    stream >> minute; stream >> discard;
    stream >> second;
}

string Time::to_string()
{
    stringstream stream;
    stream << setfill('0') << setw(2) << hour;   stream << ':';
    stream << setfill('0') << setw(2) << minute; stream << ':';
    stream << setfill('0') << setw(2) << second;
    return stream.str();
}

string Time::get_current_time() {
  Date d;
  return d.format_current_date("%H:%M:%S");
}

