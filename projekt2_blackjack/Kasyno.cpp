#include "Kasyno.hpp"
#include <cstdlib>
#include <ctime>
#include <iostream>
#include <fstream>
//#include <iomanip>





//Kasyno::Kasyno(const char* nazwa1, const char* nazwa2, int _liczbaBotow) : liczbaBotow(_liczbaBotow)
//{
//    int k = 0;
//    for (int i = 0; i < 4; ++i)
//    {
//        for (int j = 0; j < 13; ++j)
//        {
//            talia[k++] = new Karta(i, j);
//        }
//    }
//    
//    
//    gracze[0] = new Gracz(this, nazwa1);
//    gracze[1] = new Gracz(this, nazwa2);
//    
//    //int odwaga[] = {20, 18, 16};
//    for(int i = 0; i < liczbaBotow; i++)
//    {
//        if(i==0)
//            gracze[i + 2] = new GraczKomputerowy(this, "Bot1", 16);  // Gracz komputerowy
//        if(i==1)
//            gracze[i + 2] = new GraczKomputerowy(this, "Bot2", 18);  // Gracz komputerowy
//        if(i==2)
//            gracze[i + 2] = new GraczKomputerowy(this, "Bot3", 20);  // Gracz komputerowy
//    }
//
//    liczbaGraczy = 2 + liczbaBotow;
//    
//    
//}


Kasyno::Kasyno(int _liczbaGraczyL, int _liczbaBotow) : liczbaBotow(_liczbaBotow), liczbaGraczyL(_liczbaGraczyL)
{
    int k = 0;
    for (int i = 0; i < 4; ++i)
    {
        for (int j = 0; j < 13; ++j)
        {
            talia[k++] = new Karta(i, j);
        }
    }
    
    for(int i = 0; i < liczbaGraczyL; i++)
    {
        if(i==0)
            gracze[i] = new Gracz(this, "Gracz1");  
        if(i==1)
            gracze[i] = new Gracz(this, "Gracz2");
        //if(i==2)
            //gracze[i] = new Gracz(this, "Gracz3");
    }
    
    //int odwaga[] = {20, 18, 16};
    for(int i = 0; i < liczbaBotow; i++)
    {
        if(i==0)
            gracze[i + 2] = new GraczKomputerowy(this, "Bot1", 16);  // Gracz komputerowy
        if(i==1)
            gracze[i + 2] = new GraczKomputerowy(this, "Bot2", 18);  // Gracz komputerowy
        if(i==2)
            gracze[i + 2] = new GraczKomputerowy(this, "Bot3", 20);  // Gracz komputerowy
    }

    liczbaGraczy = liczbaGraczyL + liczbaBotow;
    
    
}


Kasyno::~Kasyno()
{
    for (int i = 0; i < liczbaGraczy; i++)
    {
        //std::cout<<"Wyw. Destr." << gracze[i]->getNazwa();
        delete gracze[i];
        
    }
    for(int i = 0; i < 52; i++)
    {
        delete talia[i];
    }
}


void Kasyno::tasuj()
{
    srand(time(0));
    for (int i = 0; i < 100; ++i) 
    {
        int index1 = rand() % 52;
        int index2 = rand() % 52;
        Karta* temp = talia[index1];
        talia[index1] = talia[index2];
        talia[index2] = temp;
    }
}

Karta* Kasyno::dajKarte() 
{
    if (indeks < 52) 
    {
        return talia[indeks++];
    }
    return nullptr;
}


