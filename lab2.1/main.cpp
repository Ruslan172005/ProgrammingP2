#pragma once

#include <iostream>
#include <vector>
#include <algorithm>
#include <tuple>
#include "test_runner.h" // Включення файлу тест ранера

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
    int price;
};

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

#define SORT_BY(field) [](const AirlineTicket& lhs, const AirlineTicket& rhs) { \
    return lhs.field < rhs.field; \
}

void TestSortBy() {
    // Your test for SORT_BY function
}

int main() {
    TestRunner tr; // Створення об'єкту тест ранера
    RUN_TEST(tr, TestSortBy); // Запуск тесту
    return 0;
}
