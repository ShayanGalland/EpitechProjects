#include "Priest.hpp"

Priest::Priest(const std::string &name, int power) : Peasant(name, power), Enchanter(name, power)
{
    std::cout << name << " enters in the order." << std::endl;
}

Priest::~Priest()
{
    std::cout << getName() << " finds peace." << std::endl;
}

void Priest::rest()
{
    if (_health <= 0) {
        std::cout << _name  << " is out of combat." << std::endl;
        return ;
    }
    _health = 100;
    _power = 100;
    std::cout << getName() << " prays." << std::endl;
}