void Kasyno::graj()
{
    int  wybor = 0;
    bool koniec = false; //koniec rozgrywki gdy 21 lub >21
    while (true)
    {
        std::cout << "1. Nowa gra\n";
        std::cout << "2. Wyjście\n";
        std::cout << "Wybierz opcję: ";
        std::cin >> wybor;

        // Zabezpieczenie strumienia wejścia
        if (std::cin.fail())
        {
            std::cin.clear();  // Czyści flagę błędu na strumieniu
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');  // Ignoruje nieprawidłowe znaki
            std::cout << "NIEPRAWIDŁOWY WYBÓR.\n";
            continue;  // Kontynuuje pętlę
        }
    
        if (wybor == 1)
        {
            nowaGra(liczbaBotow);
            koniec = false;
            while (!koniec)
            {
                koniec = true;
                for (int i = 0; i < 2+liczbaBotow; ++i)
                {
                    if(!gracze[i]->czyPass() && gracze[i]->getPunkty() < 21)
                    {
                        koniec = false;
                        if(gracze[i]->czyJestKomputerowy())
                        {
                            std::cout<<"\nTURA "<<gracze[i]->getNazwa()<<"\n";
                            gracze[i]->wyswietlKarty();
                            gracze[i]->wyswietlPunkty();
                            //bierze karte
                            if(gracze[i]->getPunkty() < gracze[i]->getOdwaga())
                            {
                                std::cout <<"BOT DOBRAŁ KARTE\n";
                                gracze[i]->dobierzKarte();
                                gracze[i]->wyswietlKarty();
                                gracze[i]->wyswietlPunkty();
                            }
                            
                            if(gracze[i]->getPunkty() >=gracze[i]->getOdwaga())
                            {
                                gracze[i]->spasuj();
                            }
//                            if(gracze[i]->getPunkty() != 21)
//                            {
//                                gracze[i]->wyswietlKarty();
//                                gracze[i]->wyswietlPunkty();
//                            }
                            if(gracze[i]->getPunkty()==21)
                                std::cout<<"Oczko!\n";
                        }
                        else
                        {
                            for(int b=0; b<5; b++)
                            {
                                std::cout << "\nGracz " << gracze[i]->getNazwa() << ", twoje karty:\n";
                                gracze[i]->wyswietlKarty();
                                gracze[i]->wyswietlPunkty();
                                std::cout << "1. Dobierz kartę\n";
                                std::cout << "2. Spasuj\n";
                                std::cout << "Wybierz opcję: ";
                                std::cin >> wybor;
                                // Zabezpieczenie strumienia wejścia
                                if (std::cin.fail())
                                {
                                    std::cin.clear();  // Czyści flagę błędu na strumieniu
                                    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');  // Ignoruje nieprawidłowe znaki
                                    std::cout << "NIEPRAWIDŁOWY WYBÓR.\n";
                                    continue;  // Kontynuuje pętlę
                                }
                                if(wybor != 1 && wybor != 2)
                                {
                                    std::cout << "NIEPRAWIDŁOWY WYBÓR.\n";
                                    continue;
                                }
                                else
                                    break;
                            }
                            
                            if (wybor == 1)
                            {
                                gracze[i]->dobierzKarte();
                            }
                            else if (wybor == 2)
                            {
                                gracze[i]->spasuj();
                            }
                            if(gracze[i]->getPunkty()==21)
                            {
                                std::cout << "\nGracz " << gracze[i]->getNazwa() << ", twoje karty:\n";
                                gracze[i]->wyswietlKarty();
                                gracze[i]->wyswietlPunkty();
                                std::cout << "21! Oczko!\n";
                                break;
                            }
                            if(gracze[i]->getPunkty() > 21)
                            {
                                std::cout << "Przegrana! \n";
                            }
                        }
                    }
                    //jezeli oczko
                    if(gracze[i]->getPunkty()==21 && i==1)
                    {
                        std::cout << "\nGracz " << gracze[i]->getNazwa() << ", twoje karty:\n";
                        gracze[i]->wyswietlKarty();
                        gracze[i]->wyswietlPunkty();
                        std::cout << "Oczko!\n";
                    }
                    
                    
                }
                
                    
            }
            wyznaczZwyciezce();
            wyswietlWyniki();
        } 
        else
            if (wybor == 2)
            {
                break;
            }
            if (wybor != 2)
                std::cout << "NIEPRAWIDŁOWY WYBÓR.\n";
    }
}


