#include "problem_57.hpp"

#include "../Computing/FatNumber/FatNumber.hpp"

using namespace Computing;

int problem_57()
{
    FatNumber<1024> a = 5;
    FatNumber<1024> b = 2;

    int sum = 0;

    for(int idx = 0 ; idx < 1000 ; ++idx)
    {
        FatNumber<1024> c = (a+b);

        if(c.NbDigits() > a.NbDigits())
        {
            ++sum;
            cout << c << " / " << a << " : " << c.NbDigits() << " > " << a.NbDigits() << endl;
        }

        FatNumber<1024> tmp = a;
        a = b + a * 2;
        b = tmp;
    }

    cout << endl << sum << endl;

    return 0;
}
