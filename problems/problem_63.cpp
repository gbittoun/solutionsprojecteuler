#include "../Computing/FatNumber/FatNumber.hpp"
#include "../Computing/FatNumber/Power.hpp"

#include <iostream>

using namespace std;
using namespace Computing;


int main()
{
    int sum = 0;

    FatNumber<16> a;
    for(int idx = 1 ; idx < 10 ; ++idx)
    {
        int jdx = 1;

        while(true)
        {
            a = FatPower<16>(idx,jdx);
            int nb = a.NbDigits();
            if(nb == jdx)
            {
                ++sum;
                cout << a << endl;
            }
            else
                break;

            ++jdx;
        }
    }

    cout << endl << sum << endl;

    return 0;
}
