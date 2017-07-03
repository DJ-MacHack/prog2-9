/**
* @file: date.cpp
* @author:DJ MacHack
* @date: 29.06.2017.
* Matrnr.: 3747719
* mail@hendrik-haas.de
*/

#include "Date.h"

/**
 * constructor
 * @param day
 * @param month
 * @param year
 */
Date::Date(int day, int month, int year) {
    this->day = day;
    this->month = month;
    this->year = year;
}

/**
 * cout
 * @param stream
 * @param date
 * @return
 */
std::ostream &operator<<(std::ostream &stream, const Date &date) {
    stream << date.getDay() << "." << date.getMonth() << "." << date.getYear();
    return stream;
}

Date::Date(const Date &date) {
    this->day=date.getDay();
    this->month=date.getMonth();
    this->year=date.getYear();
}

Date &Date::operator=(const Date &date) {
    if(this==&date){
        return *this;
    }
    this->day=date.getDay();
    this->month=date.getMonth();
    this->year=date.getYear();
    return *this;
}

