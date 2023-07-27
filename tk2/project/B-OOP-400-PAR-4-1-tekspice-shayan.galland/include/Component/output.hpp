#ifndef OUTPUT_HPP
#define OUTPUT_HPP

#include "../AComponent.hpp"

namespace nts
{
    class COutput : public nts::AComponent
    {
    public:
        COutput();
        nts::Tristate compute(std::size_t pin) override;

        void Print();
    };
}

#endif // COUTPUT_HPP
