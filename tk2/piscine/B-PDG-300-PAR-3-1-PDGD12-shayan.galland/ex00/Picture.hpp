#ifndef PICTURE_HPP
#define PICTURE_HPP
#include <iostream>

class Picture {

    public:
        bool getPictureFromFile(const std:: string &file);
        ~Picture() {}
        Picture(const std:: string &file);
        Picture();
        std::string data;


};


#endif