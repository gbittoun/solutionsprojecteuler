#include "Computing/IntegerOperations.hpp"

#include <iostream>

using namespace std;
using namespace Computing;

template<typename T>
T GetIntegerSqrt(T a)
{
    T x = a;
    T nrj = x * x - a;

    while(true)
    {
        T x_tmp   = (x * x + a) / (x * 2);
        T nrj_tmp = x_tmp * x_tmp - a;

        if(nrj_tmp < nrj)
        {
            x = x_tmp;
            nrj = nrj_tmp;
        }
        else
            break;
    }

    return x;
}

int main()
{
    FatNumber<256> a = 2;
    for(int p = 0 ; p < 100 ; ++p)
        a *= 10;

    cout << GetIntegerSqrt(a) << endl;

    return 0;
}
