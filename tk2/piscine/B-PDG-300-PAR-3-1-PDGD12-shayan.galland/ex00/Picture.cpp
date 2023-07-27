#include "Picture.hpp"
#include <fstream>
#include <sstream>

Picture::Picture()
{
    data = "";
}

Picture::Picture(const std:: string &file)
{
    getPictureFromFile(file);
    std::cout << data << std::endl;
}

bool Picture::getPictureFromFile(const std::string &file)
{
    std::ifstream buf (file);
    std::stringstream getFile;

    if (file == "") {
        data = "";
        return true;
    }
    if (buf.good()) {
        getFile << buf.rdbuf();
        data = getFile.str();
        return true;
    }
    data = "ERROR";
    return false;
}