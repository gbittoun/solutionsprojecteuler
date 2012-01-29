#include "problem_65.hpp"

#include "../Computing/FatNumber/FatNumber.hpp"

using namespace Computing;

int problem_65()
{
    FatNumber<128> n = 0, d = 1;

    for(int idx = 33 ; idx >= 1 ; --idx)
    {
        FatNumber<128> tmp = d + n;
        n = d;
        d = tmp;

        cout << n << " / " << d << endl;

        tmp = d * 2 * idx + n;
        n = d;
        d = tmp;

        cout << n << " / " << d << endl;

        tmp = d + n;
        n = d;
        d = tmp;

        cout << n << " / " << d << endl;
    }

    cout << endl << (n + d * 2).SumOfDigits() << endl;

    return 0;
}
