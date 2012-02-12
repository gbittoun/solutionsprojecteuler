#include <string.h>
#include <iostream>

#include "../Computing/Combination.hpp"

using namespace Computing;

template<int N>
class NumberPyramid
{
    int v[N];

    public :

    typedef struct{int a[N];} PyramidArray;

    NumberPyramid(int v_in[N])
    {
        for(size_t idx = 0 ; idx < sizeof(v) / sizeof(int) ; ++idx)
            v[idx] = v_in[idx];
    }

    PyramidArray GetCombination(long long num) const
    {
        PyramidArray ret;
        int memv[N];
        memcpy(memv, v, N * sizeof(int));

        num = num % Factorial(N);

        for(int idx = N - 1 ; idx >= 0 ; --idx)
        {
            long long div = Factorial(idx);
            int outIdx = num / div;
            num %= div;

            ret.a[N - 1 - idx] = memv[outIdx];
            for(int jdx = outIdx ; jdx < N - 1 ; ++jdx)
                memv[jdx] = memv[jdx + 1];
        }

        return ret;
    }
};

int problem_24();
