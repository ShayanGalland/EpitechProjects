#include "PoisonPotion.hpp"

PoisonPotion::PoisonPotion()
{

}

PoisonPotion::~PoisonPotion()
{

}

void PoisonPotion::effect(int &hp, int &power) const
{
    power = power;
    if (hp > 0) {
        hp -= 50;
        if (hp < 0)
            hp = 0;
    }
}
