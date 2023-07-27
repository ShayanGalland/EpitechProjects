#ifndef NOT_HPP
#define NOT_HPP

#include "../AComponent.hpp"

namespace nts
{
    class CNot : public nts::AComponent
    {
    public:
        CNot();
        nts::Tristate compute(std::size_t pin) override;
    };
}

#endif // NOT_HPP
