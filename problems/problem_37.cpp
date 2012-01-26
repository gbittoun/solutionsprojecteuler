#include <iostream>
#include <set>
#include <math.h>

#include "problem_37.hpp"

using namespace std;

#include "../Computing/IntegerOperations.hpp"

int problem_37()
{
    set<long long> primes;
    Computing::FillPrimes(primes, 1000000);

    set<long long> trunc;

    set<long long>::reverse_iterator it = primes.rbegin();
    while(it != primes.rend())
    {
        bool isTruncatable = true;
        long long div = 10;
        while(*it > div)
        {
            long long left = *it / div;
            long long right = *it - left * div;

            if(primes.find(left) == primes.end() || primes.find(right) == primes.end())
            {
                isTruncatable = false;
                break;
            }

            div *=10;
        }

        if(isTruncatable)
        {
            trunc.insert(*it);
        }

        ++it;
    }

    long long sum = 0;

    set<long long>::iterator trunc_it = trunc.begin();
    while(trunc_it != trunc.end())
    {
        if(*trunc_it > 10)
            sum += *trunc_it;

        cout << *trunc_it<< endl;
        ++trunc_it;
    }

    cout << endl << sum << endl;

    return 0;
}
