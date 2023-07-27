#include "Orange.hpp"

unsigned int Orange::getVitamins() const
{
    if (isPeeled() != true)
        return 0;
    return 7;
}
std::string Orange::getName() const
{
    return "orange";
}