#include "../../include/Component/input.hpp"
#include <iostream>

namespace nts {
    
    CInput::CInput() : _value(nts::Tristate::Undefined)
    {
    }
    nts::Tristate CInput::compute(std::size_t pin)
    {
        return _value;
    }
    void CInput::Print()
    {
        std::cout << _value;
    }
}