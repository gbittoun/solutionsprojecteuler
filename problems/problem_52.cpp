#include "problem_52.hpp"
#include "problem_49.hpp"

#include <iostream>
#include <vector>
#include <map>

#include "../Computing/DigitsOperations.hpp"

using namespace std;
using namespace Computing;

int problem_52()
{
    map<map<char, int>, vector<long long>, DigitsComparer> result;

    for(long long idx = 100 ; ; ++idx)
    {
        map<map<char, int>, vector<long long>, DigitsComparer> nbIdentity;

        for(long long factor = 1 ; factor <= 6 ; ++factor)
        {
            long long r = idx * factor;
            map<char, int> digits;
            DigitsDecompose<10>(r, digits);

            nbIdentity[digits].push_back(r);
        }

        if(nbIdentity.size() == 1)
        {
            result = nbIdentity;
            break;
        }
    }

    for(map<map<char, int>, vector<long long>, DigitsComparer>::iterator it = result.begin() ; it != result.end() ; ++it)
    {
        for(vector<long long>::iterator vit = it->second.begin() ; vit != it->second.end() ; ++vit)
        {
            cout << *vit << endl;
        }
    }

    return 0;
}
