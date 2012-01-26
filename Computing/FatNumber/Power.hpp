#ifndef FATPOWER_HPP
#define FATPOWER_HPP

#include "FatNumber.hpp"

namespace Computing
{
    template<int N>
    FatNumber<N> FatPower(int a, int b)
    {
        FatNumber<N> f = a;

        for(int idx = 0 ; idx < b ; ++idx)
        {
            f = f * a;
        }

        return f;
    }
}

#endif
