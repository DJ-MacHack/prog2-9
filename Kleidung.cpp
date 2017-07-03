/**
* @file: Kleidung.cpp
* @author:DJ MacHack
* @date: 28.06.2017.
* Matrnr.: 3747719
* mail@hendrik-haas.de
*/

#include "Kleidung.h"
using namespace std;

/**
 * constructor
 * @param nummer
 * @param name
 * @param menge
 * @param preis
 * @param farbe
 * @param groesse
 */
Kleidung::Kleidung(int nummer, const string &name, int menge, double preis, string farbe, string groesse) : Artikel(nummer, name, menge, preis) {
    this->farbe = farbe;
    this->groesse = groesse;

}

/**
 * copy constructor
 * @param artikel
 */
Kleidung::Kleidung(const Kleidung &artikel) :Artikel(artikel.getArtikelnummer(), artikel.getBezeichnung(), artikel.getBestand(),
                                                     artikel.getPreis()) {
    this->setFarbe(artikel.getFarbe());
    this->setGroesse(artikel.getGroesse());
}

/**
 * cout
 * @param stream
 */
void Kleidung::ausgeben(std::ostream &stream) const {
    Artikel::ausgeben(stream);
    stream << "Farbe: " << getFarbe() << endl;
    stream << "Groesse: " << getGroesse() << endl;
}

Kleidung &Kleidung::operator=(const Kleidung &artikel) {
    Artikel::operator=(artikel);
    setGroesse(artikel.getGroesse());
    setFarbe(artikel.getFarbe());
    return *this;
}
