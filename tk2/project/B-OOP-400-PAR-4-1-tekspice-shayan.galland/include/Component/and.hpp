#ifndef AND_HPP
#define AND_HPP

#include "../AComponent.hpp"

namespace nts
{
    class CAnd : public nts::AComponent
    {
    public:
        CAnd();
        nts::Tristate compute(std::size_t pin) override;
    };
}

#endif // AND_HPP
