#include "../Computing/FatNumber/Power.hpp"

using namespace Computing;


int main()
{
    int sum = 0;

    for(int idx = 1 ; idx <= 100 ; ++idx)
    {
        for(int jdx = 1 ; jdx <= 100 ; ++jdx)
        {
            FatNumber<1024> f = FatPower<1024>(idx, jdx);

            int sd = f.SumOfDigits();
            cout << sd << endl;

            if(sd > sum)
            {
                sum = sd;
            }
        }
    }

    cout << endl << sum << endl;

    return 0;
}
