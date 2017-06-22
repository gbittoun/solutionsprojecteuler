#include "../Computing/IntegerOperations.hpp"

#include <iostream>
#include <set>

using namespace std;
using namespace Computing;


int main()
{
    set<int> abundants;

    for(int idx = 2 ; idx <= 28123 ; ++idx)
    {
        if(GetSum<int>(GetDivisors(idx)) > idx)
            abundants.insert(idx);
    }

    cout << "step 1 done !" << endl;
    cout << "abundants size = " << abundants.size() << endl;

    long long sum = 0;

    for(int idx = 1 ; idx < 28123 ; ++idx)
    {
        set<int>::iterator it = abundants.begin();
        set<int>::iterator bound = abundants.lower_bound(idx);

        bool isCorrect = false;

        while(it != bound)
        {
            if(abundants.find(idx - *it) != abundants.end())
            {
                isCorrect = true;
                break;
            }
            ++it;
        }

        if(!isCorrect)
        {
            sum += idx;
        }
    }

    cout << sum << endl;

    return 0;
}
