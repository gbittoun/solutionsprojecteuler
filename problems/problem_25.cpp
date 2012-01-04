#include "problem_25.hpp"

#include "problem_20.hpp"

using namespace Computing;

int problem_25()
{
    FatNumber<1024> x, y;
    x = 1;
    y = 1;

    int ret = 2;

    while(true)
    {
        x += y;
        ++ret;

        if(x.NbDigits() == 1000)
            break;

        y += x;
        ++ret;

        if(y.NbDigits() == 1000)
            break;
    }

    cout << ret << endl;

    return 0;
}
