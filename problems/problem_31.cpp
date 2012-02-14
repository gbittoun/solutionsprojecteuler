#include <iostream>
#include <set>

using namespace std;

#include "problem_31.hpp"

#include "../Computing/Combination.hpp"

int problem_31()
{
    set<long long> coins;
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
