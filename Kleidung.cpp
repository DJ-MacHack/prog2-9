/**
* @file: Kleidung.cpp
* @author:DJ MacHack
* @date: 28.06.2017.
* Matrnr.: 3747719
* mail@hendrik-haas.de
*/

#include "Kleidung.h"
using namespace std;

Kleidung::Kleidung(int nummer, const string &name, int menge, double preis) : Artikel(nummer, name, menge, preis) {setFarbe();
setGroesse();
}

void Kleidung::setFarbe() {
    string color = "";
    cout << "Farbe der Kleidung: " << endl;
    cin >> color;
    this->farbe = color;
}

void Kleidung::setGroesse() {
    string size = "";
    cout << "Groesse der Kleidung" << endl;
    cin >> size;
    this->groesse = size;
}

void Kleidung::ausgeben(std::ostream &stream) const {
    Artikel::ausgeben(stream);
    stream << "Farbe: " << getFarbe() << endl;
    stream << "Groesse: " << getGroesse() << endl;
}
