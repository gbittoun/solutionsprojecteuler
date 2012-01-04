#include "problem_20.hpp"

using namespace Computing;

int problem_20()
{
    FatNumber<1024> x;
    x = 1;

    for(int idx = 2 ; idx <= 100 ; ++idx)
    {
        x.Print();
        cout << endl;
        x = x*idx;
    }

    x.Print();
    cout << endl << endl;

    cout << x.SumOfDigits() << endl;

    return 0;
}
