using namespace std;

#include <set>
#include <iostream>

#include "problem_37.hpp"
#include "problem_49.hpp"

namespace Computing
{
    template<int DIGITS, int BASE>
    void DigitsDecompose(long long n, map<char, int> & digits)
    {
        for(int idx = 0 ; idx < DIGITS ; ++idx)
        {
            ++digits[n % BASE];
            n /= BASE;
        }
    }
}

#include <vector>

using namespace Computing;

int problem_49()
{
    set<long long> primes;
    Computing::FillPrimes(primes, 10000LL);

    map<map<char, int>, set<long long>, DigitsComparer> numbers;

    for(set<long long>::reverse_iterator it = primes.rbegin() ; it != primes.rend() ; ++it)
    {
        if(*it < 1000)
            break;

        map<char, int> dc;
        DigitsDecompose<4,10>(*it, dc);
        numbers[dc].insert(*it);
    }

    for(map<map<char, int>, set<long long>, DigitsComparer>::iterator it = numbers.begin() ; it != numbers.end() ; ++it)
    {
        if(it->second.size() >= 3)
        {
            for(set<long long>::iterator sit0 = it->second.begin() ; sit0 != it->second.end() ; ++sit0)
            {
                for(set<long long>::iterator sit1 = sit0 ; ++sit1 != it->second.end() ; )
                {
                    if( it->second.find(*sit1 - *sit0 + *sit1) != it->second.end())
                        cout << *sit0 << "," << *sit1 << "," << (*sit1 - *sit0 + *sit1) << endl;
                }
            }
        }
    }

    return 0;
}

