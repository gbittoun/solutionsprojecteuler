#include <iostream>

using namespace std;

int main()
{
    int primes[10001];
    int nbPrimes;

    primes[0] = 2;
    primes[1] = 3;
    nbPrimes = 2;

    int current = 4;

    while(nbPrimes < 10001)
    {
        int idx;

        for(idx = 0 ; idx < nbPrimes ; ++idx)
        {
            if(current % primes[idx] == 0)
                break;
        }

        if(idx == nbPrimes)
        {
            primes[nbPrimes++] = current;
        }

        ++current;
    }

    cout << primes[nbPrimes - 1] << endl;

    return 0;
}
