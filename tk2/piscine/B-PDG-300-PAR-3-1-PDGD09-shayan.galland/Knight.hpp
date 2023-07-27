#ifndef KNIGHT_HPP
#define KNIGHT_HPP

#include <string.h>
#include <iostream>
#include "Peasant.hpp"


class Knight : public virtual Peasant
{

    public:
        Knight(const std::string &name , int power);
        ~Knight();
        virtual int attack () override;
        virtual int special () override;
        virtual void rest() override;
};

#endif