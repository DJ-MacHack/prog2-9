/**
* @file: Kleidung.h
* @author:DJ MacHack
* @date: 28.06.2017.
* Matrnr.: 3747719
* mail@hendrik-haas.de
*/

#ifndef INC_9_KLEIDUNG_H
#define INC_9_KLEIDUNG_H


#include "Artikel.h"

class Kleidung : public Artikel{
public:
    Kleidung(int nummer, const string &name, int menge, double preis, string farbe, string groesse);
    Kleidung(const Kleidung& artikel);
    virtual void ausgeben(std::ostream& stream) const;
    const string &getFarbe() const {
        return farbe;
    }

    const string &getGroesse() const {
        return groesse;
    }

private:
    std::string farbe = "";
    std::string groesse = "";
    virtual void clone(const Kleidung artikel);
    void setFarbe(string farbe){
        this->farbe = farbe;
    }
    void setGroesse(string groesse) {
        this->groesse = groesse;
    }
};


#endif //INC_9_KLEIDUNG_H
