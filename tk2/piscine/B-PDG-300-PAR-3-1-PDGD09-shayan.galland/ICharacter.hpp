#ifndef ICHARACTER_HPP
#define ICHARACTER_HPP
#include <string>
#include <ostream>
#include <iostream>
#include "IPotion.hpp"
#include "PoisonPotion.hpp"
#include "PowerPotion.hpp"
#include "HealthPotion.hpp"

class ICharacter {
    public:
        virtual ~ICharacter() {}
        virtual const std:: string &getName () const = 0;
        virtual int getPower () const = 0;
        virtual int getHp() const = 0;
        virtual void setPower (int power) = 0;
        virtual void setHp (int health) = 0;
        virtual int attack () = 0;
        virtual int special () = 0;
        virtual void rest() = 0;
        virtual void damage(int damage) = 0;
        virtual void drink(const IPotion &potion) = 0;
        virtual void drink(const PoisonPotion &potion) = 0;
        virtual void drink(const PowerPotion &potion) = 0;
        virtual void drink(const HealthPotion &potion) = 0;
};
#endif