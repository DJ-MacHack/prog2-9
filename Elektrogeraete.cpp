/**
* @file: Elektrogeraete.cpp
* @author:DJ MacHack
* @date: 28.06.2017.
* Matrnr.: 3747719
* mail@hendrik-haas.de
*/

#include "Elektrogeraete.h"

/**
 * constructor
 * @param nummer
 * @param name
 * @param menge
 * @param preis
 * @param kw
 */
Elektrogeraete::Elektrogeraete(int nummer, const string &name, int menge, double preis, int kw) : Artikel(nummer, name, menge,
                                                                                                  preis) {
    this->kW = kw;
}

/**
 * copy constructor
 * @param artikel
 */
Elektrogeraete::Elektrogeraete(const Elektrogeraete &artikel): Artikel(artikel.getArtikelnummer(), artikel.getBezeichnung(), artikel.getBestand(),
                                                                       artikel.getPreis()) {
    this->kW = artikel.getKW();
}

/**
 * cout
 * @param stream
 */
void Elektrogeraete::ausgeben(std::ostream &stream) const {
    Artikel::ausgeben(stream);
    stream << "Verbrauch in kW: " << getKW() << endl;
}
