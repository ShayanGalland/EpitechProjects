#include <vector>
#include <iostream>
#include "IFruit.hpp"

class FruitBox {
    public:
        FruitBox(unsigned int size) : _size(size) {}
        ~FruitBox() {
            for (auto& fruit : _fruits) {
                delete fruit;
            }
        }

        IFruit *getFruit(int i) const {return _fruits[i];}

        unsigned int getSize() {
            return _size;
        }

        unsigned int nbFruits() const {
            return _fruits.size();
        }

        bool pushFruit(IFruit * fruit) {
            if (nbFruits() >= _size || checkFruitInBox(fruit))
                return false;
            _fruits.push_back(fruit);
            return true;
        }

        IFruit * popFruit() {
            if (nbFruits() == 0)
                return nullptr;
            IFruit* fruit = _fruits.front();
            _fruits.erase(_fruits.begin());
            return fruit;
        }

        bool checkFruitInBox(IFruit * fruit) {
            for (auto& f : _fruits) {
                if (f == fruit)
                    return true;
            }
            return false;
        }


    private:
        std::vector<IFruit*> _fruits;
        unsigned int _size;
};

std::ostream& operator<<(std::ostream& out, const FruitBox& box);
