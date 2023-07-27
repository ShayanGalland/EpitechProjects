#include <iostream>
#include "Skat.hpp"

Skat::Skat(const std::string &name, int stimPaks)
{
    _name = name;
    _stimPaks = stimPaks;
}

Skat::~Skat()
{

}

int Skat::stimPaks() const
{
    return _stimPaks;
}

const std::string &Skat::name() const
{
    return _name;
}

void Skat::shareStimPaks(int number, Skat &stock)
{
    if (number > _stimPaks) {
        std::cout << "Don't be greedy" << std::endl;
        return;
    }
    _stimPaks -= number;
    stock._stimPaks += number;
    std::cout << "Keep the change." << std::endl;
}

void Skat::addStimPaks(unsigned int number)
{
    if (number == 0) {
        std::cout << "Hey boya, did you forget something?" << std::endl;
        return;
    }
    _stimPaks += number;
}

void Skat::useStimPaks()
{
    if (_stimPaks > 0) {
        _stimPaks--;
        std::cout << "Time to kick some ass and chew bubble gum." << std::endl;
    } else {
        std::cout << "Mediiiiiic" << std::endl;
    }
}

void Skat::status() const
{
    std::cout << "Soldier " << _name << " reporting " << _stimPaks << " stimpaks remaining sir!" << std::endl;
}
