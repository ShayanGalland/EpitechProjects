#include "Strawberry.hpp"

unsigned int Strawberry::getVitamins() const
{
    if (isPeeled() != true)
        return 0;
    return 6;
}

std::string Strawberry::getName() const
{
    return "strawberry";
}
