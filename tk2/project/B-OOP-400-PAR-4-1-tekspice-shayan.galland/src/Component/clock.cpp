#include "../../include/Component/clock.hpp"

namespace nts {
    
    CClock::CClock() : _value(nts::Tristate::Undefined)
    {
    }
    nts::Tristate CClock::compute(std::size_t pin)
    {
        return _value;
    }

    void CClock::simulate(std::size_t tick)
    {
        if(_value != nts::Tristate::Undefined) 
        {
            _value = _value == nts::Tristate::True ? nts::Tristate::False : nts::Tristate::True;
        }
    }
    void CClock::Print()
    {
        std::cout << _value;
    }
}