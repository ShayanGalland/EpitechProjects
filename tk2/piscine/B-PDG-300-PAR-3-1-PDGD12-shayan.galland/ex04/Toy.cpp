#include <iostream>

#include "Toy.hpp"

Toy::Toy() : type(BASIC_TOY), name("toy"), picture()
{

}

Toy::Toy(ToyType type, const std::string &name, const std::string &file) : type(type), name(name), picture(file)
{

}

Toy::Toy(const Toy &other) : type(other.type), name(other.name), picture(other.picture)
{

}

Toy& Toy::operator=(const Toy &other)
{
    if (this != &other) {
        type = other.type;
        name = other.name;
        picture = other.picture;
    }
    return *this;
}

Toy::~Toy()
{

}

Toy::ToyType Toy::getType() const
{
    return type;
}

std::string Toy::getName() const
{
    return name;
}

void Toy::setName(const std::string &name)
{
    this->name = name;
}

bool Toy::setAscii(const std::string &file)
{
    return picture.getPictureFromFile(file);
}

std::string Toy::getAscii() const
{
    return picture.data;
}

void Toy::speak(std::string say)
{
    std::cout << name << " \"" << say << "\"" << std::endl;
}

std::ostream& operator << (std::ostream& out, Toy const &toy)
{
    out << toy.name << std::endl << toy.getAscii() << std::endl;
    return out;
}

Toy& Toy::operator<<(const char *prt)
{
    picture.data = std::string(prt);
    return (*this);
}