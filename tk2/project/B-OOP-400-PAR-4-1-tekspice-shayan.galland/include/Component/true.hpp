#ifndef TRUE_HPP
#define TRUE_HPP

#include "../AComponent.hpp"

namespace nts
{
    class CTrue : public nts::AComponent
    {
    public:
        CTrue();
        nts::Tristate compute(std::size_t pin) override;
    };
}

#endif // TRUE_HPP
