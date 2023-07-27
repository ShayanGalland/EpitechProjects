#ifndef STRAWBERRY_HPP
#define STRAWBERRY_HPP

#include <iostream>
#include "ABerry.hpp"

class Strawberry : public ABerry {
    public:
        unsigned int getVitamins() const override;
        std::string getName() const override;
};


#endif