#ifndef GRACZKOMPUTEROWY_HPP
#define GRACZKOMPUTEROWY_HPP

#include "Gracz.hpp"


class Kasyno;

class GraczKomputerowy : public Gracz
{
private:
    bool jestKomputerowy = true;
    //int odwaga;
public:
    GraczKomputerowy(Kasyno* _kasyno, const char* _nazwa, int _odwaga) : Gracz(_kasyno, _nazwa, true, odwaga)
    {
        this->odwaga = _odwaga;
    }
    int getOdwaga() const {return odwaga; }
    bool czyJestKomputerowy() const { return true; }
};

#endif // GRACZKOMPUTEROWY_HPP
