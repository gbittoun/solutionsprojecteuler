#include "problems/problem_65.hpp"

#include <iostream>
#include <set>
#include <math.h>

#include "Computing/IntegerOperations.hpp"

using namespace std;
using namespace Computing;

int main()
{
    set<long long> primes;
    FillPrimes(primes, 1500000LL);

    map<long long, long long> factor;

    for(long long x = 3000000LL ; x >= 2 ; --x)
    {
        map<long long, int> pd;
        Decompose(x * x - 1, primes, pd);

        long long D = 1;

        for(map<long long, int>::iterator it = pd.begin() ; it != pd.end() ; ++it)
        {
            if(it->second % 2 != 0)
                D *= it->first;
        }

        if(D > 1 && D <= 1000)
        {
            cout << x << " " << D << endl;
            factor[D] = x;
        }
    }

    cout << endl;

    for(map<long long, long long>::iterator it = factor.begin() ; it != factor.end() ; ++it)
    {
        cout << it->first << " " << it->second << endl;
    }

    return 0;
}
