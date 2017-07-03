/**
* @file: date.cpp
* @author:DJ MacHack
* @date: 29.06.2017.
* Matrnr.: 3747719
* mail@hendrik-haas.de
*/

#include "Date.h"

Date::Date(int day, int month, int year) {
    this->day = day;
    this->month = month;
    this->year = year;
}

std::ostream &operator<<(std::ostream &stream, const Date &date) {
    stream << date.getDay() << "." << date.getMonth() << "." << date.getYear();
    return stream;
}

