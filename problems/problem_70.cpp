#include "../Computing/IntegerOperations.hpp"
#include "../Computing/DigitsOperations.hpp"

using namespace std;
using namespace Computing;

#include <iostream>

int problem_70()
{
    set<long long> primes;
    FillPrimes(primes, 1000000LL);

    map<float, pair<long long, long long> > results;

    for(long long n = 10000000LL ; n > 5000000LL ; --n)
    {
        long long t = totient(n, primes);

        map<char, int> d0, d1;
        DigitsDecompose<10>(n, d0);
        DigitsDecompose<10>(t, d1);

        set<map<char, int>, DigitsComparer> s;
        s.insert(d0);

        if(s.find(d1) != s.end())
        {
            cout << n << " , " << t << endl;

            results[n / (float) t] = make_pair(n, t);
        }
    }

    cout << endl << results.begin()->second.first << " " << results.begin()->second.second << endl;

    return 0;
}
