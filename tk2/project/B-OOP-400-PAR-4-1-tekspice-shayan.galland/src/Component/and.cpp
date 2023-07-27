#include "../../include/Component/and.hpp"

namespace nts {
    
    CAnd::CAnd()
    {
    }
    // A => Pin 1
    // B => Pin 2
    // Output => Pin 3
    // in_1  -1-+---\
    //          | &  |-3- out
    // in_2  -2-+---/
    nts::Tristate CAnd::compute(std::size_t pin)
    {
        auto A = getLink(1);
        auto B = getLink(2);

        return nts::AND(A, B);
    }
}