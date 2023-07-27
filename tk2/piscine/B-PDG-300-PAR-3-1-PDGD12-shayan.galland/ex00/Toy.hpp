#ifndef TOY_HPP
#define TOY_HPP


#include <iostream>
#include "Picture.hpp"


class Toy {
    public:
        enum ToyType {BASIC_TOY, ALIEN};
        Picture picturecp;
        Toy(): num(BASIC_TOY), _name("toy"), _picture("") {}
        Toy(ToyType type, std::string name, const std::string picture) : num(type), _name(name), _picture(picture) {picturecp.getPictureFromFile(picture);}
        ToyType getType() const;
        std::string getName() const;
        void setName(std::string name);
        bool setAscii(std::string picture);
        std::string getAscii() const;


    private:
        ToyType num;
        std::string _name;
        std::string _picture;
};

#endif