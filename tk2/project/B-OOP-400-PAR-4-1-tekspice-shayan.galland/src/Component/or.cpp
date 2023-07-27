#include "../../include/Component/or.hpp"

namespace nts {
    
    COr::COr()
    {
    }
    nts::Tristate COr::compute(std::size_t pin)
    {
        auto A = getLink(1);
        auto B = getLink(2);

        return nts::OR(A, B);
    }
}