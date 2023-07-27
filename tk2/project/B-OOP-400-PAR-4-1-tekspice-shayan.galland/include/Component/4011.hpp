#ifndef _4011_HPP_
#define _4011_HPP_
#include "../AComponent.hpp"

namespace nts
{
    class C4011 : public AComponent
    {
    public:
        C4011();
        ~C4011() = default;
        nts::Tristate compute(std::size_t pin) override;
    };
}

#endif

