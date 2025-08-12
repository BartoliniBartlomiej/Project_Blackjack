
#ifndef GRACZ_HPP
#define GRACZ_HPP

#include "Karta.hpp"

class Kasyno;

class Gracz
{
private:
    Karta* karty[10];
    int liczba_kart = 0;
    int punkty = 0;
    bool pass = 0;
    char nazwa[20];
protected:
    bool jestKomputerowy;
    Kasyno* kasyno;
    int odwaga = 0;
public:
    Gracz(Kasyno * _kasyno, const char* _nazwa, bool _jestKomputerowy = false, int _odwaga = 0) 
    : kasyno(_kasyno), jestKomputerowy(_jestKomputerowy), odwaga(_odwaga)
    {
        strncpy(nazwa, _nazwa, sizeof(nazwa));
        nazwa[sizeof(nazwa-1)] = '\0';
    }
    void wezKarte(Karta* _karta);
    void wyswietlKarty();
    void wyswietlPunkty();
    void dobierzKarte();
    void spasuj();
    bool czyPass() const { return pass; }
    int getPunkty() const { return punkty; }
    Karta* getKarta(int indeks) const;
    void reset(); // w przypadku nowej gry
    const char* getNazwa() const { return nazwa; }
    //const char* getKarta() const { return }
    int getLiczbaKart() const { return liczba_kart;}
    bool czyJestKomputerowy() const { return jestKomputerowy; }
    int getOdwaga() const {return odwaga;}
};

#endif // GRACZ_HPP
