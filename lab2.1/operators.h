#pragma once

#include "airline_ticket.h"
#include <tuple>

std::ostream& operator<<(std::ostream& os, const Date& date);
std::ostream& operator<<(std::ostream& os, const Time& time);
bool operator<(const Time& lhs, const Time& rhs);
bool operator<(const Date& lhs, const Date& rhs);
