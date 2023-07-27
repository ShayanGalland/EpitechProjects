#include "../../include/Component/4069.hpp"

// NOT logic gates (4069)
//
//           +----4069----+
// in_01  -1-|>--+    ign-|-14-
//           |  _|_       |
//           |  \ /   +--<|-13- in_13
//           |   v   _|_  |
//           |   O   \ /  |
//           |   |    v   |
// out_02 -2-|<--+    O   |
//           |        |   |
// in_03  -3-|>--+    +-->|-12- out_12
//           |  _|_       |
//           |  \ /   +--<|-11- in_11
//           |   v   _|_  |
//           |   O   \ /  |
//           |   |    v   |
// out_04 -4-|<--+    O   |
//           |        |   |
// in_05  -5-|>--+    +-->|-10- out_10
//           |  _|_       |
//           |  \ /   +--<|-9-  in_09
//           |   v   _|_  |
//           |   O   \ /  |
//           |   |    v   |
// out_06 -6-|<--+    O   |
//           |        |   |
//        -7-|-ign    +-->|-8-  out_08
//           +------------+

namespace nts
{
    C4069::C4069()
    {
    }

    Tristate C4069::compute(std::size_t pin)
    {
        if(pin == 2)
        {
            auto A = getLink(1);
            return nts::NOT(A);
        }
        else if(pin == 4)
        {
            auto A = getLink(3);
            return nts::NOT(A);
        }
        else if(pin == 6)
        {
            auto A = getLink(5);
            return nts::NOT(A);
        }
        else if(pin == 8)
        {
            auto A = getLink(9);
            return nts::NOT(A);
        }
        else if(pin == 10)
        {
            auto A = getLink(11);
            return nts::NOT(A);
        }
        else if(pin == 12)
        {
            auto A = getLink(13);
            return nts::NOT(A);
        }

        return nts::Tristate::Undefined;
    }
}
