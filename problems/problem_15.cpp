#include "problem_15.hpp"

#include <iostream>

using namespace std;

int pgcd(int a, int b)
{
    if(a == b)
        return a;
    else if(a > b)
    {
        if(a % b == 0)
            return b;
        else
            return pgcd(a-b, b);
    }
    else
    {
        if(b % a == 0)
            return a;
        else
            return pgcd(b-a, a);
    }
}

int problem_15()
{
    int up[20], down[19];

    for(int idx = 21 ; idx <= 40 ; ++idx)
        up[idx - 21] = idx;
    for(int idx = 2 ; idx <= 20 ; ++idx)
        down[idx - 2] = idx;

    for(size_t idx = 0 ; idx < sizeof(up) / sizeof(int) ; ++idx)
    {
        for(size_t jdx = 0 ; jdx < sizeof(down) / sizeof(int) ; ++jdx)
        {
            int p = pgcd(up[idx], down[jdx]);
            up[idx] /= p;
            down[jdx] /= p;
        }
    }

    long u = 1;
    long d = 1;

    for(size_t idx = 0 ; idx < sizeof(up) / sizeof(int) ; ++idx)
        u *= up[idx];

    for(size_t jdx = 0 ; jdx < sizeof(down) / sizeof(int) ; ++jdx)
        d *= down[jdx];

    cout << u / d << endl;

    return 0;
}
