#include "../include/IComponent.hpp"

/*
0 0 0 0 0
0 1 0 1 1
0 U 0 U U
1 0 0 1 1
1 1 1 1 0
1 U U 1 U
U 0 0 U U
U 1 U 1 U
U U U U U
*/

namespace nts
{
    nts::Tristate AND(nts::Tristate A, nts::Tristate B)
    {
        if (A == nts::Tristate::False)
        {
            if (B == nts::Tristate::False) return nts::Tristate::False;
            if (B == nts::Tristate::True) return nts::Tristate::False;
            if (B == nts::Tristate::Undefined) return nts::Tristate::False;
        }
        else if (A == nts::Tristate::True)
        {
            if (B == nts::Tristate::False) return nts::Tristate::False;
            if (B == nts::Tristate::True) return nts::Tristate::True;
            if (B == nts::Tristate::Undefined) return nts::Tristate::Undefined;
        }
        else if (A == nts::Tristate::Undefined)
        {
            if (B == nts::Tristate::False) return nts::Tristate::False;
            if (B == nts::Tristate::True) return nts::Tristate::Undefined;
            if (B == nts::Tristate::Undefined) return nts::Tristate::Undefined;
        }

        return nts::Tristate::Undefined;
    }

    nts::Tristate OR(nts::Tristate A, nts::Tristate B)
    {
        if (A == nts::Tristate::False)
        {
            if (B == nts::Tristate::False) return nts::Tristate::False;
            if (B == nts::Tristate::True) return nts::Tristate::True;
            if (B == nts::Tristate::Undefined) return nts::Tristate::Undefined;
        }
        else if (A == nts::Tristate::True)
        {
            if (B == nts::Tristate::False) return nts::Tristate::True;
            if (B == nts::Tristate::True) return nts::Tristate::True;
            if (B == nts::Tristate::Undefined) return nts::Tristate::True;
        }
        else if (A == nts::Tristate::Undefined)
        {
            if (B == nts::Tristate::False) return nts::Tristate::Undefined;
            if (B == nts::Tristate::True) return nts::Tristate::True;
            if (B == nts::Tristate::Undefined) return nts::Tristate::Undefined;
        }

        return nts::Tristate::Undefined;
    }
    
    nts::Tristate XOR(nts::Tristate A, nts::Tristate B)
    {
        if (A == nts::Tristate::False)
        {
            if (B == nts::Tristate::False) return nts::Tristate::False;
            if (B == nts::Tristate::True) return nts::Tristate::True;
            if (B == nts::Tristate::Undefined) return nts::Tristate::Undefined;
        }
        else if (A == nts::Tristate::True)
        {
            if (B == nts::Tristate::False) return nts::Tristate::True;
            if (B == nts::Tristate::True) return nts::Tristate::False;
            if (B == nts::Tristate::Undefined) return nts::Tristate::Undefined;
        }
        else if (A == nts::Tristate::Undefined)
        {
            if (B == nts::Tristate::False) return nts::Tristate::Undefined;
            if (B == nts::Tristate::True) return nts::Tristate::Undefined;
            if (B == nts::Tristate::Undefined) return nts::Tristate::Undefined;
        }

        return nts::Tristate::Undefined;
    }

    nts::Tristate NOT(nts::Tristate A)
    {
        if(A != nts::Tristate::Undefined) 
        {
            return A == nts::Tristate::True ? nts::Tristate::False : nts::Tristate::True;
        }
        else 
        {
            return A;
        }
    }
    std::ostream& operator<<(std::ostream& stream, nts::Tristate A)
    {
        if(A == nts::Tristate::Undefined)
            stream << "U";
        else if(A == nts::Tristate::True)
            stream << "1";
        else if(A == nts::Tristate::False)
            stream << "0";

        return stream;
    }
}
