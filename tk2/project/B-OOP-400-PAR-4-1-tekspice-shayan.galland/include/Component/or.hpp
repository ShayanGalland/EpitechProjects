#ifndef OR_HPP
#define OR_HPP

#include "../AComponent.hpp"

namespace nts
{
    class COr : public nts::AComponent
    {
    public:
        COr();
        nts::Tristate compute(std::size_t pin) override;
    };
}

#endif // OR_HPP
