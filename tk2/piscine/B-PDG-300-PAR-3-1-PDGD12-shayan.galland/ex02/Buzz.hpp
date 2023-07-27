#ifndef BUZZ_HPP
#define BUZZ_HPP

#include "Toy.hpp"

class Buzz : public Toy {
public:
    Buzz(const std::string &name, const std::string &picture = "buzz.txt");
    ~Buzz();
};

#endif