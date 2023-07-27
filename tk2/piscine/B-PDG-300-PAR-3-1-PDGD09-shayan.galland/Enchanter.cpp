#include "Enchanter.hpp"

Enchanter::Enchanter(const std::string &name ,int power) : Peasant(name, power)
{
    std::cout << _name << " learns magic from his spellbook." << std::endl;
}

Enchanter::~Enchanter()
{
    std::cout << _name << " closes his spellbook." << std::endl;
}

int Enchanter::attack()
{
    if (_health <= 0) {
        std::cout << _name  << " is out of combat." << std::endl;
        return 0;
    }
    std::cout << _name << " doesn't know how to fight." << std::endl;
    return 0;
}

int Enchanter::special()
{
    if (_health <= 0) {
        std::cout << _name  << " is out of combat." << std::endl;
        return 0;
    }
    if (_power < 50) {
        std::cout << _name << " is out of power." << std::endl;
        return 0;
    }
    _power-= 50;
    std::cout << _name << " casts a fireball." << std::endl;
    return 99;
}

void Enchanter::rest()
{
    if (_health <= 0) {
        std::cout << _name  << " is out of combat." << std::endl;
        return ;
    }
    std::cout << _name << " meditates." << std::endl;
    int ret = _power;
    if ((ret += 100) > 100)
        _power = 100;
    else
        _power += 100;
}
