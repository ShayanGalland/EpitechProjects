    #include "Paladin.hpp"

    Paladin::Paladin(const std::string &name, int power) : Peasant(name, power), Knight(name, power), Priest(name, power)
    {
        std::cout << Priest::_name << " fights for the light." << std::endl;
    }

    Paladin::~Paladin()
    {
        std::cout << Priest::_name << " is blessed." << std::endl;
    }

    int Paladin::attack()
    {
        return Knight::attack();
    }

    void Paladin::rest()
    {
        Priest::rest();
    }

    int Paladin::special()
    {
        return Enchanter::special();
    }

    void Paladin::damage(int damage)
    {
        Priest::damage(damage);
    }