#include "Computing/IntegerOperations.hpp"

#include <iostream>

using namespace std;
using namespace Computing;

template<typename T>
T GetIntegerSqrt(T a)
{
    T x = a;
    T nrj = x * x - a;

    int joker = 10;

    while(true)
    {
        T x_tmp   = (x * x + a) / (x * 2);
        T nrj_tmp = x_tmp * x_tmp - a;

        cout << x_tmp << endl;

        if(nrj < nrj_tmp && --joker == 0)
            break;

        x = x_tmp;
        nrj = nrj_tmp;
    }

    return x;
}

int main()
{
    FatNumber<256> a = 99;
    for(int i = 0 ; i < 200 ; ++i)
        a *= 10;

    FatNumber<256> b = GetIntegerSqrt(a);
    cout << b << endl;
    cout << b.NbDigits() << endl;

    return 0;
}
