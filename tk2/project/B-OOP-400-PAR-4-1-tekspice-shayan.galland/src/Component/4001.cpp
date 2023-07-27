#include "../../include/Component/4001.hpp"

namespace nts
{
    C4001::C4001()
    {
    }

    Tristate nts::C4001::compute(std::size_t pin)
    {
        if(pin == 3)
        {
            auto A = getLink(1);
            auto B = getLink(2);

            return nts::NOT(nts::OR(A, B));
        }
        else if(pin == 4)
        {
            auto A = getLink(5);
            auto B = getLink(6);

            return nts::NOT(nts::OR(A, B));
        }
        else if(pin == 10)
        {
            auto A = getLink(8);
            auto B = getLink(9);

            return nts::NOT(nts::OR(A, B));
        }
        else if(pin == 11)
        {
            auto A = getLink(12);
            auto B = getLink(13);

            return nts::NOT(nts::OR(A, B));
        }

        return nts::Tristate::Undefined;
    }
}
