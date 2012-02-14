#include "problem_76.hpp"

#include <iostream>
#include <set>

#include "problem_31.hpp"

#include "../Computing/Combination.hpp"

using namespace std;

int problem_76()
{
    set<long long> numbers;
    for(int idx = 1 ; idx < 100 ; ++idx)
        numbers.insert(idx);

    long long count = 0;

    Computing::Combine(numbers, numbers.begin(), 100, count);

    cout << count << endl;

    return 0;
}
