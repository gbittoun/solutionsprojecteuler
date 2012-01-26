#include <iostream>
#include <sstream>
#include <set>

#include "problem_32.hpp"

using namespace std;

#include "../Computing/DigitsOperations.hpp"

int problem_32()
{
    set<int> results;

    for(int idx = 1, jdx = 1 ; (jdx < 10000) || (jdx = 0) || (++idx < 100); ++jdx)
    {
        set<char> digits;
        int globalLength = 0;

        ostringstream os1;
        ostringstream os2;
        ostringstream os3;

        os1 << idx;
        os2 << jdx;
        os3 << (idx * jdx);

        globalLength += os1.str().size();
        globalLength += os2.str().size();
        globalLength += os3.str().size();

        Computing::PushDigits(digits, os1.str());
        Computing::PushDigits(digits, os2.str());
        Computing::PushDigits(digits, os3.str());

        if((globalLength == 9) && (digits.size() == 9) && (digits.find('0') == digits.end()))
        {
            results.insert(idx * jdx);
            cout << idx << " * " << jdx << " = " << idx * jdx << endl;
        }
    }

    long long sum = 0;
    set<int>::iterator it = results.begin();
    while(it != results.end())
    {
        sum += *it;
        ++it;
    }

    cout << endl << "result : " << sum << endl;

    return 0;
}
