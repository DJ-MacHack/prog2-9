/**
* @file: Kleidung.cpp
* @author:DJ MacHack
* @date: 28.06.2017.
* Matrnr.: 3747719
* mail@hendrik-haas.de
*/

#include "Kleidung.h"
using namespace std;

Kleidung::Kleidung(int nummer, const string &name, int menge, double preis, string farbe, string groesse) : Artikel(nummer, name, menge, preis) {
    this->farbe = farbe;
    this->groesse = groesse;

}

Kleidung::Kleidung(const Kleidung &artikel) :Artikel(artikel.getArtikelnummer(), artikel.getBezeichnung(), artikel.getBestand(),
                                                     artikel.getPreis()) {
    this->setFarbe(artikel.getFarbe());
    this->setGroesse(artikel.getGroesse());
}

Kleidung &Kleidung::operator=(const Kleidung &artikel) {
    if(this==&artikel){
        return *this;
    }
    clone(artikel);
    return *this;
}

void Kleidung::clone(const Kleidung artikel) {
    setArtikelnummer(artikel.getArtikelnummer());
    setBestand(artikel.getBestand());
    setPreis(artikel.getPreis());
    setBezeichnung(artikel.getBezeichnung());
    setFarbe(artikel.getFarbe());
    setFarbe(artikel.getGroesse());
}

void Kleidung::ausgeben(std::ostream &stream) const {
    Artikel::ausgeben(stream);
    stream << "Farbe: " << getFarbe() << endl;
    stream << "Groesse: " << getGroesse() << endl;
}
