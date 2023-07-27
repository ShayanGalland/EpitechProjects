#ifndef PICTURE_HPP
#define PICTURE_HPP
#include <iostream>

class Picture {
    public:
        std::string data;
        Picture();
        Picture(const std::string &file);
        Picture(const Picture &other);
        Picture& operator=(const Picture &other);
        ~Picture();
        bool getPictureFromFile(const std::string &file);
};


#endif