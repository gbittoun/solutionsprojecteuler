#include <iostream>
#include <set>

using namespace std;

#include "problem_31.hpp"

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

int problem_31()
{
    set<int> coins;
    coins.insert(1);
    coins.insert(2);
    coins.insert(5);
    coins.insert(10);
    coins.insert(20);
    coins.insert(50);
    coins.insert(100);
    coins.insert(200);

    long long count = 0;

    Computing::Combine(coins, coins.begin(), 200, count);

    cout << count << endl;

    return 0;
}
