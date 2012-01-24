#include <math.h>
#include <iostream>
#include <set>

using namespace std;

#include "problem_58.hpp"
#include "problem_37.hpp"

namespace Computing
{
    bool IsPrime(set<long long> & p, long long n)
    {
        if(p.find(n) != p.end())
            return true;

        set<long long>::iterator it = p.begin();
        while(it != p.end())
        {
            if(n % *it == 0)
                return false;
            else if(*it > ceil(sqrt(n)))
                return true;

            ++it;
        }

        return true;
    }
}

using namespace Computing;

int problem_58()
{
    set<long long> primes;
    FillPrimes(primes, 1000000LL);

    long long last = 1;
    long long sidelength = 1;

    long long nbPrimes = 0;

    while(last <= (*primes.rbegin() * *primes.rbegin()))
    {
        sidelength += 2;

        for(int idx = 0 ; idx < 4 ; ++idx)
        {
            last += sidelength - 1;
            if(IsPrime(primes, last))
            {
                cout << last << endl;
                ++nbPrimes;
            }
        }

        cout << nbPrimes << "," << sidelength << " => " <<(nbPrimes / (float)(sidelength * 2 - 1)) << endl;

        if( (nbPrimes / (float)(sidelength * 2 - 1)) < 0.1f )
            break;
    }

    cout << endl << sidelength << endl;

    return 0;
}
