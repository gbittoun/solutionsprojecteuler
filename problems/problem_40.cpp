#include "problem_40.hpp"

#include <iostream>

using namespace std;

long long pow10(long long p)
{
    long long result = 1;

    while(p--)
        result *= 10;

    return result;
}

long long log10(long long p)
{
    long long result = 0;

    while(p /= 10)
        ++result;

    return result;
}

int problem_40()
{
    long long idx = 1;
    long long count = 0;
    long long last = -1;

    while(true)
    {
        count += log10(idx) + 1;

        if(last < log10(count))
        {
            cout << count<< " : " << idx << endl;
            last = log10(count);
        }

        if(count > 1000000)
            break;

        ++idx;
    }

    return 0;
}
