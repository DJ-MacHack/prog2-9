/**
* @file: Elektrogeraete.h
* @author:DJ MacHack
* @date: 28.06.2017.
* Matrnr.: 3747719
* mail@hendrik-haas.de
*/

#ifndef INC_9_ELEKTROGERAETE_H
#define INC_9_ELEKTROGERAETE_H


#include "Artikel.h"

class Elektrogeraete : public Artikel {
public:
    Elektrogeraete(int nummer, const string &name, int menge, double preis, int kw);
    Elektrogeraete(const Elektrogeraete& artikel);
    virtual void ausgeben(std::ostream& stream) const;
    Elektrogeraete& operator=(const Elektrogeraete& artikel);
    int getKW() const {
        return kW;
    }

private:
    int kW;
    void setKW(int kW) {
        this->kW = kW;
    }
};


#endif //INC_9_ELEKTROGERAETE_H
