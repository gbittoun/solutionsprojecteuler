#include "problem_20.hpp"

using namespace Computing;

int problem_57()
{
    FatNumber<4096> a = 5;
    FatNumber<4096> b = 2;

    int sum = 0;

    for(int idx = 0 ; idx < 1000 ; ++idx)
    {
        if((a+b).NbDigits() > a.NbDigits())
        {
            ++sum;
            cout << (a+b) << " / " << a << endl;
        }

        FatNumber<4096> tmp = b + a * 2;
        b = a;
        a = tmp;
    }

    cout << endl << sum << endl;

    return 0;
}
