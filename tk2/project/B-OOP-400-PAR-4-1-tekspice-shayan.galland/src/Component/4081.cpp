#include "../../include/Component/4081.hpp"

namespace nts
{
    C4081::C4081()
    {
    }

    Tristate C4081::compute(std::size_t pin)
    {
        if(pin == 3) 
        {
            auto A = getLink(1);
            auto B = getLink(2);

            return nts::AND(A, B);
        }
        else if(pin == 4) 
        {
            auto A = getLink(5);
            auto B = getLink(6);

            return nts::AND(A, B);
        }
        else if(pin == 10) 
        {
            auto A = getLink(8);
            auto B = getLink(9);

            return nts::AND(A, B);
        }
        else if(pin == 11) 
        {
            auto A = getLink(12);
            auto B = getLink(13);

            return nts::AND(A, B);
        }

        return nts::Tristate::Undefined;
    }
}
