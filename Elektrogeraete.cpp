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

Elektrogeraete::Elektrogeraete(const Elektrogeraete &artikel): Artikel(artikel.getArtikelnummer(), artikel.getBezeichnung(), artikel.getBestand(),
                                                                       artikel.getPreis()) {
    this->kW = artikel.getKW();
}

Elektrogeraete &Elektrogeraete::operator=(const Elektrogeraete &artikel) {
    if(this==&artikel){
        return *this;
    }
    clone(artikel);
    return *this;
}

void Elektrogeraete::clone(const Elektrogeraete &artikel) {
    setArtikelnummer(artikel.getArtikelnummer());
    setBestand(artikel.getBestand());
    setPreis(artikel.getPreis());
    setBezeichnung(artikel.getBezeichnung());
    setKW(artikel.getKW());
}

void Elektrogeraete::ausgeben(std::ostream &stream) const {
    Artikel::ausgeben(stream);
    stream << "Verbrauch in kW: " << getKW() << endl;
}
