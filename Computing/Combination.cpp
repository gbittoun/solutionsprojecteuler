#include "Combination.hpp"

namespace Computing
{
    long long Factorial(long long n)
    {
        if(n <= 1)
            return 1;
        else
            return n * Factorial(n-1);
    }

    void Combine(set<long long> & coins, set<long long>::iterator it, long long val, long long & count)
    {
        while(it != coins.end())
        {
            long long res = val - *it;
            if(res == 0)
                ++count;
            else if(res > 0)
                Combine(coins, it, res, count);

            ++it;
        }
    }
}
