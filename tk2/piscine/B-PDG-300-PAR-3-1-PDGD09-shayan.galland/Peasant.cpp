#include "Peasant.hpp"

Peasant::Peasant(const std::string &name ,int power) : _name(name), _power(power), _health(100)
{
    std::cout << _name << " goes for an adventure." << std::endl;
}

Peasant::~Peasant()
{
    std::cout << _name << " is back to his crops." << std::endl;
}

const std::string &Peasant::getName() const
{
    return (_name);
}

int Peasant::getPower() const
{
    return (_power);
}

int Peasant::getHp() const
{
    return (_health);
}

int Peasant::attack()
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
    std::cout << _name << " tosses a stone." << std::endl;
    return 5;
}

int Peasant::special()
{
    if (_health <= 0) {
        std::cout << _name  << " is out of combat." << std::endl;
        return 0;
    }
    std::cout << _name << " doesn't know any special move." << std::endl;
    return 0;
}

void Peasant::rest()
{
    if (_health <= 0) {
        std::cout << _name  << " is out of combat." << std::endl;
        return ;
    }
    std::cout << _name << " takes a nap." << std::endl;

    int ret = _power;
    if ((ret += 30) > 100)
        _power = 100;
    else
        _power += 30;
}

void Peasant::damage(int damage)
{
    int ret = _health;
    if ((ret-= damage) <= 0) {
        std::cout << _name  << " is out of combat." << std::endl;
        _health = 0;
        return ;
    }
    _health -= damage;
    std::cout << _name << " takes " << damage << " damage." << std::endl;
}

void Peasant::setPower (int power)
{
    _power = power;
}

void Peasant::setHp (int health)
{
    _health = health;
}

void Peasant::drink(const IPotion &potion) {
    int hp = getHp();
    int power = getPower();
    potion.effect(hp, power);
    std::cout << getName() << " drinks a mysterious potion." << std::endl;
    setHp(hp);
    setPower(power);
}
void Peasant::drink(const HealthPotion &potion) {
    int hp = getHp();
    int power = getPower();
    potion.effect(hp, power);
    std::cout << getName() << potion.getMessage() << std::endl;
    setHp(hp);
    setPower(power);
}
void Peasant::drink(const PoisonPotion &potion) {
    int hp = getHp();
    int power = getPower();
    potion.effect(hp, power);
    std::cout << getName() << potion.getMessage() << std::endl;
    setHp(hp);
    setPower(power);
}
void Peasant::drink(const PowerPotion &potion) {
    int hp = getHp();
    int power = getPower();
    potion.effect(hp, power);
    std::cout << getName() << potion.getMessage() << std::endl;
    setHp(hp);
    setPower(power);
}