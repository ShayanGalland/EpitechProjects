#ifndef _4030_HPP_
#define _4030_HPP_
#include "../AComponent.hpp"

namespace nts
{
    class C4030 : public AComponent
    {
    public:
        C4030();
        ~C4030() = default;
        nts::Tristate compute(std::size_t pin) override;
    };
}

#endif

