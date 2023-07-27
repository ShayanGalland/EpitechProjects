#include "../include/pizza.hpp"

bool Pizza::operator==(const Pizza& other) const {
    return this->type == other.type
        && this->size == other.size
        && this->ingredients == other.ingredients;
}

Pizza::Pizza(Type type, Size size) : type(type), size(size) {

}

