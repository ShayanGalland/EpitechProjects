#include <fstream>
#include "Picture.hpp"


Picture::Picture() : data("")
{

}

Picture::Picture(const std::string &file)
{
    getPictureFromFile(file);
}

Picture::Picture(const Picture &other) : data(other.data)
{

}

Picture& Picture::operator=(const Picture &other)
{
    if (this != &other)
        data = other.data;
    return *this;
}

Picture::~Picture()
{

}

bool Picture::getPictureFromFile(const std::string &file)
{
    std::ifstream in(file);
    if (!in) {
        data = "ERROR";
        return false;
    }
    std::string line;
    data.clear();
    while (std::getline(in, line))
        data += line + '\n';
    return true;
}