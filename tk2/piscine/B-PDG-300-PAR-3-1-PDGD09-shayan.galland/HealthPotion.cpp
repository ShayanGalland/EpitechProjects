#include "HealthPotion.hpp"

HealthPotion::HealthPotion() {}

HealthPotion::~HealthPotion() {}

void HealthPotion::effect(int &hp, int &power) const {
    power = power;
    if (hp < 100) {
        hp += 50;
        if (hp > 100)
            hp = 100;
    }
}