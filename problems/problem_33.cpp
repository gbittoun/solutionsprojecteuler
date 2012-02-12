#include "problem_33.hpp"

#include "../Computing/IntegerOperations.hpp"

#include <iostream>

using namespace std;
using namespace Computing;

int problem_33()
{
    long long finalUp = 1;
    long long finalDown = 1;

    for(int idx = 1 , jdx = 1 ; (jdx < 100) || (jdx = 0) || (++idx < 100) ; ++jdx )
    {
        int u;
        int d;

        u = idx / 10;
        d = jdx - (jdx / 10) * 10;

        if(u > 0 && d > 0)
        {
            int div0 = Hcf(idx, jdx);
            int div1 = Hcf(u, d);

            if( (idx - (idx / 10) * 10 == jdx / 10) &&
               (idx < jdx) &&
               (div0 % 11 != 0) &&
               (idx / div0) == (u / div1) &&
               (jdx / div0) == (d / div1) )
            {
                finalUp *= u;
                finalDown *= d;
                cout << idx << "/" << jdx << " = " << u << "/" << d << endl;
            }
        }
    }

    cout << endl << finalUp << " / " << finalDown << endl;
    cout << finalUp / Hcf(finalUp, finalDown) << " / " << finalDown / Hcf(finalUp, finalDown) << endl;

    return 0;
}
