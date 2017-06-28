/**
* @file: Lebensmittel.h
* @author:DJ MacHack
* @date: 28.06.2017.
* Matrnr.: 3747719
* mail@hendrik-haas.de
*/

#ifndef INC_9_LEBENSMITTEL_H
#define INC_9_LEBENSMITTEL_H

#include <ctime>
#include "Artikel.h"

class Lebensmittel : public Artikel {
public:
    Lebensmittel(int nummer, const string &name, int menge, double preis);
    Lebensmittel(const Lebensmittel& artikel) = delete;
    tm* getDate() const {
        return  date;
    }
    bool pruefeMHD();
    virtual void ausgeben(std::ostream& stream) const;
private:
    tm* date;
    void setDate();
};


#endif //INC_9_LEBENSMITTEL_H
