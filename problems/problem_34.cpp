#include <iostream>

#include "../Computing/Combination.hpp"

using namespace Computing;
using namespace std;


long long GetFactorialSum(long long x)
{
    long long div = 1;
    long long sum = 0;

    do
    {
        div *= 10;
        long long tmp = x - (x / div) * div;
        tmp = (tmp - (tmp % (div / 10))) / (div / 10);
        sum += Factorial(tmp);
    }
    while(div < x);

    return sum;
}

int main()
{
    long long sum = 0;

    for(long long idx = 3 ; idx < 1000000LL ; ++idx)
    {
        long long result = GetFactorialSum(idx);

        if(result == idx)
        {
            cout << idx << endl;
            sum += idx;
        }
    }

    cout << endl << sum << endl;

    return 0;
}

