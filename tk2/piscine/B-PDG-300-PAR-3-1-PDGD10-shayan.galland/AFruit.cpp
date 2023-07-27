#include "AFruit.hpp"

AFruit::AFruit() : _peeled(false), _vitamins(0) {
  // constructor code
}

unsigned int AFruit::getVitamins() const {
    return _vitamins;
}

std::string AFruit::getName() const {
    return "AFruit";
}

bool AFruit::isPeeled() const {
    return _peeled;
}

void AFruit::peel() {
    _peeled = true;
}
