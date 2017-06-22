#include "../Computing/IntegerOperations.hpp"

#include <iostream>
#include <math.h>

using namespace std;
using namespace Computing;

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
