#ifndef CLOCK_HPP
#define CLOCK_HPP

#include "../AComponent.hpp"

namespace nts
{
    class CClock : public nts::AComponent
    {
    public:
        CClock();
        nts::Tristate compute(std::size_t pin) override;
        void simulate(std::size_t tick) override;
        void SetValue(nts::Tristate value) { _value = value; }
        void Print();

    private:
        nts::Tristate _value;
    };
}

#endif // CLOCK_HPP
