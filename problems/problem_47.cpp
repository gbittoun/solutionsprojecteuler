#include <iostream>
#include <set>
#include <map>

#include <math.h>

using namespace std;

#include "problem_47.hpp"
#include "problem_37.hpp"

namespace Computing
{
    void Decompose(long long n, set<long long> & primes, map<long long, int> & pd)
    {
        set<long long>::iterator it = primes.begin();
        while(it != primes.end())
        {
            while(n % *it == 0)
            {
                ++pd[*it];
                n /= *it;
            }

            if(*it > sqrt(ceil(n)))
                break;

            ++it;
        }

        if(n > 1)
            ++pd[n];
    }

    void DumpDecomposition(map<long long, int> & pd)
    {
        map<long long, int>::iterator it = pd.begin();
        while(it != pd.end())
        {
            cout << it->first << " : " << it->second << " , ";
            ++it;
        }
        cout << endl;
    }
}

int problem_47()
{
    set<long long> primes;
    Computing::FillPrimes(primes, 1000000LL);

    long long n = 3;

    while(true)
    {
        map<long long, int> pd0, pd1, pd2, pd3;
        Computing::Decompose(n, primes, pd0);
        Computing::Decompose(n+1, primes, pd1);
        Computing::Decompose(n+2, primes, pd2);
        Computing::Decompose(n+3, primes, pd3);

        if(pd0.size() == 4 && pd1.size() == 4 && pd2.size() == 4 && pd3.size() == 4)
        {
            cout << n << endl;
            Computing::DumpDecomposition(pd0);
            cout << n+1 << endl;
            Computing::DumpDecomposition(pd1);
            cout << n+2 << endl;
            Computing::DumpDecomposition(pd2);
            cout << n+3 << endl;
            Computing::DumpDecomposition(pd3);

            break;
        }

        ++n;
    }

    return 0;
}
