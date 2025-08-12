#include "Kasyno.hpp"
#include <iostream>
#include <fstream>


int main()
{

    int liczbaBotow = 0;
    int liczbaGraczy = 0;
    
    for(int i=0; i < 5; i++)
    {
        std::cout << "Podaj liczbę graczy (1-2): ";
        std::cin >> liczbaGraczy;
        if(liczbaGraczy >=1 && liczbaGraczy<=2)
            break;
        else
            std::cout << "Niepoprawna wartość. \n";
        if (std::cin.fail())
        {
            std::cin.clear();  // czysci flage bledu
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');  // Ignoruje nieprawidlowe znaki
            continue;
        }
    }
    
    for(int i=0; i < 5; i++)
    {
        std::cout << "Podaj liczbę botów (1-3): ";
        std::cin >> liczbaBotow;
        if(liczbaBotow >=1 && liczbaBotow <=3)
            break;
        else
            std::cout << "Niepoprawna wartość. \n";
        if (std::cin.fail())
        {
            std::cin.clear();  // czysci flage bledu
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');  // Ignoruje nieprawidlowe znaki
            continue;
        }
    }
        
    
    //Kasyno kasyno("Gracz1", "Gracz2", liczbaBotow);
    Kasyno kasyno(liczbaGraczy, liczbaBotow);
    kasyno.tasuj();
    kasyno.graj();
    kasyno.zapiszStan("/Users/bartek/Studia/Programowanie C++/projekt2_blackjack/projekt2_blackjack/WYNIKI.txt");

}

