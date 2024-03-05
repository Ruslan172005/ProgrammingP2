#pragma once

#include <string>
#include <iostream>
#include <sstream>
#include <map>

struct Date {
    int year, month, day;
};

struct Time {
    int hours, minutes;
};

struct AirlineTicket {
    std::string from;
    std::string to;
    std::string airline;
    Date departure_date;
    Time departure_time;
    Date arrival_date;
    Time arrival_time;
    uint64_t price;
};
