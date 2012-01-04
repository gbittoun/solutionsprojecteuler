#include "problem_34.hpp"

#include "problem_24.hpp"

#include <iostream>

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
        sum += factorial(tmp);
    }
    while(div < x);

    return sum;
}

int problem_34()
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

