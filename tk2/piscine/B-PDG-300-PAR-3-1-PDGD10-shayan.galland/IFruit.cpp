
#include "IFruit.hpp"

std::ostream& operator<<(std::ostream& out, const IFruit& fruit)
{
    out << "[name: \"" << fruit.getName() << "\", vitamins: " << fruit.getVitamins() << ", peeled: " << (fruit.isPeeled() ? "true" : "false") << "]";
    return out;
}