#include "Gracz.hpp"
#include "Kasyno.hpp"
//#include <cstring>



void Gracz::wezKarte(Karta* _karta)
{
    if (liczba_kart < 10)
    {
        karty[liczba_kart++] = _karta;
        punkty += _karta->getWartosc();
    }
}

void Gracz::wyswietlKarty() 
{
    for (int i = 0; i < liczba_kart; ++i) 
    {
        karty[i]->wypisz();
        std::cout << " ";
    }
    std::cout << "\n";
}

void Gracz::dobierzKarte()
{
    if(czyJestKomputerowy())
    {
        if(!czyPass() && getPunkty() < 17)
        {
            wezKarte(kasyno->dajKarte());
            
        }
        if (getPunkty() >= 17)
        {
            pass = true;
        }
        
    }
    else
    {
        if (!pass)
        {
            wezKarte(kasyno -> dajKarte());
            std::cout << "\nDobrano karte. Karty po dobraniu:\n";
            wyswietlKarty();
            wyswietlPunkty();
        }
    }
    
}

void Gracz::spasuj()
{
    pass = true;
    if(getPunkty()>21)
        std::cout << getNazwa() << " Przegrana!\n";
    if(getPunkty()<21)
        std::cout <<"\n"<< getNazwa() << " pasuje!\n";

}
void Gracz::wyswietlPunkty()
{
    std::cout << "Punkty: " << punkty << "\n";
}

void Gracz::reset()
{
    liczba_kart = 0;
    punkty = 0;
    pass = false;
    for (int i = 0; i < 10; ++i)
    {
        if(karty[i] != nullptr)
        {
            karty[i] = nullptr;
        }
    }
}

Karta* Gracz::getKarta(int indeks) const 
{  // Dodajemy tę linię
    if (indeks >= 0 && indeks < liczba_kart) 
    {
        return karty[indeks];
    }
    return nullptr;
}


