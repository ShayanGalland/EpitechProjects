#ifndef _4081_HPP_
#define _4081_HPP_
#include "../AComponent.hpp"

namespace nts
{
    class C4081 : public AComponent
    {
    public:
        C4081();
        ~C4081() = default;
        nts::Tristate compute(std::size_t pin) override;
    };
}

#endif

