#ifndef INPUT_HPP
#define INPUT_HPP

#include "../AComponent.hpp"

namespace nts
{
    class CInput : public nts::AComponent
    {
    public:
        CInput();
        nts::Tristate compute(std::size_t pin) override;
        void SetValue(nts::Tristate value) { _value = value; }

        void Print();

    private:
        nts::Tristate _value;
    };
}

#endif // INPUT_HPP
