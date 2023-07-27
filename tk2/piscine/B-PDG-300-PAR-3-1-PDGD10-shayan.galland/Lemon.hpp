#ifndef LEMON_HPP
#define LEMON_HPP
#include "ACitrus.hpp"
#include <iostream>

class Lemon : public ACitrus {
    public:
        unsigned int getVitamins() const override;
        std::string getName() const override;
};

#endif