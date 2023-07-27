#include "FruitBox.hpp"

std::ostream& operator<<(std::ostream& out, const FruitBox& box)
{
    out << "[";
    for (unsigned int i = 0; i < box.nbFruits(); i++) {
        if (i == (box.nbFruits() - 1))
            out << *(box.getFruit(i));
        else
            out << *(box.getFruit(i)) << ", ";
    }
    out << "]";
    return out;
}

