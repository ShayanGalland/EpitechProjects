#ifndef ENCHANTER_HPP
#define ENCHANTER_HPP

#include <string.h>
#include <iostream>
#include "Peasant.hpp"

class Enchanter : public virtual Peasant//, public ICharacter
{

    public:
        Enchanter(const std::string &name , int power);
        ~Enchanter();
        virtual int attack () override;
        virtual int special () override;
        virtual void rest() override;
};

#endif