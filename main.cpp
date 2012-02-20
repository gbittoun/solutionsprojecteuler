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
    FatNumber<200> a = 2;
    for(int i = 0 ; i < 200 ; ++i)
        a *= 10;

    cout << GetIntegerSqrt(a) << endl;

    return 0;
}
