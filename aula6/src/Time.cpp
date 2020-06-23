#include <iostream>
#include <fstream>
#include <string>

#include "../include/Date.h"
#include "../include/Time.h"

using namespace std;

string Time::get_current_time() {
  Date d;
  return d.format_current_date("%H:%M:%S");
}
