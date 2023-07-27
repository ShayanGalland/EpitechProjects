#ifndef _4001_HPP_
#define _4001_HPP_
#include "../AComponent.hpp"

namespace nts
{
    class C4001 : public AComponent
    {
    public:
        C4001();
        ~C4001() = default;
        nts::Tristate compute(std::size_t pin) override;
    };
}

#endif

