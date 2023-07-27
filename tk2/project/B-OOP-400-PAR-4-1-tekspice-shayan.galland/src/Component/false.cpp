#include "../../include/Component/false.hpp"

namespace nts {
    
    CFalse::CFalse()
    {
    }
    nts::Tristate CFalse::compute(std::size_t pin)
    {
        return nts::Tristate::False;
    }
}