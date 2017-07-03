CC=gcc
CXX=g++
RM=rm -f
PR=lager
CPPFLAGS=-Wall -O2 -g -pedantic -std=c++14
SRCS=main.cpp Lager.cpp Lager.h Lagerdialog.cpp Lagerdialog.h Artikel.cpp Artikel.h Artikeldialog.cpp Artikeldialog.h Kleidung.cpp Kleidung.h Lebensmittel.cpp Lebensmittel.h Date.cpp Date.h Elektrogeraete.cpp Elektrogeraete.h
OBJS=$(subst .cc,.cpp,.h,.hh,.o,$(SRCS))
all: Lager
Lager: main.o Lager.o Artikel.o Artikeldialog.o Lagerdialog.o Lebensmittel.o Elektrogeraete.o Kleidung.o Date.o
	$(CXX) $(CPPFLAGS) -o lager main.o Lager.o Artikel.o Artikeldialog.o Lagerdialog.o Lebensmittel.o Elektrogeraete.o Kleidung.o Date.o
main.o: main.cpp
	$(CXX) $(CPPFLAGS) -c main.cpp
Lager.o: Lager.cpp 
	$(CXX) $(CPPFLAGS) -c Lager.cpp 
Lagerdialog.o: Lagerdialog.cpp 
	$(CXX) $(CPPFLAGS) -c Lagerdialog.cpp 
Artikeldialog.o: Artikeldialog.cpp 
	$(CXX) $(CPPFLAGS) -c Artikeldialog.cpp 
Artikel.o: Artikel.cpp 
	$(CXX) $(CPPFLAGS) -c Artikel.cpp
Lebensmittel.o: Lebensmittel.cpp
	$(CXX) $(CPPFLAGS) -c Lebensmittel.cpp
Elektrogeraete.o: Elektrogeraete.cpp
	$(CXX) $(CPPFLAGS) -c Elektrogeraete.cpp
Kleidung.o: Kleidung.cpp
	$(CXX) $(CPPFLAGS) -c Kleidung.cpp
Date.o: Date.cpp
	$(CXX) $(CPPFLAGS) -c Date.cpp
	
.PHONY: clean
clean:
	$(RM) $(PR) *.o *.gch

.PHONY: clear
clear:
	$(RM) *.o *.gch
