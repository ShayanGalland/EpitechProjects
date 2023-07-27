#include "PowerPotion.hpp"

PowerPotion::PowerPotion()
{

}

PowerPotion::~PowerPotion()
{

}

void PowerPotion::effect(int &hp, int &power) const {
    hp = hp;
    if (power < 100) {
        power += 50;
        if (power > 100)
            power = 100;
    }
}
