//
// Created by DJ_MacHack on 09.05.2017.
// Mtknr.: 374771
// mail@hendrik-haas.de
// Partner: Julian Bruna
//

#ifndef INC_2_ARTIKEL_H
#define INC_2_ARTIKEL_H

#include<iostream>
using namespace std;

class Artikel {

public: Artikel(const Artikel& artikel);
        Artikel(int nummer, string name, int menge, double preis);
        void bucheZugang(int menge);
        void bucheAbgang(int menge);
        void  setBezeichnung(string name);
        int getBestand() const;
        string getBezeichnung() const;
        int getArtikelnummer() const;
        double getPreis() const;
        void setPreis(double preis);
        virtual Artikel& operator=(const Artikel& Artikel);
        friend std::ostream& operator<<(std::ostream& stream, const Artikel& artikel);
        virtual void ausgeben(std::ostream& stream) const;
        friend class Lager;
        friend class Lagerdialog;

protected:
        int bestand;
        string bezeichnung;
        int artikelnummer;
        double preis;
        void setArtikelnummer(int artikelnummer);
        void setBestand(int menge);
        virtual void clone(const Artikel& artikel);

};


#endif //INC_2_ARTIKEL_H
