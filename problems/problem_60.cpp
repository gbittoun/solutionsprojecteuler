#include "problem_60.hpp"

#include <iostream>
#include <set>

using namespace std;

#include "problem_37.hpp"
#include "problem_58.hpp"

using namespace Computing;

long long ConcatInt(long long p0, long long p1)
{
    long long result = 0;
    long long f = 1;

    while(p0 > 0)
    {
        result += (p0 % 10) * f;
        p0 /= 10;
        f *= 10;
    }

    while(p1 > 0)
    {
        result += (p1 % 10) * f;
        p1 /= 10;
        f *= 10;
    }

    return result;
}

int problem_60()
{
    set<long long> primes;
    FillPrimes(primes, 1000000LL);

    for(set<long long>::iterator it0 = primes.begin() ; it0 != primes.end() ; ++it0)
    {
        for(set<long long>::iterator it1 = primes.begin() ; *it1 < *it0 ; ++it1)
        {
            if(IsPrime(primes, ConcatInt(*it0, *it1)) && IsPrime(primes, ConcatInt(*it1, *it0)))
            {
                for(set<long long>::iterator it2 = primes.begin() ; *it2 < *it1 ; ++it2)
                {
                    if(IsPrime(primes, ConcatInt(*it0, *it2)) && IsPrime(primes, ConcatInt(*it1, *it2)) &&
                       IsPrime(primes, ConcatInt(*it2, *it0)) && IsPrime(primes, ConcatInt(*it2, *it1)))
                    {
                        for(set<long long>::iterator it3 = primes.begin() ; *it3 < *it2 ; ++it3)
                        {
                            if(IsPrime(primes, ConcatInt(*it0, *it3)) && IsPrime(primes, ConcatInt(*it3, *it0)) &&
                               IsPrime(primes, ConcatInt(*it1, *it3)) && IsPrime(primes, ConcatInt(*it3, *it1)) &&
                               IsPrime(primes, ConcatInt(*it2, *it3)) && IsPrime(primes, ConcatInt(*it3, *it2))
                               )
                            {
                                for(set<long long>::iterator it4 = primes.begin() ; *it4 < *it3 ; ++it4)
                                {
                                    if(IsPrime(primes, ConcatInt(*it0, *it4)) && IsPrime(primes, ConcatInt(*it4, *it0)) &&
                                       IsPrime(primes, ConcatInt(*it1, *it4)) && IsPrime(primes, ConcatInt(*it4, *it1)) &&
                                       IsPrime(primes, ConcatInt(*it2, *it4)) && IsPrime(primes, ConcatInt(*it4, *it2)) &&
                                       IsPrime(primes, ConcatInt(*it3, *it4)) && IsPrime(primes, ConcatInt(*it4, *it3))
                                       )
                                    {
                                        cout << *it0 << " + " << *it1 << " + " << *it2 << " + " << *it3 << " + " << *it4;
                                        cout << " = " << (*it0 + *it1 + *it2 + *it3 + *it4) << endl;
                                        goto TheEnd;
                                    }
                                }
                            }
                        }
                    }
                }
            }
        }
    }

TheEnd:

    return 0;
}
