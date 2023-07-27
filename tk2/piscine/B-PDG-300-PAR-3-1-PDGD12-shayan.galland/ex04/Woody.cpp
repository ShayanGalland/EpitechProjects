#include "Woody.hpp"

Woody::Woody(const std::string &name, const std::string &file) : Toy(Toy::WOODY, name, file)
{

}

Woody::~Woody()
{

}

void Woody::speak(std::string say)
{
    std::cout << "WOODY: " << name << " \"" << say << "\"" << std::endl;
}