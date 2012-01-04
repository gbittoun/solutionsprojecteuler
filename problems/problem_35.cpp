#include "problem_35.hpp"

#include <iostream>
#include <set>

using namespace std;

long long NbDigits(long long x)
{
    long long div = 10;
    long long ret = 1;

    while(div <= x)
    {
        div *= 10;
        ++ret;
    }

    return ret;
}

long long CircShift(long long x, long long digits)
{
    long long div = 1;

    for(int idx  = 1 ; idx < digits ; ++idx)
        div *= 10;

    return (x / 10) + (x % 10) * div;
}

int problem_35()
{
    set<long long> primes;
    primes.insert(2);
    primes.insert(3);

    for(int idx = 5 ; idx < 1000000 ; idx += 2)
    {
        if (idx % 10001 == 0)
            cout << idx << endl;

        bool isPrime = false;

        set<long long>::iterator it = primes.begin();
        while(it != primes.end())
        {
            if(idx % *it == 0)
                break;
            else if(*it > idx / 2)
            {
                isPrime = true;
                break;
            }
            ++it;
        }

        if(isPrime)
        {
            primes.insert(idx);
            if (idx > 1000000)
                break;
        }
    }

    cout << "primes computing : done !" << endl;

    long long count = 0;

    set<long long>::iterator it = primes.begin();
    while(it != primes.end())
    {
        long long a = *it;
        bool isCircular = true;
        int n = NbDigits(*it);

        for(int idx = 0 ; idx < n ; ++idx)
        {
            a = CircShift(a, n);

            if(primes.find(a) == primes.end())
            {
                isCircular = false;
                break;
            }
        }

        if(isCircular)
        {
            cout << *it << endl;
            ++count;
        }

        ++it;
    }

    cout << endl << count << endl;

    return 0;
}
