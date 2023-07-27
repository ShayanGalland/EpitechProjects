#ifndef HEALTHPOTION_HPP
#define HEALTHPOTION_HPP

#include "IPotion.hpp"

class HealthPotion : public IPotion {
    public:
        HealthPotion();
        ~HealthPotion();
        virtual void effect(int &hp, int &power) const override;
        const char *getMessage() const {return " feels rejuvenated.";}
};

#endif
