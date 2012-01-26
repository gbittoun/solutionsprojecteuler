#include "problem_50.hpp"

#include <iostream>
#include <set>

#include "problem_37.hpp"

#include "../Computing/IntegerOperations.hpp"

using namespace std;
using namespace Computing;

int problem_50()
{
    set<long long> primes;
    FillPrimes(primes, 1000000LL);

    set<long long>::reverse_iterator it_hi = primes.rbegin();
    set<long long>::reverse_iterator it_lo = it_hi;
    ++it_lo;
    long long total = *it_hi + *it_lo;

    while(true)
    {
        if(primes.find(total) != primes.end())
        {
            cout << total << " : ";
            long long count = 0;
            for(set<long long>::reverse_iterator it_disp = it_hi ; it_disp != it_lo ; ++it_disp)
            {
                ++count;
                //cout << *it_disp << ",";
            }
            cout << count << endl;
            //cout << endl;
        }

        if(total <= 1000000LL)
        {
            ++it_lo;
            if(it_lo == primes.rend())
                break;

            total += *it_lo;
        }
        else
        {
            total -= *it_hi;
            ++it_hi;
        }
    }

    return 0;
}
