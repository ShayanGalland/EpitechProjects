#ifndef _4071_HPP_
#define _4071_HPP_
#include "../AComponent.hpp"

namespace nts
{
    class C4071 : public AComponent
    {
    public:
        C4071();
        ~C4071() = default;
        nts::Tristate compute(std::size_t pin) override;
    };
}

#endif

