#ifndef ALMOND_HPP
#define ALMOND_HPP

#include <iostream>
#include "ANut.hpp"

class Almond : public ANut {
    public:
        unsigned int getVitamins() const override;
        std::string getName() const override;
};

#endif