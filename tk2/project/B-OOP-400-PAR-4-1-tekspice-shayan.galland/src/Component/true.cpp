#include "../../include/Component/true.hpp"

namespace nts {
    
    CTrue::CTrue()
    {
    }
    nts::Tristate CTrue::compute(std::size_t pin)
    {
        return nts::Tristate::True;
    }
}