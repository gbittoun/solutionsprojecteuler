#include <string.h>
#include <iostream>

using namespace std;


int main()
{
    int x[1024];
    memset(x, 0, sizeof(x));

    x[0] = 1;

    for(int idx = 0 ; idx < 1000 ; ++idx)
    {
        for(size_t jdx = 0 ; jdx < sizeof(x) / sizeof(int) ; ++jdx)
            x[jdx] *= 2;

        for(size_t jdx = 0 ; jdx < sizeof(x) / sizeof(int) ; ++jdx)
        {
            if(x[jdx] >= 10)
            {
                x[jdx+1] += x[jdx] / 10;
                x[jdx] -= (x[jdx] / 10) * 10;
            }
        }
    }

    long long sum = 0;

    for(size_t jdx = 0 ; jdx < sizeof(x) / sizeof(int) ; ++jdx)
    {
        sum += x[jdx];
    }
    cout << sum << endl;

    return 0;
}
