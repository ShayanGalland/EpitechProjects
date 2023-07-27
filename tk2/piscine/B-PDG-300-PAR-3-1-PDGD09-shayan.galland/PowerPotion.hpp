#ifndef POWERPOTION_HPP
#define POWERPOTION_HPP

#include "IPotion.hpp"

class PowerPotion : public IPotion {
    public:
        PowerPotion();
        ~PowerPotion();
        virtual void effect(int &hp, int &power) const override;
        const char *getMessage() const {return "' power is restored.";}

};

#endif
