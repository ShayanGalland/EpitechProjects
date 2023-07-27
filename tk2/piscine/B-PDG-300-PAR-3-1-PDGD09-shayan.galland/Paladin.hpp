#ifndef PALADIN_HPP
#define PALADIN_HPP
#include <iostream>
#include <string>
#include "Priest.hpp"
#include "Knight.hpp"

class Paladin : public Knight, public Priest  {
public:
    Paladin(const std::string &name, int power);
    ~Paladin();
    virtual int attack() override;
    virtual int special() override;
    virtual void rest() override;
    void damage(int damage);

};

#endif