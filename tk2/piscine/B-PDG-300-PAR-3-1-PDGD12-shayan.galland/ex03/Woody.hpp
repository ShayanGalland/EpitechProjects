#ifndef WOODY_HPP
#define WOODY_HPP

#include "Toy.hpp"

class Woody : public Toy {
    public:
        Woody(const std::string &name, const std::string &picture = "woody.txt");
        ~Woody();
        void speak(std::string say) override;
};

#endif