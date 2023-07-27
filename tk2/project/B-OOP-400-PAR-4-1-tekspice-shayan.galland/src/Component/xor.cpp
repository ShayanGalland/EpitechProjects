#include "../../include/Component/xor.hpp"

namespace nts {
    
    CXor::CXor()
    {
    }
    nts::Tristate CXor::compute(std::size_t pin)
    {
        auto A = getLink(1);
        auto B = getLink(2);

        return nts::XOR(A, B);
    }
}