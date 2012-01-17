#include <iostream>
#include <map>
#include <set>

#include "problem_51.hpp"
#include "problem_37.hpp"

using namespace std;
using namespace Computing;

int problem_51()
{
    set<long long> primes;
    FillPrimes(primes, 1000000LL);

    bool found = false;

    map<int, bool> k0;
    map<int,int> k1;
    map<map<int, bool> , map<map<int,int>, set<long long> , DigitsMatching> , PatternMatching> values;

    for(set<long long>::iterator p0 = primes.lower_bound(100000LL) ; *p0 < 1000000LL ; ++p0)
    {
        set<long long>::iterator p1 = p0;
        for(++p1 ; *p1 < 1000000LL ; ++p1)
        {
            map<int, bool> pattern;
            map<int, int> digits;
            if(ComputeDigitsPattern<6, 10>(*p0, *p1, pattern, digits))
            {
                values[pattern][digits].insert(*p0);
                values[pattern][digits].insert(*p1);

                if(values[pattern][digits].size() >= 8)
                {
                    k0 = pattern;
                    k1 = digits;
                    found = true;

                    goto DisplayResult;
                }

                cout << *p0 << "," << *p1 << endl;
            }
        }
    }

DisplayResult:

    if(found)
    {
        cout << endl;
        for(set<long long>::iterator it = values[k0][k1].begin() ; it != values[k0][k1].end() ; ++it)
        {
            cout << *it << ",";
        }
        cout << endl;
    }
    else
        cout << "No result found :-(" << endl;

    return 0;
}
