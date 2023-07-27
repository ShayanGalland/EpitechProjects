#include "Lemon.hpp"

unsigned int Lemon::getVitamins() const
{
    if (isPeeled() != true)
        return 0;
    return 4;
}
std::string Lemon::getName() const {
    return "lemon";
}