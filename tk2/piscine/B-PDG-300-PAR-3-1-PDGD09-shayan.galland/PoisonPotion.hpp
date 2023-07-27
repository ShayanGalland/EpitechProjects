#ifndef POISONPOTION_HPP
#define POISONPOTION_HPP

#include "IPotion.hpp"

class PoisonPotion : public IPotion {
    public:
        PoisonPotion();
        ~PoisonPotion();
        virtual void effect(int &hp, int &power) const override;
        const char *getMessage() const {return " has been poisoned.";}

};

#endif
