#include <iostream>
#include <math.h>

using namespace std;


int main()
{
    long nbPrimes = 2;
    long primes[200000L];
    long idx;

    primes[0] = 2;
    primes[1] = 3;

    for(int x = 4 ; ; ++x)
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

        if(nbPrimes >= 8)
            break;
    }

    long result = 1;

    for(idx = 0 ; idx < nbPrimes ; ++idx)
    {
        result *= primes[idx];
    }

    cout << result << endl;

    long i = (long)sqrt(result);
    int nb;

    while(true)
    {
        result = (i*i+i)/2;
        nb = 0;

        for(long idx = 2 ; idx <= result / 2 ; ++idx)
        {
            if((result % idx) == 0)
                ++nb;
        }

        if(nb > 500)
            break;

        ++i;
    }

    // answer = 76576500
    cout << result << endl;

    return 0;
}
