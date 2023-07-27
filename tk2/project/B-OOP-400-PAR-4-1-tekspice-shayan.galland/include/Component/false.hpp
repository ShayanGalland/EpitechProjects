#ifndef FALSE_HPP
#define FALSE_HPP

#include "../AComponent.hpp"

namespace nts
{
    class CFalse : public nts::AComponent
    {
    public:
        CFalse();
        nts::Tristate compute(std::size_t pin) override;
    };
}

#endif // FALSE_HPP
