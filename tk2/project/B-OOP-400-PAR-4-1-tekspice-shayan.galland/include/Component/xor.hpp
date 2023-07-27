#ifndef XOR_HPP
#define XOR_HPP

#include "../AComponent.hpp"

namespace nts
{
    class CXor : public nts::AComponent
    {
    public:
        CXor();
        nts::Tristate compute(std::size_t pin) override;
    };
}

#endif // XOR_HPP
