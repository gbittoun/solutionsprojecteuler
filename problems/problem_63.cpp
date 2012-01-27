#include "problem_63.hpp"

#include "../Computing/FatNumber/FatNumber.hpp"
#include "../Computing/FatNumber/Power.hpp"

#include <iostream>

using namespace std;
using namespace Computing;

int problem_63()
{
    int sum = 0;

    FatNumber<1024> a;
    for(int idx = 1 ; idx < 10 ; ++idx)
    {
        for(int jdx = 1 ; jdx < 23 ; ++jdx)
        {
            a = FatPower<1024>(idx,jdx);
            int nb = a.NbDigits();
            if(nb == jdx)
            {
                ++sum;
                cout << a << endl;
            }
        }
    }

    cout << sum << endl;

    return 0;
}
