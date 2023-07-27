#ifndef PIZZA_HPP_
#define PIZZA_HPP_
#include <vector>
#include <string>
#include <stdexcept>

class Pizza {
public:
    enum class Type {
        Regina = 1,
        Margarita = 2,
        Americana = 4,
        Fantasia = 8
    };
    enum class Size {
        S = 1,
        M = 2,
        L = 4,
        XL = 8,
        XXL = 16
    };
    Type type;
    Size size;
    std::vector<std::string> ingredients;
    bool operator==(const Pizza& other) const;
    Pizza(Type type, Size size);
    Pizza() = default;
};

#endif
