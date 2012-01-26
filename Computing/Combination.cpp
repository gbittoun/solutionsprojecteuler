#include "../Computing/Combination.hpp"

namespace Computing
{
    void Combine(set<int> & coins, set<int>::iterator it, int val, long long & count)
    {
        while(it != coins.end())
        {
            int res = val - *it;
            if(res == 0)
                ++count;
            else if(res > 0)
                Combine(coins, it, res, count);

            ++it;
        }
    }
}
