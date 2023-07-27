#ifndef PRIEST_HPP
#define PRIEST_HPP

#include <string>
#include "Enchanter.hpp"

class Priest : public Enchanter {
public:
    Priest(const std::string &name, int power);
    ~Priest();
    virtual void rest() override;
};

#endif
