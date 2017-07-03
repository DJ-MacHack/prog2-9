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

Lebensmittel::Lebensmittel(int nummer, const string &name, int menge, double preis, int tag, int monat, int jahr) : Artikel(nummer, name, menge,
                                                                                              preis) {
    this->date = new Date(tag, monat, jahr);
}

void Lebensmittel::ausgeben(std::ostream &stream) const {
    Artikel::ausgeben(stream);
    stream << "Mindesthalbarkeitsdatum: " << *(this->date) << endl;
}

Lebensmittel::Lebensmittel(const Lebensmittel &artikel) : Artikel(artikel.getArtikelnummer(), artikel.getBezeichnung(), artikel.getBestand(),
        artikel.getPreis()) {
    setDate(*(new Date(artikel.getDate()->getDay(), artikel.getDate()->getMonth(), artikel.getDate()->getYear())));
}

Lebensmittel &Lebensmittel::operator=(const Lebensmittel &artikel) {
    if(this==&artikel){
        return *this;
    }
    clone(artikel);
    return *this;
}

void Lebensmittel::clone(const Lebensmittel artikel) {
    setArtikelnummer(artikel.getArtikelnummer());
    setBestand(artikel.getBestand());
    setPreis(artikel.getPreis());
    setBezeichnung(artikel.getBezeichnung());
    setDate(*(new Date(artikel.getDate()->getDay(), artikel.getDate()->getMonth(), artikel.getDate()->getYear())));
}

void Lebensmittel::setDate(Date datum) {

}

bool Lebensmittel::pruefeMHD() {
    time_t now = time(0);
    tm *ltm = localtime(&now);
    if(ltm->tm_year+1900 > this->date->getYear()){
        throw abgelaufenExp;
    } else {
        if (ltm->tm_year + 1900 == this->date->getYear()) {
            if (ltm->tm_mon + 1 > this->date->getMonth()) {
                throw abgelaufenExp;
            } else {
                if ((ltm->tm_mon + 1 == this->date->getMonth())) {
                    if (ltm->tm_mday > this->date->getDay()) {
                        throw abgelaufenExp;
                    }
                }
            }
        }
    }
    return true;
}

Lebensmittel::~Lebensmittel() {
    delete(this->date);
}
