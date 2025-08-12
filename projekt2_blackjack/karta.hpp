#include <iostream>

class Karta {
private:
    //std::string kolor;
    char kolor;
    char figura;
    int wartosc;
public:
    Karta(int _kolor = 0, int _wartosc = 0);
    void setKolor(int _kolor);
    void setWartosc(int _wartosc);
    //std::string getKolor() const { return kolor; }
    char getKolor() const { return kolor; }
    char getFigura() const { return figura; }
    int getWartosc() const { return wartosc; }
    void wypisz() const { std::cout << figura << "[" <<kolor<< "]"; }
};
