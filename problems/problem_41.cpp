#include "problem_41.hpp"

#include <iostream>
#include <set>
#include <sstream>

#include "problem_37.hpp"

#include "../Computing/IntegerOperations.hpp"

using namespace std;
using namespace Computing;

int problem_41()
{
    set<long long> primes;
    FillPrimes(primes, 10000000);

    set<long long>::iterator it = primes.begin();

    while(it != primes.end())
    {
        ostringstream stream;
        stream << *it;
        set<int> digits;

        bool useless = false;

        for(size_t idx = 0 ; idx < stream.str().size() ; ++idx)
        {
            if(digits.find(stream.str().c_str()[idx]) != digits.end())
            {
                useless = true;
                break;
            }
            digits.insert(stream.str().c_str()[idx]);
        }

        if(useless)
        {
            ++it;
            continue;
        }

        if(*digits.begin() == '1' && digits.size() == (unsigned int)(*digits.rbegin() - *digits.begin() + 1) )
            cout << *it << endl;

        ++it;
    }

    return 0;
}
