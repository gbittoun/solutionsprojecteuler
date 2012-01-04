#include "problem_28.hpp"

#include <iostream>

using namespace std;

int problem_28()
{
    int last = 1;
    int n = 1;
    int side = 2*n + 1;

    long long sum = last;


    while(true)
    {
        if(side > 1001)
            break;

        for(int idx = 0 ; idx < 4 ; ++idx)
        {
            last += side - 1;
            cout << last << endl;
            sum += last;

            // Just in case it goes over (long long).MAX
            if(sum < 0)
                break;
        }

        // Just in case it goes over (long long).MAX
        if(sum < 0)
            break;

        ++n;
        side = 2*n+1;
    }

    cout << endl << sum << endl;

    return 0;
}
