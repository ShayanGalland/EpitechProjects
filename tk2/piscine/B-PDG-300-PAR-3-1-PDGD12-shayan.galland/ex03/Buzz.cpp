#include "Buzz.hpp"

Buzz::Buzz(const std::string &name, const std::string &file) : Toy(Toy::WOODY, name, file)
{

}

Buzz::~Buzz()
{

}

void Buzz::speak(std::string say)
{
    std::cout << "BUZZ: " << name << " \"" << say << "\"" << std::endl;
}