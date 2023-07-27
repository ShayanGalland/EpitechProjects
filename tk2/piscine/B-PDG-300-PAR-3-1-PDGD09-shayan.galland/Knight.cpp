#include "Knight.hpp"
#include "Peasant.hpp"

Knight::Knight(const std::string &name ,int power) : Peasant(name, power)
{
    std::cout << _name << " vows to protect the kingdom." << std::endl;
}

Knight::~Knight()
{
    std::cout << _name << " takes off his armor." << std::endl;
}

int Knight::attack()
{
    if (_health <= 0) {
        std::cout << _name  << " is out of combat." << std::endl;
        return 0;
    }
    if (_power < 10) {
        std::cout << _name << " is out of power." << std::endl;
        return 0;
    }
    _power -= 10;
    std::cout << _name << " strikes with his sword." << std::endl;
    return 20;
}

int Knight::special()
{
    if (_health <= 0) {
        std::cout << _name  << " is out of combat." << std::endl;
        return 0;
    }
    if (_power < 30) {
        std::cout << _name << " is out of power." << std::endl;
        return 0;
    }
    _power -= 30;
    std::cout << _name << " impales his enemy." << std::endl;
    return 50;
}

void Knight::rest()
{
    if (_health <= 0) {
        std::cout << _name  << " is out of combat." << std::endl;
        return ;
    }
    std::cout << _name << " eats." << std::endl;

    int ret = _power;
    if ((ret += 50) > 100)
        _power = 100;
    else
        _power += 50;
}