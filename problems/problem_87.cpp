#include "problem_87.hpp"

#include "../Computing/IntegerOperations.hpp"

#include <set>

using namespace std;
using namespace Computing;

int problem_87()
{
    set<long long> primes;
    FillPrimes(primes, 1000000LL);

    set<long long> previous;

    int count = 0;

    for(set<long long>::iterator i = primes.begin() ; (*i) < 8000 ; ++i)
    {
        for(set<long long>::iterator j = primes.begin() ; (*j) < 8000 ; ++j)
        {
            if(*i**i + *j**j**j > 50000000LL)
                break;

            for(set<long long>::iterator k = primes.begin() ; (*k) < 8000 ; ++k)
            {
                long long result = *i**i + *j**j**j + *k**k**k**k ;
                if(result <= 50000000LL)
                {
                    if(previous.find(result) == previous.end())
                    {
                        count++;
                        previous.insert(result);
                    }
                }
                else
                    break;
            }
        }
    }

    cout << count << endl;

    return 0;
}
