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
#include "Date.h"

class Lebensmittel : public Artikel {
public:
    Lebensmittel(int nummer, const string &name, int menge, double preis, int tag, int monat, int jahr);
    Lebensmittel(const Lebensmittel& artikel) = delete;
    Date* getDate() const {
        return  date;
    }
    bool pruefeMHD();
    virtual void ausgeben(std::ostream& stream) const;
private:
    Date* date;
};


#endif //INC_9_LEBENSMITTEL_H
