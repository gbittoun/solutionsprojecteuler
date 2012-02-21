#include "Computing/IntegerOperations.hpp"

#include <iostream>
#include <math.h>

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

        if(nrj < nrj_tmp && --joker == 0)
            break;

        x = x_tmp;
        nrj = nrj_tmp;
    }

    return x;
}

#include "problems/problem_25.hpp"

int main()
{
    int sum = 0;

    for(int n = 2 ; n < 100 ; ++n)
    {
        if(ceil(sqrt(n)) != floor(sqrt(n)))
        {
            FatNumber<256> a = n;
            for(int i = 0 ; i < 220 ; ++i)
                a *= 10;

            FatNumber<256> b = GetIntegerSqrt(a);

            FatNumber<256>::DigitIterator it = b.GetIterator();
            //it.Next();

            for(int count = 0 ; count < 100 ; ++count)
            {
                sum += it.GetCurrent();
                it.Next();
            }
        }

        cout << n << " : " << sum << endl;
    }

    return 0;
}
