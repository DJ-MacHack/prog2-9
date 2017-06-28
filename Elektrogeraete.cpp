/**
* @file: Elektrogeraete.cpp
* @author:DJ MacHack
* @date: 28.06.2017.
* Matrnr.: 3747719
* mail@hendrik-haas.de
*/

#include "Elektrogeraete.h"

Elektrogeraete::Elektrogeraete(int nummer, const string &name, int menge, double preis, int kw) : Artikel(nummer, name, menge,
                                                                                                  preis) {
    this->kW = kw;
}

void Elektrogeraete::ausgeben(std::ostream &stream) const {
    Artikel::ausgeben(stream);
    stream << "Verbrauch in kW: " << getKW() << endl;
}
