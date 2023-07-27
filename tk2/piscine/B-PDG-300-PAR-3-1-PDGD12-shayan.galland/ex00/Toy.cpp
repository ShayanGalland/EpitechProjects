#include "Toy.hpp"
#include <fstream>
#include <sstream>



std::string Toy::getAscii() const
{

    return picturecp.data;
}

std::string Toy::getName() const
{
    return _name;
}

Toy::ToyType Toy::getType() const
{
    return num;
}

bool Toy::setAscii(std::string pictureFile)
{
    return picturecp.getPictureFromFile(pictureFile);
}

void Toy::setName(std::string name)
{
    _name = name;
}

