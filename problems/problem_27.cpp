#include <iostream>
#include <set>

using namespace std;


void recurse(const set<int> & p, int a, int b, int & n)
{
    if(p.find(n*n+a*n+b) != p.end())
        recurse(p, a, b, ++n);
}

int main()
{
    set<int> primes;
    primes.insert(2);
    primes.insert(3);

    for(int idx = 4 ; idx < 10000 ; ++idx)
    {
        bool isPrime = false;

        set<int>::iterator it = primes.begin();
        while(it != primes.end())
        {
            if(idx % *it == 0)
                break;
            else if(*it > idx / 2)
            {
                isPrime = true;
                break;
            }
            ++it;
        }

        if(isPrime)
            primes.insert(idx);
    }

    int maxCount = 0;
    int aval = 0, bval = 0;

    set<int>::iterator it = primes.begin();
    for(; it != primes.end() && (*it < 1000) ; ++it)
    {
        int b = *it;

        for(int a = -b ; a < 1000 ; a += 2)
        {
            int n = 0;
            recurse(primes, a, b, n);

            if(n > maxCount)
            {
                aval = a;
                bval = b;
                maxCount = n;

                cout << "new value : " << a << " " << b << " " << n << endl;
            }
            else if(n == maxCount)
            {
                cout << "bof value : " << a << " " << b << " " << n << endl;
            }
        }
    }

    cout << aval << " * " << bval << " = " << aval*bval << endl;

    return 0;
}
