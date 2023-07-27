#include "../../include/Component/output.hpp"
#include <iostream>

namespace nts {
    
    COutput::COutput()
    {
    }
    nts::Tristate COutput::compute(std::size_t pin)
    {
        return getLink(pin);
    }
    void COutput::Print()
    {
        std::cout << compute(1);
    }
}