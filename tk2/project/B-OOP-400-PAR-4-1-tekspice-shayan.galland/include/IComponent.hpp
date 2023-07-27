#ifndef _ICOMPONENT_HPP
#define _ICOMPONENT_HPP
#include <cstdio>
#include <iostream>

namespace nts
{
    enum Tristate
    {
        Undefined = (-true),
        True = true,
        False = false
    };

    nts::Tristate AND(nts::Tristate A, nts::Tristate B);
    nts::Tristate OR(nts::Tristate A, nts::Tristate B);
    nts::Tristate XOR(nts::Tristate A, nts::Tristate B);
    nts::Tristate NOT(nts::Tristate A);
    std::ostream& operator<<(std::ostream& stream, nts::Tristate A);

    class IComponent
    {
    public:
        virtual ~IComponent() = default;
        virtual void simulate(std::size_t tick) = 0;
        virtual nts::Tristate compute(std::size_t pin) = 0;
        virtual void setLink(std::size_t pin, nts::IComponent &other, std::size_t otherPin) = 0;
    };
}



#endif
