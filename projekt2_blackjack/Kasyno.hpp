#include "Gracz.hpp"
#include "GraczKomputerowy.hpp"

#include <fstream>
#include <string>

class Kasyno
{
protected:
    Karta* talia[52];
    int indeks = 0;
    Gracz* gracze[5];
    int numerRozgrywki = 0;
    int liczbaBotow;
    int liczbaGraczyL;
    int liczbaGraczy;
    
public:
    //Kasyno(const char* nazwa1, const char* nazwa2, int _liczbaBotow);
    Kasyno(int _liczbaGraczyL, int _liczbaBotow);
    ~Kasyno();
    void tasuj();
    Karta* dajKarte();
    void graj();
    void nowaGra(int liczbaBotow);
    void wyznaczZwyciezce();
    void zapiszStan(const std::string& nazwaPliku);
    void wyswietlWyniki();
    void aktualizujWyniki(int indeksGracza);
    void resetujWyniki();
    void inicjalizujWyniki();
};

