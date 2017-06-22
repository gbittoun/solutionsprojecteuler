#include <iostream>

using namespace std;


int main()
{
    long nbPrimes = 2;
    long primes[200000L];
    long idx;

    primes[0] = 2;
    primes[1] = 3;

    for(int x = 4 ; x < 2000000 ; ++x)
    {
        for(idx = 0 ; idx < nbPrimes ; ++idx)
        {
            if(x % primes[idx] == 0)
                break;
        }

        if(idx == nbPrimes)
        {
            primes[nbPrimes++] = x;
            cout << primes[nbPrimes-1] << " " << nbPrimes << endl;
        }
    }

    long long sum = 0;
    for(idx = 0 ; idx < nbPrimes ; ++idx)
        sum += primes[idx];

    cout << sum << endl;

    return 0;
}
