#include <set>

#include "problem_37.hpp"
#include "problem_46.hpp"

#include <iostream>
#include <math.h>

#include "../Computing/IntegerOperations.hpp"

using namespace std;

bool Test(set<long long> & p, long long idx)
{
    set<long long>::iterator it = p.begin();
    while(it != p.end())
    {
        if(*it > idx)
            break;

        long long test = (idx - *it) / 2;

        if(ceil(sqrt(test)) == floor(sqrt(test)))
            return true;

        ++it;
    }

    return false;
}

int problem_46()
{
    set<long long> p;
    Computing::FillPrimes(p, 10000);

    for(int idx = 3 ; idx < 10000 ; idx += 2)
    {
        if(p.find(idx) != p.end())
            continue;

        if(!Test(p, idx))
        {
            cout << idx << endl;
            break;
        }
    }

    return 0;
}
