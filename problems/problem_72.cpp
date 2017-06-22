#include "../Computing/IntegerOperations.hpp"

using namespace Computing;

int main()
{
    set<long long> primes;
    FillPrimes(primes, 1000000LL);

    long long nb = 0;
    for(long long n = 2 ; n <= 1000000LL ; ++n)
    {
        nb += Totient(n, primes);
    }

    cout << nb << endl;

    return 0;
}
