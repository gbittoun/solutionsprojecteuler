#include "../Computing/Combination.hpp"

using namespace Computing;

long long FactorialSum(long long n)
{
    long long ret = 0;

    while(n)
    {
        ret += Factorial(n % 10);
        n /= 10;
    }

    return ret;
}

long long FactorialSumLoop(long long n)
{
    set<long long> s;
    s.insert(n);

    long long x = FactorialSum(n);

    while(s.find(x) == s.end())
    {
        s.insert(x);
        x = FactorialSum(x);
    }

    return s.size();
}

int main()
{
    long long sum = 0;

    for(long long n = 0 ; n < 1000000LL ; ++n)
    {
        if(FactorialSumLoop(n) == 60)
        {
            cout << n << endl;
            ++sum;
        }
    }

    cout << endl << sum << endl;

    return 0;
}
