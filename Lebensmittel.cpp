/**
* @file: Lebensmittel.cpp
* @author:DJ MacHack
* @date: 28.06.2017.
* Matrnr.: 3747719
* mail@hendrik-haas.de
*/

#include "Lebensmittel.h"

using namespace std;

/**
 * exception
 */
class AbgelaufenException: public exception {
    virtual const char *what() const throw() {
        return "MHD abgelaufen!";
    }
} abgelaufenExp;

/**
 * constructor
 * @param nummer
 * @param name
 * @param menge
 * @param preis
 * @param tag
 * @param monat
 * @param jahr
 */
Lebensmittel::Lebensmittel(int nummer, const string &name, int menge, double preis, int tag, int monat, int jahr) : Artikel(nummer, name, menge,
                                                                                              preis) {
    this->date = new Date(tag, monat, jahr);
}

/**
 * cout
 * @param stream
 */
void Lebensmittel::ausgeben(std::ostream &stream) const {
    Artikel::ausgeben(stream);
    stream << "Mindesthalbarkeitsdatum: " << *(this->date) << endl;
}

/**
 * copy constructor
 * @param artikel
 */
Lebensmittel::Lebensmittel(const Lebensmittel &artikel) : Artikel(artikel.getArtikelnummer(), artikel.getBezeichnung(), artikel.getBestand(),
        artikel.getPreis()) {
    setDate(*(new Date(artikel.getDate()->getDay(), artikel.getDate()->getMonth(), artikel.getDate()->getYear())));
}

/**
 * setDate
 * @param datum
 */
void Lebensmittel::setDate(Date datum) {
    this->date = new Date(datum.getDay(),datum.getMonth(),datum.getYear());
}

/**
 * check MHD
 * @return
 */
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

/**
 * destructor
 */
Lebensmittel::~Lebensmittel() {
    delete(this->date);
}

Lebensmittel &Lebensmittel::operator=(const Lebensmittel &artikel) {
    Artikel::operator=(artikel);
    setDate(*artikel.getDate());
    return *this;
}
