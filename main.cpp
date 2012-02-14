#include "Computing/IntegerOperations.hpp"
#include "Computing/Combination.hpp"

using namespace Computing;

int main()
{
    set<long long> primes;
    FillPrimes(primes, 1000000LL);

    long long n = 15;

    while(true)
    {
        ++n;

        long long count = 0;
        Combine(primes, primes.begin(), n, count);

        if(count >= 5000)
            break;
        else
            cout << n << " => " << count << endl;
    }

    cout << endl << n << endl;

    return 0;
}
