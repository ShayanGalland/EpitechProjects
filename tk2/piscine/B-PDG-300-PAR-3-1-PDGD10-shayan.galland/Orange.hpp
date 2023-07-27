#ifndef ORANGE_HPP
#define ORANGE_HPP

#include "ACitrus.hpp"
#include <iostream>

class Orange : public ACitrus {
    public:
        unsigned int getVitamins() const override;
        std::string getName() const override;
};

#endif