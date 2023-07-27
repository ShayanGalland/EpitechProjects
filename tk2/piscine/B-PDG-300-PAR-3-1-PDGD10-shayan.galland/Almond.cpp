#include "Almond.hpp"

unsigned int Almond::getVitamins() const
{
    if (isPeeled() != true)
        return 0;
    return 2;
}

std::string Almond::getName() const {
    return "almond";
}