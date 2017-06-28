/**
* @file: Lebensmittel.cpp
* @author:DJ MacHack
* @date: 28.06.2017.
* Matrnr.: 3747719
* mail@hendrik-haas.de
*/

#include "Lebensmittel.h"
using namespace std;

class AbgelaufenException: public exception {
    virtual const char *what() const throw() {
        return "MHD abgelaufen!";
    }
} abgelaufenExp;

Lebensmittel::Lebensmittel(int nummer, const string &name, int menge, double preis) : Artikel(nummer, name, menge,
                                                                                              preis) {setDate();}

void Lebensmittel::ausgeben(std::ostream &stream) const {
    Artikel::ausgeben(stream);
    stream << "Mindesthalbarkeitsdatum: " << getDate()->tm_mday << "." << getDate()->tm_mon+1 << "." << getDate()->tm_year+1900 << endl;
}

void Lebensmittel::setDate() {
    int d, m, y;
    cout << "Mindesthalbarkeitsdatum" << endl;
    cout << "Tag: " << endl;
    cin >> d;
    cout << "Monat: " << endl;
    cin >> m;
    cout << "Jahr: " << endl;
    cin >> y;
    this->date->tm_year = y-1900;
    this->date->tm_mon = m-1;
    this->date->tm_mday = d;
    this->date->tm_hour = 1;
    this->date->tm_min = 1;
    this->date->tm_sec = 1;
}

bool Lebensmittel::pruefeMHD() {
    time_t now = time(0);
    tm *ltm = localtime(&now);
    if(ltm->tm_year > this->date->tm_year){
        throw abgelaufenExp;
    }
    if(ltm->tm_mon > this->date->tm_mon){
        throw abgelaufenExp;
    }
    if(ltm->tm_mday > this->date->tm_mday){
        throw abgelaufenExp;
    }
    return true;
}
