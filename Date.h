/**
* @file: date.h
* @author:DJ MacHack
* @date: 29.06.2017.
* Matrnr.: 3747719
* mail@hendrik-haas.de
*/

#ifndef INC_9_DATE_H
#define INC_9_DATE_H
#include<iostream>

class Date {
public:
    Date(int day, int month, int year);
    int getDay() const {
        return day;
    }
    int getMonth() const {
        return month;
    }
    int getYear() const {
        return year;
    }
    friend std::ostream& operator<<(std::ostream& stream, const Date& artikel);
private:
    int day, month, year;
};


#endif //INC_9_DATE_H
