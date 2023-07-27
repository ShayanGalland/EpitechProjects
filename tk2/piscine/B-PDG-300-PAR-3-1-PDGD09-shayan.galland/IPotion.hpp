#ifndef IPOTION_HPP
#define IPOTION_HPP

#include <string>

class IPotion {
    public:
        IPotion() {}
        virtual ~IPotion() {}
        virtual void effect(int &hp, int &power) const = 0;
        virtual const char *getMessage() const {return " drinks a mysterious potion.";}

};
#endif
