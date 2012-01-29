#include "problem_64.hpp"

#include "../Computing/IntegerOperations.hpp"

#include <iostream>

using namespace std;
using namespace Computing;

int problem_64()
{
    long long sum = 0;

    for(long long idx = 0 ; idx < 10000 ; ++idx)
    {
        vector<long long> a;
        GetSqrtCoeff(idx, a);

        cout << idx << " : ";
        for(vector<long long>::iterator it = a.begin() ; it != a.end() ; ++it)
            cout << *it << ",";
        cout << endl;

        if(a.size() > 1 && ((a.size() - 1) % 2) != 0)
            ++sum;
    }

    cout << endl << sum << endl;


    return 0;
}
