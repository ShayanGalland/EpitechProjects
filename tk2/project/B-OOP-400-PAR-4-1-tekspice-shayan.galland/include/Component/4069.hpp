#ifndef _4069_HPP_
#define _4069_HPP_
#include "../AComponent.hpp"

namespace nts
{
    class C4069 : public AComponent
    {
    public:
        C4069();
        ~C4069() = default;
        nts::Tristate compute(std::size_t pin) override;
    };
}

#endif

