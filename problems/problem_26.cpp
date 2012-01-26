#include "problem_26.hpp"

#include "../Computing/IntegerOperations.hpp"

#include <iostream>
#include <set>

using namespace std;

int problem_26()
{
    int maxCount = 0;
    int candidate = 0;

    for (int idx = 2 ; idx < 1000 ; ++idx)
    {
        int u = 1, d = idx;
        int count = 0;
        set<pair<int, int>, Computing::ComparePair> numbers;

        cout << d << " : ";

        while(u > 0)
        {
            ++count;

            while(u<d)
                u *= 10;

            cout << u/d;
            u %= d;

            if(numbers.find(make_pair<int, int>(u, d)) != numbers.end())
                break;
            else
                numbers.insert(make_pair<int, int>(u, d));
        }
        cout << endl;

        if(count > maxCount)
        {
            candidate = idx;
            maxCount = count;
        }
    }

    cout << "number " << candidate << " has " << maxCount << " decimal repetition and is the winner" << endl;

    return 0;
}
