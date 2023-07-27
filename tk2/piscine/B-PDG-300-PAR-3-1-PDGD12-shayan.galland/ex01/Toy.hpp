#ifndef TOY_HPP
#define TOY_HPP


#include "Picture.hpp"
#include <iostream>


class Toy {
    public:
        enum ToyType {BASIC_TOY, ALIEN};
        ToyType type;
        std::string name;
        Picture picture;
        Toy();
        Toy(ToyType type, const std::string &name, const std::string &file);
        Toy(const Toy &other);
        Toy& operator=(const Toy &other);
        ~Toy();
        ToyType getType() const;
        std::string getName() const;
        void setName(const std::string &name);
        bool setAscii(const std::string &file);
        std::string getAscii() const;
};

#endif