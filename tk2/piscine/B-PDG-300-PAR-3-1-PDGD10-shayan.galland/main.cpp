#include "ABerry.hpp"
#include "ACitrus.hpp"
#include "AFruit.hpp"
#include "Almond.hpp"
#include "ANut.hpp"
#include "Hack.hpp"
#include "IFruit.hpp"
//#include "IFruitMixer.hpp"
#include "Lemon.hpp"
#include "Orange.hpp"
#include "Strawberry.hpp"
#include "FruitBox.hpp"
#include <iostream>

class TestFruit : public IFruit {
    public:
        ~TestFruit() override {std::cout << _name << " dies." << std::endl;}
        TestFruit(std::string name);
        unsigned int getVitamins() const override;
        std::string getName() const override;
        bool isPeeled() const override;
        void peel() override;
    private:
        std::string _name;
        bool _peeled;
        unsigned int _vitamins;
};

TestFruit::TestFruit(std::string name) : _name(name), _peeled(false), _vitamins(0) {std::cout << _name << " lives." << std::endl;}



unsigned int TestFruit::getVitamins() const {
    return _vitamins;
}

std::string TestFruit::getName() const {
    return _name;
}

bool TestFruit::isPeeled() const {
    return _peeled;
}

void TestFruit::peel() {
    _peeled = true;
}



int main(void)
{
FruitBox box (3);
const FruitBox& cref = box;
box.pushFruit(new TestFruit("Cerise"));
box.pushFruit(new TestFruit("Framboise"));
box.pushFruit(new TestFruit("Anis"));
std::cout << cref << std::endl;
IFruit* tmp = new TestFruit("Serge");
std::cout << box.pushFruit(tmp) << std::endl;
delete tmp;
tmp = box.popFruit ();
delete tmp;
std::cout << cref << std::endl;
return 0;
}
/*
int main(void)
{
Orange o;
Strawberry s;
Almond a;
IFruit& f = o;
std::cout << o.getName () << ": " << o.getVitamins () << " vitamins" << std::endl;
std::cout << s << std::endl;
std::cout << a << std::endl;
o.peel();
std::cout << f << std::endl;
s.peel();
std::cout << s << std::endl;
a.peel();
std::cout << a << std::endl;
return 0;
}*/