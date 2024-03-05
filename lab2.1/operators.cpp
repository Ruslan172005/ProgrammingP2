#include "operators.h"
#include <iostream>

std::ostream& operator<<(std::ostream& os, const Date& date) {
    os << date.year << "-" << date.month << "-" << date.day;
    return os;
}

std::ostream& operator<<(std::ostream& os, const Time& time) {
    os << time.hours << ":" << time.minutes;
    return os;
}

bool operator<(const Time& lhs, const Time& rhs) {
    return std::tie(lhs.hours, lhs.minutes) < std::tie(rhs.hours, rhs.minutes);
}

bool operator<(const Date& lhs, const Date& rhs) {
    return std::tie(lhs.year, lhs.month, lhs.day) < std::tie(rhs.year, rhs.month, rhs.day);
}
