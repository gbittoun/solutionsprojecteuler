#include <iostream>
#include <set>
#include <math.h>

#include "problem_37.hpp"

using namespace std;

namespace Computing
{
    void FillPrimes(set<long long> & primes, long long max)
    {
        primes.clear();

        primes.insert(2);

        for(long long idx = 3 ; idx < max ; ++idx)
        {
            bool isPrime = true;

            set<long long>::iterator it = primes.begin();
            while(it != primes.end())
            {
                if(idx % *it == 0)
                {
                    isPrime = false;
                    break;
                }
                else if(*it > ceil(sqrt(idx)))
                    break;

                ++it;
            }

            if(isPrime)
                primes.insert(idx);

            if(idx % 100000 == 0)
                cout << idx << endl;
        }

        cout << "Primes computing finished !" << endl << endl;
    }
}


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
