#include <iostream>
#include <set>
#include <map>

#include "problem_49.hpp"

#include "../Computing/DigitsOperations.hpp"

using namespace std;
using namespace Computing;

int problem_62()
{
    map<map<char,int>, set<long long>, DigitsComparer> buffer;

    for(long long idx = 1 ; idx < 1000000000LL ; ++idx)
    {
        map<char, int> digits;
        DigitsDecompose<10>(idx*idx*idx, digits);
        buffer[digits].insert(idx*idx*idx);
        if(buffer[digits].size() >= 5)
        {
            cout << buffer.size() << endl << endl;
            for(set<long long>::iterator it = buffer[digits].begin() ; it != buffer[digits].end() ; ++it)
                cout << *it << endl;

            break;
        }
    }

    return 0;
}