void Kasyno::nowaGra(int liczbaBotow)
{
    indeks = 0;
    
    tasuj();
    if(numerRozgrywki != 0)
    {
        //gracze[0]->reset();  // Resetujemy gracza
        //gracze[1]->reset();  // Resetujemy gracza
        for(int i = 0; i < liczbaGraczy; ++i)
        {
            gracze[i]->reset();
        }
    }
    
    for (int i = 0; i < liczbaGraczy; ++i)
    {
        for(int j=0; j<2; j++)
        {
            gracze[i]->wezKarte(dajKarte());
        }
    }
    numerRozgrywki++;
    std::cout << "\nRozgrywka: "<< numerRozgrywki <<std::endl;
}




void Kasyno::wyznaczZwyciezce()
{
    
    int maxPunkty = 0;
    int zwyciezca = -1;
//    int zwyciezca2= -1;
//    int zwyciezca3= -1;
//    int zwyciezca4= -1;
//    int zwyciezca5= -1;
//    int liczbaZwyciezcow =0; //juz jeden jest
    
//    if(numerRozgrywki!=1)
//    {
//        maxPunkty = 0;
//        zwyciezca = zwyciezca2 =zwyciezca3 = zwyciezca4 = zwyciezca5 = -1;
//    }
//
    for (int i = 0; i < liczbaGraczy; ++i)
    {
        if (gracze[i]->getPunkty() > maxPunkty && gracze[i]->getPunkty() <= 21)
        {
            maxPunkty = gracze[i]->getPunkty();
            zwyciezca = i;
            //liczbaZwyciezcow++;
        }
//        if(gracze[i]->getPunkty() == maxPunkty && liczbaZwyciezcow >=2)  //przypadek wiecej niz 1 wygranego
//        {
//            if(i == 1)
//                zwyciezca2 = i;
//            if(i == 2)
//                zwyciezca3 = i;
//            if(i == 3)
//                zwyciezca4 = i;
//            if(i == 4)
//                zwyciezca5 = i;
//        }
    }
    if (zwyciezca != -1)
    {
        std::cout << "Zwycięzca to gracz numer " << zwyciezca + 1 << " z " << maxPunkty << " punktami.\n";
    }
    else
    {
        std::cout << "Brak zwycięzcy.\n";
    }
}


void Kasyno::wyswietlWyniki()
{
    std::cout << "\n";
    std::cout << "====================\n";
    std::cout.width(18);
    std::cout << "WYNIKI rozgrywki" << std::endl;
    for(int i = 0; i < liczbaGraczy; i++)
    {
        std::cout << "|";
        std::cout << gracze[i]->getNazwa();
        std::cout << "\n|";
        gracze[i]->wyswietlKarty();
        std::cout << "|";
        gracze[i]->wyswietlPunkty();
        if(i<liczbaGraczy-1)
            std::cout << "--------------------\n";
    }
    std::cout << "====================\n";

}

void Kasyno::zapiszStan(const std::string& nazwaPliku)
{
    std::ofstream plik;
    plik.open(nazwaPliku, std::ifstream::out);
    if (!plik.is_open())
    {
        std::cerr << "Nie można otworzyć pliku do zapisu.\n";
        return;
    }
    int maxNazwaLength = 10;  // Maksymalna długość nazwy gracza
    int maxKartyLength = 50;  // Maksymalna liczba kart * 3 (figura, kolor i spacja)
    int maxPunktyLength = 3;  // Maksymalna długość punktów

    for(int k = 0; k < numerRozgrywki; k++)
    {
        plik << "Numer rozgrywki: " << k+1 << "\n";
        
        for (int i = 0; i < 5; ++i)
        {
            plik << std::left << std::setw(maxNazwaLength) << gracze[i]->getNazwa() << "  ";
            for (int j = 0; j < gracze[i]->getLiczbaKart(); ++j)
            {
                Karta* karta = gracze[i]->getKarta(j);
                if (karta != nullptr)
                {
                    plik <<  karta->getFigura()<<"[" <<karta->getKolor() << "] ";
                }
            }
            plik << std::setw(maxKartyLength - (5 * gracze[i]->getLiczbaKart())) << " ";  // Wypełniamy resztę pola spacjami
            plik << "  Punkty: " << std::right << std::setw(maxPunktyLength) << gracze[i]->getPunkty() << "\n";
        }
        plik << "\n";
    }
    
    plik.close();
}
