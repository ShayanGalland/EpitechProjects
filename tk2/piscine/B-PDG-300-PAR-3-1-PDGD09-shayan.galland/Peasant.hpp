#ifndef PEASANT_HPP
#define PEASANT_HPP
#include <string.h>
#include <iostream>
#include "ICharacter.hpp"
#include "HealthPotion.hpp"
#include "PoisonPotion.hpp"
#include "PowerPotion.hpp"

class Peasant : public ICharacter {
    protected:
        std::string _name;
        int _power;
        int _health;

    public:
        Peasant(const std::string &name , int power);
        ~Peasant();
        const std:: string &getName () const;
        int getPower () const;
        int getHp() const;
        void setPower (int power);
        void setHp (int health);
        virtual int attack ();
        virtual int special ();
        virtual void rest();
        void damage(int damage);
        virtual void drink(const IPotion &potion);
        virtual void drink(const HealthPotion &potion);
        virtual void drink(const PoisonPotion &potion);
        virtual void drink(const PowerPotion &potion);

};

#endif