#include "../Computing/IntegerOperations.hpp"
#include "../Computing/Combination.hpp"

using namespace Computing;

int problem_77()
{
    set<long long> primes;

    long long n = 15;

    while(true)
    {
        ++n;
        FillPrimes(primes, n);

        long long count = 0;
        Combine(primes, primes.begin(), n, count);

        cout << n << " => " << count << endl;

        if(count >= 5000)
            break;
    }

    cout << endl << n << endl;

    return 0;
}
