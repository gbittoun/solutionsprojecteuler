#include <iostream>
#include <set>

#include "../Computing/Combination.hpp"

using namespace std;


int main()
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
