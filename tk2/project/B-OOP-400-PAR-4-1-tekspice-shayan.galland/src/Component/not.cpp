#include "../../include/Component/not.hpp"

namespace nts {
    
    CNot::CNot()
    {
    }
    nts::Tristate CNot::compute(std::size_t pin)
    {
        auto A = getLink(1);

        return nts::NOT(A);
    }
}