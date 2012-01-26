#include "problem_20.hpp"

#include "../Computing/FatNumber/FatNumber.hpp"

using namespace Computing;

int problem_20()
{
    FatNumber<1024> x;
    x = 1;

    for(int idx = 2 ; idx <= 100 ; ++idx)
    {
        cout << x << endl;
        x = x*idx;
    }

    cout << x << endl << endl;

    cout << x.SumOfDigits() << endl;

    return 0;
}
