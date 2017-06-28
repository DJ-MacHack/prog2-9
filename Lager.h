/**
* @file: Lager.h
* @author:DJ MacHack
* @date: 23.05.2017.
* Matrnr.: 3747719
* mail@hendrik-haas.de
* Partner: Julian Bruna
*/

#ifndef INC_4_LAGER_H
#define INC_4_LAGER_H
#include <iostream>
#include <list>
#include <map>
#include <ctime>
#include "Artikel.h"
#include "Artikeldialog.h"


class Lager {
public:
    static const std::string LEERES_LAGER;
    static const std::string NEGATIVE_DIM;
    static const std::string NULL_DIM;
    static const std::string VOLLES_LAGER;
    static const std::string NICHT_DA;
    static const std::string SCHON_DA;
    Lager(const Lager& lager);
    Lager(std::string name, int dimension);
    Lager(int dimension);
    void addArtikel(Artikel* artikel);
    Artikel* newArtikel();
    void addNewArtikel();
    void deleteArtikel(Artikel artikel);
    void deleteArtikel(int artikelnummer);
    std::string getName() const;
    int getDimension() const;
    void bucheZugang(Artikel artikel, int menge);
    void bucheZugang(int artikelnummer, int menge);
    void bucheAbgang(Artikel artikel, int menge);
    void bucheAbgang(int artikelnummer, int menge);
    void changePreis(double prozent);
    void printLager();
    std::string toString() const;
    tm getDate() const {
        return *date;
    }
    void printCredits();
    Lager& operator=(const Lager& lager);
    friend ostream& operator<<(ostream& stream, const Lager& lager);
    const map<int, Artikel *> &getLagermap() const;
    virtual ~Lager();

private:
    int dimension;
    Artikeldialog artikeldialog;
    std::string name;
    void loescheArtikel();
    void setName(std::string name);
    void setDimension(int dimension);
    void setDate(tm date);
    std::map<int, Artikel*> lagermap;
    tm* date;
};


#endif //INC_4_LAGER_H
