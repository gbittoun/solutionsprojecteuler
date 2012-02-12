#include "../Computing/IntegerOperations.hpp"

#include <queue>

using namespace std;
using namespace Computing;

int problem_73()
{
    long long sum = 0;

    for(long long d = 1 ; d <= 12000LL ; ++d)
    {
        for(long long n = d / 3 ; n < d ; ++n)
        {
            if(3*n > d && 2*n < d && Hcf(n, d) == 1)
            {
                //cout << n << "/" << d << " = " << n / (float) d << endl;
                ++sum;
            }
        }
    }

    cout << endl << sum << endl;

    return 0;
}

